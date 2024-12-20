#include "DamageWindow.h"

DamageWindow damageWindow;

void DisplayDamageWindow(void)
{
	sfColor color = sfSprite_getColor(damageWindow.sprite);
	color.a = 255;
	sfSprite_setColor(damageWindow.sprite, color);
}


void LoadDamageWindow()
{
	sfIntRect rect = { 0 };
	sfVector2f position = { 0.0 };
	sfVector2f origin = { 0 , 0 };
	damageWindow.texture = sfTexture_createFromFile("Assets/Sprites/Game/HUD/Damage.png", NULL);

	CreateSprite(&damageWindow.sprite, damageWindow.texture, position, rect, origin);

	sfColor color = sfSprite_getColor(damageWindow.sprite);
	color.a = 0;
	sfSprite_setColor(damageWindow.sprite, color);
	damageWindow.timer = 0;
}

void UpdateDamageWindow(float _dt)
{
	sfColor color = sfSprite_getColor(damageWindow.sprite);
	int colorA = color.a;

	if (colorA > 0)
	{
		color.a -= SPEED;
		colorA -= SPEED;
	}
	if (colorA < 0)
	{
		color.a = 0;
		colorA = 0;
	}
	sfSprite_setColor(damageWindow.sprite, color);
}

void DrawDamageWindow(sfRenderWindow* _renderWindow)
{
	sfRenderWindow_drawSprite(_renderWindow, damageWindow.sprite, NULL);
}

void CleanupDamageWindow()
{
	sfSprite_destroy(damageWindow.sprite);
	damageWindow.sprite = NULL;

	sfTexture_destroy(damageWindow.texture);
	damageWindow.texture = NULL;
}
