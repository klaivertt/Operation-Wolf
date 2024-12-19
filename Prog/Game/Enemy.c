#include "Enemy.h"

EnemyData enemyData;


void LoadEnemy(short _enemyToLoad, EnemyType _enemyType )
{
	switch (_enemyType)
	{
	case MOVING_ENEMY:
		for (short i = 0; i < ENEMY_MAX; i++)
		{
			LoadMovingEnemy(&enemyData.MovingEnemy[i], &enemyData.movingEnemySpriteSheet);
		}
		break;
	case FRONT_ENEMY:
		//FrontEnemy
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
			UpdateMovingEnemy(&enemyData.MovingEnemy[i], &enemyData.movingEnemySpriteSheet, _dt);
		}
		break;
	case FRONT_ENEMY:
		//FrontEnemy
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
			DrawMovingEnemy(&enemyData.MovingEnemy[i], _renderWindow, _ground);
		}
		break;
	case FRONT_ENEMY:
		//FrontEnemy
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
			CleanupMovingEnemy(&enemyData.MovingEnemy[i]);
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




Enemy* GetAllMovingEnemy(void)
{
	return enemyData.MovingEnemy;
}

sfBool VerifPlayerKillEnemy(sfVector2f _mousePos)
{
	//FrontEnemy

	for (short i = 0; i < ENEMY_MAX; i++)
	{
		if (VerifPlayerKill_MovingEnemy(&enemyData.MovingEnemy[i], _mousePos))
		{
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
		totalDamage += DamageToPlayer_MovingEnemy(&enemyData.MovingEnemy[i]);
	}

	//FrontEnemy

	return totalDamage;
}


