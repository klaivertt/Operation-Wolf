#include "HumanIcon.h"

Icone icone;

void LoadIcon()
{
	sfIntRect rectHostage = { 168, 2184, 24 , 48 };
	sfIntRect rectEnemy = { 216, 2184, 48 , 48 };

	sfVector2f positionHostage = { SCREEN_WIDTH / 2 + (float) rectHostage.width, (float)rectHostage.height };
	sfVector2f positionEnemy = { SCREEN_WIDTH / 2 - (float)rectEnemy.width, (float)rectEnemy.height };

	sfVector2f origin = { 0.5 , 1 };

	icone.Enemy.texture = sfTexture_createFromFile("Assets/Sprites/SpriteSheet.png", NULL);
	icone.Hostage.texture = sfTexture_createFromFile("Assets/Sprites/SpriteSheet.png", NULL);

	CreateSprite(&icone.Hostage.sprite, icone.Hostage.texture, positionHostage, rectHostage, origin);
	CreateSprite(&icone.Enemy.sprite, icone.Enemy.texture, positionEnemy, rectEnemy, origin);

	icone.enemyLeft = InitText("0", 30, (sfVector2f) { positionEnemy.x - rectEnemy.width, 0 });
	icone.hostageLeft = InitText("0", 30, (sfVector2f) { positionHostage.x + rectHostage.width, 0 });
}

void UpdateIconeText()
{
	UpdateText(&icone.enemyLeft, "%d", 5);
	UpdateText(&icone.hostageLeft, "%d", 5);
}

void DrawIcon(sfRenderWindow* _renderWindow)
{
	sfRenderWindow_drawSprite(_renderWindow, icone.Enemy.sprite, sfFalse);
	sfRenderWindow_drawSprite(_renderWindow, icone.Hostage.sprite, sfFalse);
	sfRenderWindow_drawText(_renderWindow, icone.enemyLeft, sfFalse);
	sfRenderWindow_drawText(_renderWindow, icone.hostageLeft, sfFalse);
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