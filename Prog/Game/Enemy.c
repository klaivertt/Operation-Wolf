#include "Enemy.h"

EnemyData enemyData;

int i = 0;

sfVector2f RandomSpawn(void);
int RandomExitPos(void);
int RandomMapPos(void);
//Return True if is on targeted Position
sfBool Move(Enemy* _enemy, sfSprite** _sprite);
void IncreaseNbEnemyPositionGround(sfSprite* _sprite);
void DecreaseNbEnemyPositionGround(sfSprite* _sprite);


void WaitToSpawn(Enemy* _enemy, float _dt);
void Walk(Enemy* _enemy, float _dt);
void Shoot(Enemy* _enemy, float _dt);
void Dead(Enemy* _enemy, float _dt, short i);

EnemyState GetEnemyState(Enemy* _enemy)
{
	return _enemy->state;
}

void SetEnemyState(Enemy* _enemy, EnemyState _state)
{
	_enemy->state = _state;

	switch (_state)
	{
	case WALK:
		ResetAnimation(&_enemy->anim.walk, &_enemy->sprite);
		break;
	case SHOOT:
		ResetAnimation(&_enemy->anim.shoot, &_enemy->sprite);
		break;
	case DEAD:
		ResetAnimation(&_enemy->anim.dead, &_enemy->sprite);
		break;
	default:
		break;
	}
}

sfBool VerifPlayerKillEnemy(sfVector2f _mousePos)
{
	for (short i = 0; i < ENEMY_MAX; i++)
	{
		sfBool click = MouseClickOnSpritePixel(_mousePos, enemyData.enemy[i].sprite);
		if (click)
		{
			SetEnemyState(&enemyData.enemy[i], DEAD);
			return sfTrue;
		}
	}
	return sfFalse;
}

int PlayerDamage(void)
{
	int totalDamage = 0;
	for (short i = 0; i < ENEMY_MAX; i++)
	{
		if (enemyData.enemy[i].doDamageToPlayer)
		{
			enemyData.enemy[i].doDamageToPlayer = sfFalse;
			totalDamage += DAMAGE;
		}
	}
	return totalDamage;
}



void LoadEnemies(short _enemyToLoad)
{
	short i, max;
	//Every enemies
	if (_enemyToLoad == NULL)
	{
		i = 0;
		max = ENEMY_MAX;
	}
	else
	{
		i = _enemyToLoad - 1;
		max = i + 1;
	}

	for (i; i < max;i++)
	{
		enemyData.enemy[i].state = WAIT_TO_SPAWN;
		enemyData.enemy[i].life = TOTAL_LIFE;

		enemyData.enemy[i].targetedPositon = RandomMapPos();

		float speedMultiplicator = (1 + rand() % 6) / 10.0f;
		enemyData.enemy[i].speed = MAX_SPEED * (1 - speedMultiplicator);
		
		enemyData.enemy[i].haveAlreadyShoot = sfFalse;
		enemyData.enemy[i].doDamageToPlayer = sfFalse;

		//TIMER
		float delay = SHOOT_DELAY * 1.5f;
		InitTimer(&enemyData.enemy[i].shootTimer, delay);

		delay = rand() % MAX_SPAWN_DELAY + (float)(rand() % 10) / 10;
		InitTimer(&enemyData.enemy[i].waitTimer, delay);
		
		delay = DEATH_DELAY;
		InitTimer(&enemyData.enemy[i].deadTimer, delay);



		if (enemyData.spriteSheet == NULL)
		{
			enemyData.spriteSheet = sfTexture_createFromFile("Assets/Sprites/Sprite-MovingSoldier.png", NULL);
		}

		sfVector2f pos = RandomSpawn();
		sfIntRect rect = { 0,0,753/5,208 };
		sfVector2f origin = { 0.5,1 };
		CreateSprite(&enemyData.enemy[i].sprite, enemyData.spriteSheet, pos, rect, origin);
		

		CreateAnimation(&enemyData.enemy[i].anim.walk, &enemyData.enemy[i].sprite, &enemyData.spriteSheet, 5, 2, 5, sfTrue, (sfVector2f) { 0, 0 });
		CreateAnimation(&enemyData.enemy[i].anim.shoot, &enemyData.enemy[i].sprite, &enemyData.spriteSheet, 5, 2, 2, sfTrue, (sfVector2f) { 2, 0 });
		CreateAnimation(&enemyData.enemy[i].anim.dead, &enemyData.enemy[i].sprite, &enemyData.spriteSheet, 5, 1, 1, sfTrue, (sfVector2f) { 4, 0 });

		IncreaseNbEnemyPositionGround(enemyData.enemy[i].sprite);

	}
	
}

void KeyPressedEnemy(sfRenderWindow* _renderWindow, sfKeyEvent _key)
{

}

void MouseButtonPressedEnemy(sfRenderWindow* const _renderWindow, sfMouseButtonEvent _mouseButton)
{

}

