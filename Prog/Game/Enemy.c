#include "Enemy.h"

EnemyData enemyData;



void ScreenCollisionX(Enemy* _enemy);


void LoadEnemy(void)
{
	if (enemyData.spriteSheet == NULL)
	{
		enemyData.spriteSheet = sfTexture_createFromFile("Assets/Sprites/Spritesheet.png", NULL);
	}

	if (enemyData.enemy[0].sprite == NULL)
	{
		sfVector2f pos = { (float)1 + rand() % 2, (float)1 + rand() % 3 };
		sfIntRect rect = { 21,21,54,102 };
		sfVector2f origin = { 0.5,1 };
		pos = (sfVector2f){ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
		CreateSprite(&enemyData.enemy[0].sprite, enemyData.spriteSheet, pos, rect, origin);
		
		enemyData.enemy[0].speedMultiplicator = 1;
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
	ScreenCollisionX(&enemyData.enemy[0]);
}

void DrawEnemy(sfRenderWindow* _renderWindow)
{
	sfRenderWindow_drawSprite(_renderWindow, enemyData.enemy[0].sprite, NULL);
}

void CleanupEnemy(void)
{

}




void ScreenCollisionX(Enemy* _enemy)
{
	sfFloatRect GB = sfSprite_getGlobalBounds(_enemy->sprite);

	if (GB.left + GB.width > SCREEN_WIDTH)
	{
		_enemy->speedMultiplicator = BASE_SPEED * _enemy->speedMultiplicator;
	}
	else if (GB.left < 0)
	{
		_enemy->speedMultiplicator = -BASE_SPEED * _enemy->speedMultiplicator;
	}
}

sfVector2f RandomEnemySpawn(void)
{
	int pos[2] = { 1 + rand() % 2, 1 + rand() % 3 };
	sfVector2f finalPos = { 0 };

	for (short i = 0; i < 2; i++)
	{

		switch (pos[i])
		{
		case 1:

			if (i == 0)  finalPos.x = POS_LEFT_X;
			if (i == 1)  finalPos.y = POS_HIGHT_Y;
			break;
		case 2:

			if (i == 0)  finalPos.x = POS_RIGHT_X;
			if (i == 1)  finalPos.y = POS_MIDDLE_Y;
			break;

		case 3:

			finalPos.y = POS_DOWN_Y;
			break;
		}
	}

	return finalPos;
}