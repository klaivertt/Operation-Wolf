#include "Magazine.h"

Magazine magazine;

void LoadMagazine()
{
	sfIntRect rect = { 0, 0, 30 , 54 };
	sfVector2f position = { SCREEN_WIDTH / 4 * 3 + (float)rect.width * 3, (float)rect.height };
	sfVector2f origin = { 0.5 , 1 };
	magazine.texture = sfTexture_createFromFile("Assets/Sprites/HUD/AmmoAndcharger.png", NULL);

	for (int i = 0; i < MAGAZINE_NUMBER_MAX; i++)
	{
		CreateSprite(&magazine.sprite[i], magazine.texture, position, rect, origin);
		position.x += (float)rect.width;
	}
}

void DrawMagazine(sfRenderWindow* _renderWindow)
{
	for (int i = 0; i < GetMagazine(); i++)
	{
		sfRenderWindow_drawSprite(_renderWindow, magazine.sprite[i], NULL);
	}
}

void CleanupMagazine()
{
	for (int i = 0; i < MAGAZINE_NUMBER_MAX; i++)
	{
		sfSprite_destroy(magazine.sprite[i]);
		magazine.sprite[i] = NULL;
	}

	sfTexture_destroy(magazine.texture);
	magazine.texture = NULL;
}