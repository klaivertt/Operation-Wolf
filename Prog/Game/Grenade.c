#include "Grenade.h"

Grenade grenade;

void LoadGrenade()
{
	sfIntRect rect = { 120, 2184, 24 , 48 };
	sfVector2f position = { SCREEN_WIDTH / 3 * 2 , SCREEN_HEIGHT / 2 };
	sfVector2f originalPosition = position;
	sfVector2f origin = { 0.5 , 1 };
	grenade.texture = sfTexture_createFromFile("Assets/Sprites/SpriteSheet.png", NULL);

	for (int i = 0; i < BULLET_NUMBER_MAX; i++)
	{
		if (i == 5 || i == 10 || i == 15)
		{
			position.x = originalPosition.x;
			position.y += rect.height;
		}

		CreateSprite(&grenade.sprite[i], grenade.texture, position, rect, origin);
		position.x += rect.width * 1.5f;
	}
}

void DrawGrenade(sfRenderWindow* _renderWindow)
{
	for (int i = 0; i < GetBullet(); i++)
	{
		sfRenderWindow_drawSprite(_renderWindow, grenade.sprite[i], NULL);
	}
}

void CleanupGrenade()
{
	for (int i = 0; i < GRENADE_NUMBER_MAX; i++)
	{
		sfSprite_destroy(grenade.sprite[i]);
		grenade.sprite[i] = NULL;
	}

	sfTexture_destroy(grenade.texture);
	grenade.texture = NULL;
}