#include "Magazine.h"

Magazine magazine;

void LoadMagazine()
{
	magazine.magazineNumber = 3;
	sfIntRect rect = { 72, 2184, 24 , 48 };
	sfVector2f position = { SCREEN_WIDTH / 2 + rect.width , rect.height * 1.2f};
	sfVector2f origin = { 0.5 , 1 };
	magazine.texture = sfTexture_createFromFile("Assets/Sprites/SpriteSheet.png", NULL);

	for (int i = 0; i < magazine.magazineNumber; i++)
	{
		CreateSprite(&magazine.sprite[i], magazine.texture, position, rect, origin);
		position.x += rect.width * 1.5;
	}
}

void UpdateMagazine()
{

}

void ReloadMagazine()
{
	if (magazine.magazineNumber > 0)
	{
		magazine.magazineNumber--;
		ReloadBullet();
	}
	else
	{
		printf("plus de chargeurs");
	}
}

void DropMagazine()
{
	
}

void DrawMagazine(sfRenderWindow* _renderWindow)
{
	for (int i = 0; i < magazine.magazineNumber; i++)
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