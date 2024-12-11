#include "HUD.h"

Image bullet;

void LoadBullet()
{
	sfIntRect rect = { 120, 2184, 24 , 48 };
	sfVector2f position = { SCREEN_WIDTH / 2 , SCREEN_HEIGHT / 2 };
	sfVector2f origin = { 0.5 , 1 };
	bullet.texture = sfTexture_createFromFile("Assets/Sprites/SpriteSheet.png", NULL);

	CreateSprite(&bullet.sprite, bullet.texture, position, rect, origin);
}

void UpdateBullet()
{

}

void DrawBullet(sfRenderWindow* _renderWindow)
{
	sfRenderWindow_drawSprite(_renderWindow, bullet.sprite, NULL);
}

void CleanupBullet()
{
	sfSprite_destroy(bullet.sprite);
	bullet.sprite = NULL;

	sfTexture_destroy(bullet.texture);
	bullet.texture = NULL;
}