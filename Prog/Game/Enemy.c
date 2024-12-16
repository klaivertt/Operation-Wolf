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
}

sfBool VerifPlayerKillEnemy(sfVector2f _mousePos)
{
	for (short i = 0; i < ENEMY_MAX; i++)
	{
		sfBool click = MouseClickOnSpritePixel(_mousePos, enemyData.enemySprite[i]);
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
		enemyData.enemy[i].state = WAIT;
		enemyData.enemy[i].life = TOTAL_LIFE;

		enemyData.enemy[i].targetedPositon = RandomMapPos();

		float speedMultiplicator = (1 + rand() % 6) / 10.0f;
		enemyData.enemy[i].speed = MAX_SPEED * (1 - speedMultiplicator);
		
		enemyData.enemy[i].haveAlreadyShoot = sfFalse;
		enemyData.enemy[i].doDamageToPlayer = sfFalse;

		float ShootDelay = SHOOT_DELAY;
		InitTimer(&enemyData.enemy[i].shootTimer, ShootDelay);

		float spawnDelay = rand() % MAX_SPAWN_DELAY + (float)(rand() % 10) / 10;
		InitTimer(&enemyData.enemy[i].waitTimer, spawnDelay);

		if (enemyData.spriteSheet == NULL)
		{
			enemyData.spriteSheet = sfTexture_createFromFile("Assets/Sprites/Sprite-MovingSoldier.png", NULL);
		}

		sfVector2f pos = RandomSpawn();
		sfIntRect rect = { 0,0,753/5,208 };
		sfVector2f origin = { 0.5,1 };
		if (enemyData.enemySprite[i] == NULL)
		{
			CreateSprite(&enemyData.enemySprite[i], enemyData.spriteSheet, pos, rect, origin);
		}
		else
		{
			sfSprite_setTextureRect(enemyData.enemySprite[i], rect);
			sfSprite_setOrigin(enemyData.enemySprite[i], (sfVector2f) { (float)rect.width* origin.x, (float)rect.height* origin.y });
			sfSprite_setPosition(enemyData.enemySprite[i], pos);
		}
		
		IncreaseNbEnemyPositionGround(enemyData.enemySprite[i]);
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
		case WAIT:

			UpdateTimer(_dt, &enemyData.enemy[i].waitTimer);
			timerEnd = IsTimerFinished(&enemyData.enemy[i].waitTimer);
			if (timerEnd)
			{
				SetEnemyState(&enemyData.enemy[i], WALK);
			}
			break;
		case WALK:

			notMoving = Move(&enemyData.enemy[i], &enemyData.enemySprite[i]);
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

			UpdateTimer(_dt, &enemyData.enemy[i].shootTimer);
			timerEnd = IsTimerFinished(&enemyData.enemy[i].shootTimer);
			if (timerEnd) {
				enemyData.enemy[i].doDamageToPlayer = sfTrue;
				SetEnemyState(&enemyData.enemy[i], WALK);
				enemyData.enemy[i].targetedPositon = RandomExitPos();
				enemyData.enemy[i].haveAlreadyShoot = sfTrue;
			}
			break;

		case DEAD:
			DecreaseNbEnemyPositionGround(enemyData.enemySprite[i]);
			LoadEnemies(i + 1);

			break;
		}

		if (enemyData.enemy[i].state != WAIT)
		{
		BackGroundMovement(enemyData.enemySprite[i], _dt);
		}
		
	}
}

void DrawEnemy(sfRenderWindow* _renderWindow)
{
	for (short i = 0; i < ENEMY_MAX; i++)
	{
		sfRenderWindow_drawSprite(_renderWindow, enemyData.enemySprite[i], NULL);
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