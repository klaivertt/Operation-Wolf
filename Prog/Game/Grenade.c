#include "Grenade.h"

Grenade grenade;

void LoadGrenade()
{
	sfIntRect rect = { 24, 2184, 24 , 48 };
	sfVector2f position = { SCREEN_WIDTH / 4 * 3 + 9.5f * (float)rect.width, (float)rect.height };
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

	sfFloatRect text = sfText_getGlobalBounds(grenade.text);

	sfText_setOrigin(grenade.text, (sfVector2f) { text.width / 2, text.height });
	sfText_setPosition(grenade.text, (sfVector2f){position.x , text.height });
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