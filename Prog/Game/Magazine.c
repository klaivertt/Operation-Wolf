#include "Magazine.h"

Image magazine;

void LoadMagazine()
{
	sfIntRect rect = { 72, 2184, 24 , 48 };
	sfVector2f position = { SCREEN_WIDTH / 2 + rect.width , SCREEN_HEIGHT / 2 + rect.height };
	sfVector2f origin = { 0.5 , 1 };
	magazine.texture = sfTexture_createFromFile("Assets/Sprites/SpriteSheet.png", NULL);

	CreateSprite(&magazine.sprite, magazine.texture, position, rect, origin);
}

void UpdateMagazine()
{

}

void DrawMagazine(sfRenderWindow* _renderWindow)
{
	sfRenderWindow_drawSprite(_renderWindow, magazine.sprite, NULL);
}

void CleanupMagazine()
{
	sfSprite_destroy(magazine.sprite);
	magazine.sprite = NULL;

	sfTexture_destroy(magazine.texture);
	magazine.texture = NULL;
}