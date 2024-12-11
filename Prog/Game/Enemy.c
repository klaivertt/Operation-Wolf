#include "Enemy.h"

EnemyData enemyData;

void ScreenCollisionX(Enemy* _enemy);


void LoadEnemy(void)
{

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

void ScreenCollisionX(Enemy* _enemy)
{
	sfFloatRect GB = sfSprite_getGlobalBounds(_enemy->sprite);

	if (GB.left + GB.width > SCREEN_WIDTH)
	{
		_enemy->speedMultiplicator = BASE_SPEED * _enemy->speedMultiplicator;
	}
	if (GB.left < 0)
	{
		_enemy->speedMultiplicator = -BASE_SPEED * _enemy->speedMultiplicator;
	}
}