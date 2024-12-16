#include "HumanIcon.h"

Icone icone;

void LoadIcon()
{
	sfIntRect rectHostage = { 168, 2184, 24 , 48 };
	sfIntRect rectEnemy = { 216, 2184, 48 , 48 };

	sfVector2f positionHostage = { SCREEN_WIDTH / 2 + rectHostage.width, rectHostage.height };
	sfVector2f positionEnemy = { SCREEN_WIDTH / 2 - rectEnemy.width, rectEnemy.height };
	
	sfVector2f origin = { 0.5 , 1 };

	icone.Enemy.texture = sfTexture_createFromFile("Assets/Sprites/SpriteSheet.png", NULL);
	icone.Hostage.texture = sfTexture_createFromFile("Assets/Sprites/SpriteSheet.png", NULL);

	CreateSprite(&icone.Hostage.sprite, icone.Hostage.texture, positionHostage, rectHostage, origin);
	CreateSprite(&icone.Enemy.sprite, icone.Enemy.texture, positionEnemy, rectEnemy, origin);
}

void DrawIcon(sfRenderWindow* _renderWindow)
{
	sfRenderWindow_drawSprite(_renderWindow, icone.Enemy.sprite, sfFalse);
	sfRenderWindow_drawSprite(_renderWindow, icone.Hostage.sprite, sfFalse);
}

void CleanupIcon()
{
	sfSprite_destroy(icone.Enemy.sprite);
	icone.Enemy.sprite = NULL;

	sfTexture_destroy(icone.Enemy.texture);
	icone.Enemy.texture = NULL;

	sfSprite_destroy(icone.Hostage.sprite);
	icone.Hostage.sprite = NULL;

	sfTexture_destroy(icone.Hostage.texture);
	icone.Hostage.texture = NULL;
}