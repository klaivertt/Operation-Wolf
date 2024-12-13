#include "Grenade.h"

Grenade grenade;

void LoadGrenade()
{
	sfIntRect rect = { 24, 2184, 24 , 48 };
	sfVector2f position = { rect.width , rect.height * 1.2f };
	sfVector2f origin = { 0.5 , 1 };
	grenade.texture = sfTexture_createFromFile("Assets/Sprites/SpriteSheet.png", NULL);

	for (int i = 0; i < GRENADE_NUMBER_MAX; i++)
	{
		CreateSprite(&grenade.sprite[i], grenade.texture, position, rect, origin);
		position.x += rect.width * 1.5f;
	}
}

void DrawGrenade(sfRenderWindow* _renderWindow)
{
	for (int i = 0; i < GRENADE_NUMBER_MAX; i++)
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