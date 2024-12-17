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
void BackGroundMovement(sfSprite* _enemySprite, float _dt);


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
	
	
	sfBool notMoving, timerEnd;

	for (short i = 0; i < ENEMY_MAX; i++)
	{

		

		switch (enemyData.enemy[i].state)
		{
		case WAIT_TO_SPAWN:

			UpdateTimer(_dt, &enemyData.enemy[i].waitTimer);
			timerEnd = IsTimerFinished(&enemyData.enemy[i].waitTimer);
			if (timerEnd)
			{
				SetEnemyState(&enemyData.enemy[i], WALK);
			}
			break;
		case WALK:

			UpdateAnimation(&enemyData.enemy[i].anim.walk, &enemyData.enemy[i].sprite, _dt);
			notMoving = Move(&enemyData.enemy[i], &enemyData.enemy[i].sprite);
			if (notMoving)
			{
				if (enemyData.enemy[i].haveAlreadyShoot)
				{
					SetEnemyState(&enemyData.enemy[i], DEAD);
				}
				else
				{
					SetEnemyState(&enemyData.enemy[i], SHOOT);
				}
			}

			break;
		case SHOOT:
			UpdateAnimation(&enemyData.enemy[i].anim.shoot, &enemyData.enemy[i].sprite, _dt);
			UpdateTimer(_dt, &enemyData.enemy[i].shootTimer);
			timerEnd = IsTimerFinished(&enemyData.enemy[i].shootTimer);
			if (timerEnd)
			{
				enemyData.enemy[i].doDamageToPlayer = sfTrue;
				SetEnemyState(&enemyData.enemy[i], WALK);
				enemyData.enemy[i].targetedPositon = RandomExitPos();
				enemyData.enemy[i].haveAlreadyShoot = sfTrue;
			}
			
			break;

		case DEAD:
			UpdateAnimation(&enemyData.enemy[i].anim.dead, &enemyData.enemy[i].sprite, _dt);
			UpdateTimer(_dt, &enemyData.enemy[i].deadTimer);
			sfBool endDeadAnimation = IsTimerFinished(&enemyData.enemy[i].deadTimer);
			if (endDeadAnimation)
			{
				DecreaseNbEnemyPositionGround(enemyData.enemy[i].sprite);
				LoadEnemies(i + 1);
			}
			break;
		}

		if (enemyData.enemy[i].state != WAIT_TO_SPAWN)
		{
		BackGroundMovement(enemyData.enemy[i].sprite, _dt);
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

sfBool Move(Enemy* _enemy, sfSprite** _sprite)
{
	sfVector2f pos = sfSprite_getPosition(*_sprite);

	pos.x = _enemy->targetedPositon;

	return MoveSpriteToTarget(_sprite, pos, _enemy->speed, sfFalse);
}

void BackGroundMovement(sfSprite* _enemySprite,float _dt)
{
	sfVector2f pos = sfSprite_getPosition(_enemySprite);
	pos.x -= BACKGROUND_SPEED*_dt;
	sfSprite_setPosition(_enemySprite, pos);
	
	//Verifer position
}





////Verifer position
//sfVector2f ok = sfSprite_getPosition(enemyData.enemy[temporaire].sprite);
//printf("\npos origin : %f %f\Bn", ok.x, ok.y);