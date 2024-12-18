#include "Magazine.h"

Magazine magazine;

void LoadMagazine()
{
	sfIntRect rect = { 72, 2184, 24 , 48 };
	sfVector2f position = { SCREEN_WIDTH / 4 * 3 + rect.width * 3, rect.height };
	sfVector2f origin = { 0.5 , 1 };
	magazine.texture = sfTexture_createFromFile("Assets/Sprites/SpriteSheet.png", NULL);

	for (int i = 0; i < GetMagazine(); i++)
	{
		CreateSprite(&magazine.sprite[i], magazine.texture, position, rect, origin);
		position.x += rect.width;
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