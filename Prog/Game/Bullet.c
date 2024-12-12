#include "HUD.h"

Bullet bullet;

void LoadBullet()
{
	sfIntRect rect = { 120, 2184, 24 , 48 };
	sfVector2f position = { SCREEN_WIDTH / 3 * 2 , SCREEN_HEIGHT / 2 };
	sfVector2f originalPosition = position;
	sfVector2f origin = { 0.5 , 1 };
	bullet.texture = sfTexture_createFromFile("Assets/Sprites/SpriteSheet.png", NULL);

	for (int i = 0; i < BULLET_NUMBER_MAX; i++)
	{
		if (i == 5 || i == 10 || i==15)
		{
			position.x = originalPosition.x;
			position.y += rect.height;
		}

		CreateSprite(&bullet.sprite[i], bullet.texture, position, rect, origin);
		position.x += rect.width * 1.5f;
	}
}

void DrawBullet(sfRenderWindow* _renderWindow)
{
	for (int i = 0; i < GetBullet(); i++)
	{
		sfRenderWindow_drawSprite(_renderWindow, bullet.sprite[i], NULL);
	}
}

void CleanupBullet()
{
	for (int i = 0; i < BULLET_NUMBER_MAX; i++)
	{
		sfSprite_destroy(bullet.sprite[i]);
		bullet.sprite[i] = NULL;
	}

	sfTexture_destroy(bullet.texture);
	bullet.texture = NULL;
}