#include "Props.h"

Props props[MAX_PROPS] = { 0 };
sfTexture* texture[MAX_PROPS_TEXTURE] = { 0 };
void LoadProps(void)
{
	texture[0] = sfTexture_createFromFile("Assets/Sprites/Map/props.png", NULL);
	texture[1] = sfTexture_createFromFile("Assets/Sprites/Map/props2.png", NULL);

	for (size_t i = 0; i < MAX_PROPS; i++)
	{
		props[i].sprite = sfSprite_create();
		sfSprite_setTexture(props[i].sprite, texture[rand()% MAX_PROPS_TEXTURE], sfTrue);

		// Randomize x position and choose one of 3 fixed y positions
		props[i].layerY = (rand() % 3) + 1;
		int randomX = rand() % SCREEN_WIDTH;
		int randomY = PROP_HEIGHT_STEP * props[i].layerY;

		sfVector2f position = { (float)randomX, (float)randomY };
		sfSprite_setPosition(props[i].sprite, position);
		SetSpriteOrigin(&props[i].sprite, (sfVector2f) {2,1});
	}
}

void NewProps(Props* _props)
{
	if (_props == NULL) return;

	sfSprite_setTexture(_props->sprite, texture[rand() % MAX_PROPS_TEXTURE], sfTrue);
	_props->layerY = (rand() % 3) + 1;
	int randomX = (rand() % SCREEN_WIDTH) + (SCREEN_WIDTH * 1.5f);
	int randomY = (PROP_HEIGHT_STEP * _props->layerY) + 100;

	sfVector2f position = { (float)randomX, (float)randomY };
	sfSprite_setPosition(_props->sprite, position);
	SetSpriteOrigin(&_props->sprite, (sfVector2f) { 2, 1 });
}

void UpdateProps(float _dt, float _bacgroundSpeed)
{
	for (size_t i = 0; i < MAX_PROPS; i++)
	{
		float move = -_bacgroundSpeed * _dt;

		sfSprite_move(props[i].sprite, (sfVector2f) { move, 0 });

		sfFloatRect rect = sfSprite_getGlobalBounds(props[i].sprite);
		if (sfSprite_getPosition(props[i].sprite).x < -rect.width)
		{
			NewProps(&props[i]);
		}
	}
}

void DrawThirdPlanProps(sfRenderWindow* _renderWindow)
{
	for (size_t i = 0; i < MAX_PROPS; i++)
	{
		if (props[i].layerY == 1)
		{
			sfRenderWindow_drawSprite(_renderWindow, props[i].sprite, NULL);
		}
	}

}

void DrawSecondPlanProps(sfRenderWindow* _renderWindow)
{
	for (size_t i = 0; i < MAX_PROPS; i++)
	{
		if (props[i].layerY == 2)
		{
			sfRenderWindow_drawSprite(_renderWindow, props[i].sprite, NULL);
		}
	}

}

void DrawFistPlanProps(sfRenderWindow* _renderWindow)
{
	for (size_t i = 0; i < MAX_PROPS; i++)
	{
		if (props[i].layerY == 3)
		{
			sfRenderWindow_drawSprite(_renderWindow, props[i].sprite, NULL);
		}
	}
}

void CleanupProps(void)
{
	for (size_t i = 0; i < MAX_PROPS; i++)
	{
		sfSprite_destroy(props[i].sprite);
	}
}
