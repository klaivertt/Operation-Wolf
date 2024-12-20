#include "Enemy.h"

EnemyData enemyData;


void LoadEnemy(short _enemyToLoad, EnemyType _enemyType )
{
	switch (_enemyType)
	{
	case MOVING_ENEMY:
		for (short i = 0; i < ENEMY_MAX; i++)
		{
			LoadMovingEnemy(&enemyData.movingEnemy[i], &enemyData.movingEnemySpriteSheet);
		}
		break;
	case FRONT_ENEMY:
		LoadFrontEnemy(&enemyData.frontEnemy, &enemyData.frontEnemySpriteSheet);
		break;
	default:
		break;
	}

}

void UpdateEnemy(float _dt, EnemyType _enemyType)
{
	switch (_enemyType)
	{
	case MOVING_ENEMY:
		for (short i = 0; i < ENEMY_MAX; i++)
		{
			UpdateMovingEnemy(&enemyData.movingEnemy[i], &enemyData.movingEnemySpriteSheet, _dt);
		}
		break;
	case FRONT_ENEMY:
		UpdateFrontEnemy(&enemyData.frontEnemy, &enemyData.frontEnemySpriteSheet,_dt);
		break;
	default:
		break;
	}

}

void DrawEnemy( sfRenderWindow* _renderWindow, EnemyType _enemyType, int _ground)
{
	switch (_enemyType)
	{
	case MOVING_ENEMY:
		for (short i = 0; i < ENEMY_MAX; i++)
		{
			DrawMovingEnemy(&enemyData.movingEnemy[i], _renderWindow, _ground);
		}
		break;
	case FRONT_ENEMY:
		DrawFrontEnemy(&enemyData.frontEnemy, _renderWindow);
		break;
	default:
		break;
	}
}

void CleanupEnemy(EnemyType _enemyType)
{
	switch (_enemyType)
	{
	case MOVING_ENEMY:
		for (short i = 0; i < ENEMY_MAX; i++)
		{
			CleanupMovingEnemy(&enemyData.movingEnemy[i]);
		}
		break;
	case FRONT_ENEMY:
		//FrontEnemy
		break;
	default:
		break;
	}

	if (enemyData.movingEnemySpriteSheet != NULL)
	{
		sfTexture_destroy(enemyData.movingEnemySpriteSheet);
		enemyData.movingEnemySpriteSheet = NULL;
	}

	//FrontEnemy
}




MovingEnemy* GetAllMovingEnemy(void)
{
	return enemyData.movingEnemy;
}

sfBool VerifPlayerKillEnemy(sfVector2f _mousePos, short _i)
{
	//FrontEnemy

	if (VerifPlayerKill_MovingEnemy(&enemyData.movingEnemy[_i], _mousePos))
	{
		return sfTrue;
	}

	return sfFalse;
}

int PlayerDamage(void)
{
	int totalDamage = 0;
	for (short i = 0; i < ENEMY_MAX; i++)
	{
		totalDamage += DamageToPlayer_MovingEnemy(&enemyData.movingEnemy[i]);
	}

	//FrontEnemy

	return totalDamage;
}


