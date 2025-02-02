#include "Enemy.h"

EnemyData enemyData;


void LoadEnemy(short _enemyToLoad, EnemyType _enemyType )
{
	switch (_enemyType)
	{
	case MOVING_ENEMY:
		for (short i = 0; i < MOVING_ENEMY_MAX; i++)
		{
			LoadMovingEnemy(&enemyData.movingEnemy[i], &enemyData.movingEnemySpriteSheet);
		}
		break;
	case FRONT_ENEMY:
		for (short i = 0; i < FRONT_ENEMY_MAX; i++)
		{
			LoadFrontEnemy(&enemyData.frontEnemy[i], &enemyData.frontEnemySpriteSheet);
		}
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
		for (short i = 0; i < MOVING_ENEMY_MAX; i++)
		{
			UpdateMovingEnemy(&enemyData.movingEnemy[i], &enemyData.movingEnemySpriteSheet, _dt);
		}
		break;
	case FRONT_ENEMY:
		for (short i = 0; i < FRONT_ENEMY_MAX; i++)
		{
			UpdateFrontEnemy(&enemyData.frontEnemy[i], &enemyData.frontEnemySpriteSheet, _dt);
		}
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
		for (short i = 0; i < MOVING_ENEMY_MAX; i++)
		{
			DrawMovingEnemy(&enemyData.movingEnemy[i], _renderWindow, _ground);
		}
		break;
	case FRONT_ENEMY:
		for (short i = 0; i < FRONT_ENEMY_MAX; i++)
		{
			DrawFrontEnemy(&enemyData.frontEnemy[i], _renderWindow);
		}
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
		for (short i = 0; i < MOVING_ENEMY_MAX; i++)
		{
			CleanupMovingEnemy(&enemyData.movingEnemy[i],&enemyData.movingEnemySpriteSheet);
		}
		break;
	case FRONT_ENEMY:
		for (short i = 0; i < FRONT_ENEMY_MAX; i++)
		{
			CleanupFrontEnemy(&enemyData.frontEnemy[i], &enemyData.frontEnemySpriteSheet);
		}
		break;
	default:
		break;
	}

	if (enemyData.movingEnemySpriteSheet != NULL)
	{
		sfTexture_destroy(enemyData.movingEnemySpriteSheet);
		enemyData.movingEnemySpriteSheet = NULL;
	}

	if (enemyData.frontEnemySpriteSheet != NULL)
	{
		sfTexture_destroy(enemyData.frontEnemySpriteSheet);
		enemyData.frontEnemySpriteSheet = NULL;
	}

}




MovingEnemy* GetAllMovingEnemy(void)
{
	return enemyData.movingEnemy;
}

FrontEnemy* GetAllFrontEnemy(void)
{
	return enemyData.frontEnemy;
}

sfBool VerifPlayerKillEnemy(sfVector2f _mousePos, short _i, EnemyType _enemyType)
{
	
	switch (_enemyType)
	{
	case MOVING_ENEMY:
		if (VerifPlayerKill_MovingEnemy(&enemyData.movingEnemy[_i], _mousePos))
		{
			return sfTrue;
		}
		break;
	case FRONT_ENEMY:
		if (VerifPlayerKill_FrontEnemy(&enemyData.frontEnemy[_i], _mousePos))
		{
			return sfTrue;
		}
		break;

	}
	return sfFalse;
}

int PlayerDamage(void)
{
	int totalDamage = 0;
	for (short i = 0; i < FRONT_ENEMY_MAX; i++)
	{
		totalDamage += DamageToPlayer_FrontEnemy(&enemyData.frontEnemy[i]);
	}

	for (short i = 0; i < MOVING_ENEMY_MAX; i++)
	{
		totalDamage += DamageToPlayer_MovingEnemy(&enemyData.movingEnemy[i]);
	}

	//FrontEnemy
	
	return totalDamage;
}


