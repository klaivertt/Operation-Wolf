#include "Grenade.h"

Grenade grenade;

void LoadGrenade()
{
	sfIntRect rect = { 24, 2184, 24 , 48 };
	sfVector2f position = { (float)rect.width , rect.height * 1.2f };
	sfVector2f origin = { 0.5 , 1 };
	grenade.texture = sfTexture_createFromFile("Assets/Sprites/SpriteSheet.png", NULL);

	CreateSprite(&grenade.sprite, grenade.texture, position, rect, origin);

	grenade.font = sfFont_createFromFile("Assets/Fonts/Prototype.ttf");
	grenade.text = sfText_create();

	sfText_setFont(grenade.text, grenade.font);
	sfText_setString(grenade.text, "0");
	sfText_setOutlineThickness(grenade.text, 2);
	sfText_setOutlineColor(grenade.text, sfBlack);
	sfText_setCharacterSize(grenade.text, 30);

	grenade.time = MAX_TIMER;
}

void DrawGrenade(sfRenderWindow* _renderWindow)
{
	if (GetGrenade() == 0)
	{
		sfRenderWindow_drawText(_renderWindow, grenade.text, NULL);
	}
	else
	{
		sfRenderWindow_drawSprite(_renderWindow, grenade.sprite, NULL);
	}
}

void UpdateGrenadeTimer(float _dt)
{
	if (GetGrenade() == 0)
	{
		grenade.timer += _dt;
		if (grenade.timer >= 1)
		{
			grenade.time--;
			grenade.timer = 0;
		}
		char string[5];
		sprintf_s(string, sizeof(string), "%d", grenade.time);
		sfText_setString(grenade.text, string);

		if (grenade.time <= 0)
		{
			ResetGrenadeTimer();
			ReloadGrenade();
			grenade.time = MAX_TIMER;
		}
	}
}

void ResetGrenadeTimer()
{
	grenade.time = 0;
}

void CleanupGrenade()
{
	sfSprite_destroy(grenade.sprite);
	grenade.sprite = NULL;

	sfTexture_destroy(grenade.texture);
	grenade.texture = NULL;

	sfText_destroy(grenade.text);
	grenade.text = NULL;

	sfFont_destroy(grenade.font);
	grenade.font = NULL;
}