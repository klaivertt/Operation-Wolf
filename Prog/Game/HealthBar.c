#include "HealthBar.h"

Image healthBarContainer;
Image healthBar;

void LoadHealthBar()
{
	sfVector2f positionHealthBarContainer = { SCREEN_WIDTH / 5 , 50};
	sfVector2f positionHealthBar = { SCREEN_WIDTH / 5 , 50};

	sfIntRect textureRect = { 0,0, 0,0 };

	sfVector2f origin = { 0.5 , 0.5 };

	healthBarContainer.texture = sfTexture_createFromFile("Assets/Sprites/TimeContainer.png", NULL);
	healthBar.texture = sfTexture_createFromFile("Assets/Sprites/TimeBar.png", NULL);

	CreateSprite(&healthBarContainer.sprite, healthBarContainer.texture, positionHealthBarContainer, (sfIntRect) { 0, 0, 0, 0 }, origin);
	CreateSprite(&healthBar.sprite, healthBar.texture, positionHealthBar, (sfIntRect){0,0,0,0}, origin);
}

void UpdateBar()
{
	int playerHP = GetPlayerHP();
	sfIntRect size = sfSprite_getTextureRect(healthBar.sprite);
	sfSprite_setTextureRect(healthBar.sprite, (sfIntRect) { size.left, size.top, 254 * playerHP / MAX_HP, size.height });
}

void DrawHealthBar(sfRenderWindow* _renderWindow)
{
	sfRenderWindow_drawSprite(_renderWindow, healthBarContainer.sprite, sfFalse);
	sfRenderWindow_drawSprite(_renderWindow, healthBar.sprite, sfFalse);
}

void CleanupHealthBar()
{
	sfSprite_destroy(healthBarContainer.sprite);
	healthBarContainer.sprite = NULL;

	sfTexture_destroy(healthBarContainer.texture);
	healthBarContainer.texture = NULL;

	sfSprite_destroy(healthBar.sprite);
	healthBar.sprite = NULL;

	sfTexture_destroy(healthBar.texture);
	healthBar.texture = NULL;
}
