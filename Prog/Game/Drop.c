#include "Drop.h"

DropData dropData;

void LoadDrop()
{
	sfIntRect rect = { 1079, 1949, 50 , 44 };
	sfVector2f position = { SCREEN_WIDTH / 2, SCREEN_HEIGHT/2 };
	sfVector2f origin = { 0.5 , 1 };
	dropData.heal.texture = sfTexture_createFromFile("Assets/Sprites/SpriteSheet.png", NULL);
	
	CreateSprite(&dropData.heal.sprite, dropData.heal.texture, position, rect, origin);
}

void DrawDrop(sfRenderWindow* _renderWindow)
{
	sfRenderWindow_drawSprite(_renderWindow, dropData.heal.sprite, NULL);
}

void MoveDrop()
{
	sfSprite_move(dropData.heal.sprite, GetBackGroundSpeed());
}

void CleanupDrop()
{

}

sfBool VerifyClickOnDrop()
{

}