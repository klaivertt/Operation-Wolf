#include "Magazine.h"

Magazine magazine;

void LoadMagazine()
{
	sfIntRect rect = { 72, 2184, 24 , 48 };
	sfVector2f position = { SCREEN_WIDTH / 2 + rect.width , rect.height * 1.2f};
	sfVector2f origin = { 0.5 , 1 };
	magazine.texture = sfTexture_createFromFile("Assets/Sprites/SpriteSheet.png", NULL);

	for (int i = 0; i < MAGAZINE_NUMBER_MAX; i++)
	{
		CreateSprite(&magazine.sprite[i], magazine.texture, position, rect, origin);
		position.x += rect.width * 1.5;
	}
}

void UpdateMagazine()
{

}

void DrawMagazine(sfRenderWindow* _renderWindow)
{
	for (int i = 0; i < MAGAZINE_NUMBER_MAX; i++)
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