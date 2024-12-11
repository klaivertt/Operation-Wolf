#include "Enemy.h"

EnemyData enemyData;

void LoadEnemy(void)
{
	//enemyData.animSoldier[0] = (sfIntRect){};
	//enemyData.animSoldier[1] = (sfIntRect){};
	//enemyData.animSoldier[2] = (sfIntRect){};
	//enemyData.animSoldier[3] = (sfIntRect){};
	//enemyData.animSoldier[4] = (sfIntRect){};
	//enemyData.animSoldier[5] = (sfIntRect){};
	//enemyData.animSoldier[6] = (sfIntRect){};
	//enemyData.animSoldier[7] = (sfIntRect){};
	//enemyData.animSoldier[8] = (sfIntRect){};

	enemyData.nbSoldierSprite = sizeof(enemyData.animSoldier) / sizeof(enemyData.animSoldier[0]);

	for (short i = 0; i < enemyData.nbSoldierSprite; i++)
	{
		switch (enemyData.enemy[i].type)
		{
		case SOLDIER:
			enemyData.enemy->life = 1;
			enemyData.enemy->damage = 1;
			enemyData.enemy->attackPosition;

			break;
		}
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

}

void DrawEnemy(sfRenderWindow* _renderWindow)
{

}

void CleanupEnemy(void)
{

}