void MouseMovedEnemy(sfRenderWindow* const _renderWindow, sfMouseMoveEvent _mouseMove)
{

}

void UpdateEnemy(float _dt)
{

	for (short i = 0; i < ENEMY_MAX; i++)
	{

		switch (enemyData.enemy[i].state)
		{
		case WAIT_TO_SPAWN:

			WaitToSpawn(&enemyData.enemy[i], _dt);
			break;
		case WALK:

			Walk(&enemyData.enemy[i], _dt);
			break;
		case SHOOT:

			Shoot(&enemyData.enemy[i], _dt);
			break;

		case DEAD:

			/*UpdateAnimation(&enemyData.enemy[i].anim.dead, &enemyData.enemy[i].sprite, _dt);
			UpdateTimer(_dt, &enemyData.enemy[i].deadTimer);
			sfBool endDeadAnimation = IsTimerFinished(&enemyData.enemy[i].deadTimer);
			if (endDeadAnimation)
			{
				DecreaseNbEnemyPositionGround(enemyData.enemy[i].sprite);
				LoadEnemies(i + 1);
			}*/
			Dead(&enemyData.enemy[i],_dt,i);
			break;
		}

		if (enemyData.enemy[i].state != WAIT_TO_SPAWN)
		{
			sfSprite_move(enemyData.enemy[i].sprite, GetBackGroundSpeed());
		}
		
	}
}

void DrawEnemy(sfRenderWindow* _renderWindow)
{
	for (short i = 0; i < ENEMY_MAX; i++)
	{
		sfRenderWindow_drawSprite(_renderWindow, enemyData.enemy[i].sprite, NULL);
	}
}

void CleanupEnemy(void)
{

}



//Local Function

void WaitToSpawn(Enemy* _enemy, float _dt)
{
	sfBool timerEnd;
	UpdateTimer(_dt, &_enemy->waitTimer);
	timerEnd = IsTimerFinished(&_enemy->waitTimer);
	if (timerEnd)
	{
		SetEnemyState(_enemy, WALK);
	}
}

void Walk(Enemy* _enemy, float _dt)
{
	sfBool notMoving;

	UpdateAnimation(&_enemy->anim.walk, &_enemy->sprite, _dt);
	notMoving = Move(_enemy, &_enemy->sprite);
	if (notMoving)
	{
		if (_enemy->haveAlreadyShoot)
		{
			SetEnemyState(_enemy, DEAD);
		}
		else
		{
			SetEnemyState(_enemy, SHOOT);
		}
	}
}

void Shoot(Enemy* _enemy, float _dt)
{
	sfBool timerEnd;

	UpdateAnimation(&_enemy->anim.shoot, &_enemy->sprite, _dt);
	UpdateTimer(_dt, &_enemy->shootTimer);
	timerEnd = IsTimerFinished(&_enemy->shootTimer);
	int actualFrame = GetAnimCurrentFrame(&_enemy->anim.shoot);
	if (actualFrame == 2 && !_enemy->haveAlreadyShoot)
	{
		_enemy->doDamageToPlayer = sfTrue;
		_enemy->haveAlreadyShoot = sfTrue;
		Props* props[MAX_PROPS] = GetAllProps();

		sfFloatRect rectEnemy = sfSprite_getGlobalBounds(_enemy->sprite);
		rectEnemy = (sfFloatRect){ rectEnemy.left + 74, rectEnemy.top + 80, 5, 5 };

		

		for (short p = 0; p < MAX_PROPS; p++)
		{
			sfFloatRect rectProps = sfSprite_getGlobalBounds(props[p]->sprite);
			sfBool collision = CollisionRectRect(&rectProps, &rectEnemy);
			if (collision)
			{
				_enemy->doDamageToPlayer = sfFalse;
				_enemy->haveAlreadyShoot = sfFalse;
				printf("collision");
			}
		}
		
		

		
	}
	if (timerEnd)
	{
		SetEnemyState(_enemy, WALK);
		_enemy->targetedPositon = RandomExitPos();
	}
}

void Dead(Enemy* _enemy, float _dt, short i)
{
	UpdateAnimation(&_enemy->anim.dead, &_enemy->sprite, _dt);
	UpdateTimer(_dt, &_enemy->deadTimer);
	sfBool endDeadAnimation = IsTimerFinished(&_enemy->deadTimer);
	if (endDeadAnimation)
	{
		DecreaseNbEnemyPositionGround(_enemy->sprite);
		LoadEnemies(i + 1);
	}
}


sfBool Move(Enemy* _enemy, sfSprite** _sprite)
{
	sfVector2f pos = sfSprite_getPosition(*_sprite);

	pos.x = _enemy->targetedPositon;

	return MoveSpriteToTarget(_sprite, pos, _enemy->speed, sfFalse);
}

////Verifer position
//sfVector2f ok = sfSprite_getPosition(enemyData.enemy[temporaire].sprite);
//printf("\npos origin : %f %f\Bn", ok.x, ok.y);