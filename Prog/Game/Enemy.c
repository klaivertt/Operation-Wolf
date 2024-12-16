#include "Enemy.h"

EnemyData enemyData;

int i = 0;

sfVector2f RandomSpawn(void);
int RandomExitPos(void);
int RandomMapPos(void);

//Return True if is on targeted Position
sfBool Move(Enemy* _enemy, sfSprite** _sprite);


void IncreaseVariablesNbEnemyPos(sfSprite* _sprite);

void DecreaseVariablesNbEnemyPos(sfSprite* _sprite);



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

void BackGroundMovement(sfSprite* _enemySprite, float _dt);




int PlayerDamage(void)
{
	int totalDamage = 0;
	for (short i = 0; i < ENEMY_MAX; i++)
	{
		if (enemyData.enemy[i].doDamageToPlayer)
		{
			enemyData.enemy[i].doDamageToPlayer = sfFalse;
			totalDamage += enemyData.enemy[i].damage;
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
		enemyData.enemy[i].life = 1;
		enemyData.enemy[i].damage = 1;
		enemyData.enemy[i].maxSpeed = 8;

		enemyData.enemy[i].targetedPositon = RandomMapPos();

		float speedMultiplicator = (1 + rand() % 6) / 10.0f;
		enemyData.enemy[i].maxSpeed *= 1 - speedMultiplicator;
		
		enemyData.enemy[i].haveAlreadyShoot = sfFalse;
		enemyData.enemy[i].doDamageToPlayer = sfFalse;

		float ShootDelay = SHOOT_DELAY;
		InitTimer(&enemyData.enemy[i].shootTimer, ShootDelay);

		float spawnDelay = rand() % MAX_SPAWN_DELAY + (float)(rand() % 10) / 10;
		InitTimer(&enemyData.enemy[i].waitTimer, spawnDelay);

		if (enemyData.spriteSheet == NULL)
		{
			enemyData.spriteSheet = sfTexture_createFromFile("Assets/Sprites/Spritesheet.png", NULL);
		}

		sfVector2f pos = RandomSpawn();
		sfIntRect rect = { 23,23,50,98 };
		sfVector2f origin = { 0.5,1 };
		CreateSprite(&enemyData.enemySprite[i], enemyData.spriteSheet, pos, rect, origin);

		IncreaseVariablesNbEnemyPos(enemyData.enemySprite[i]);
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
			DecreaseVariablesNbEnemyPos(enemyData.enemySprite[i]);
			LoadEnemies(i + 1);
			break;
		}

		BackGroundMovement(enemyData.enemySprite[i], _dt);
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


sfVector2f RandomSpawn(void)
{
	int pos[2] = { 1 + rand() % 2, 1 + rand() % 3 };
	sfVector2f finalPos = { 0 };

	for (short i = 0; i < 2; i++)
	{

		switch (pos[i])
		{
		case 1:

			if (i == 0)
			{
				finalPos.x = POS_LEFT_X;
				break;
			}
			if (i == 1 && enemyData.nbEnemyPosHIGHT < ENEMY_MAX_PER_POS_Y)
			{
				finalPos.y = POS_HIGHT_Y;
				break;
			}
			
		case 2:

			if (i == 0)
			{
				finalPos.x = POS_RIGHT_X;
				break;
			}
			if (i == 1 && enemyData.nbEnemyPosMIDDLE < ENEMY_MAX_PER_POS_Y)
			{
				finalPos.y = POS_MIDDLE_Y;
				break;
			}
		case 3:
			if (enemyData.nbEnemyPosDOWN < ENEMY_MAX_PER_POS_Y)
			{
				finalPos.y = POS_DOWN_Y;
				break;
			}
		default :
			if (enemyData.nbEnemyPosHIGHT < ENEMY_MAX_PER_POS_Y)
			{
				finalPos.y = POS_HIGHT_Y;
			}
			else if (enemyData.nbEnemyPosMIDDLE < ENEMY_MAX_PER_POS_Y)
			{
				finalPos.y = POS_MIDDLE_Y;
			}
			else if ((enemyData.nbEnemyPosDOWN < ENEMY_MAX_PER_POS_Y))
			{
				finalPos.y = POS_DOWN_Y;
			}
			break;
		}

	}

	return finalPos;

}

int RandomExitPos(void)
{
	int pos = rand() % 2;

	switch (pos)
	{
	case 0:
		return POS_RIGHT_X;

	case 1:
		return POS_LEFT_X;
	}

	return 0;
}

int RandomMapPos(void)
{
	return SCREEN_WIDTH * 0.05 + rand() % SCREEN_WIDTH * 0.90;
}


sfBool Move(Enemy* _enemy, sfSprite** _sprite)
{
	sfVector2f pos = sfSprite_getPosition(*_sprite);

	pos.x = _enemy->targetedPositon;

	return MoveSpriteToTarget(_sprite, pos, _enemy->maxSpeed, sfFalse);
}

void BackGroundMovement(sfSprite* _enemySprite,float _dt)
{
	sfVector2f pos = sfSprite_getPosition(_enemySprite);
	pos.x -= BACKGROUND_SPEED*_dt;
	sfSprite_setPosition(_enemySprite, pos);
	//Verifer position
}



void IncreaseVariablesNbEnemyPos(sfSprite* _sprite)
{
	sfVector2f pos = sfSprite_getPosition(_sprite);
	int posY = pos.y;
	switch (posY)
	{
	case POS_HIGHT_Y:
		enemyData.nbEnemyPosHIGHT += 1;
		break;
	case POS_MIDDLE_Y:
		enemyData.nbEnemyPosMIDDLE += 1;
		break;
	case POS_DOWN_Y:
		enemyData.nbEnemyPosDOWN += 1;
		break;
	default:
		printf("\nIncreaseVariablesNbEnemyPos error : problem with enemy position Y : %d",posY);
		break;
	}
}

void DecreaseVariablesNbEnemyPos(sfSprite* _sprite)
{
	sfVector2f pos = sfSprite_getPosition(_sprite);
	int posY = pos.y;
	switch (posY)
	{
	case POS_HIGHT_Y:
		enemyData.nbEnemyPosHIGHT -= 1;
		break;
	case POS_MIDDLE_Y:
		enemyData.nbEnemyPosMIDDLE -= 1;
		break;
	case POS_DOWN_Y:
		enemyData.nbEnemyPosDOWN -= 1;
		break;
	default:
		printf("\nDecreaseVariablesNbEnemyPos error : problem with enemy position Y : %d", posY);
		break;
	}

}


////Verifer position
//sfVector2f ok = sfSprite_getPosition(enemyData.enemy[temporaire].sprite);
//printf("\npos origin : %f %f\Bn", ok.x, ok.y);