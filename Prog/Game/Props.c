#include "Props.h"
#include <math.h>

Props props[MAX_PROPS] = { 0 };
sfTexture* texture[MAX_PROPS_TEXTURE] = { 0 };

sfBool IsPositionOccupied(sfVector2f position, float minDistance);
void NewProps(Props* _props);

#pragma region Game Loop
void LoadProps(void)
{
	texture[0] = sfTexture_createFromFile("Assets/Sprites/Map/props.png", NULL);
	texture[1] = sfTexture_createFromFile("Assets/Sprites/Map/props2.png", NULL);
	texture[2] = sfTexture_createFromFile("Assets/Sprites/Map/props3.png", NULL);

	for (size_t i = 0; i < MAX_PROPS; i++)
	{
		props[i].sprite = sfSprite_create();
		sfSprite_setTexture(props[i].sprite, texture[rand() % MAX_PROPS_TEXTURE], sfTrue);
	}

	for (size_t i = 0; i < MAX_PROPS; i++)
	{
		sfVector2f position = { 0,0 };
		do
		{
			props[i].layerY = (rand() % 3);
			int randomX = rand() % SCREEN_WIDTH;
			int randomY = 0;

			switch (props[i].layerY)
			{
			case 0:
				randomY = POS_HIGHT_Y;
				break;
			case 1:
				randomY = MIDDLEGROUND;
				break;
			case 2:
				randomY = FORGROUND;
				break;
			}
			position = (sfVector2f){ (float)randomX, (float)randomY };
		} while (IsPositionOccupied(position, PROP_MIN_DISTANCE));

		sfSprite_setPosition(props[i].sprite, position);
		SetSpriteOrigin(&props[i].sprite, (sfVector2f) { 2, 1 });
	}
}

void UpdateProps(float _dt, float _backgroundSpeed)
{
	for (size_t i = 0; i < MAX_PROPS; i++)
	{
		float move = -_backgroundSpeed * _dt;

		sfSprite_move(props[i].sprite, (sfVector2f) { move, 0 });

		sfFloatRect rect = sfSprite_getGlobalBounds(props[i].sprite);
		if (sfSprite_getPosition(props[i].sprite).x < -rect.width)
		{
			NewProps(&props[i]);
		}
	}
}

void DrawProps(sfRenderWindow* _renderWindow)
{
	for (size_t i = 0; i < MAX_PROPS; i++)
	{
		if (props[i].layerY == 0)
		{
			sfRenderWindow_drawSprite(_renderWindow, props[i].sprite, NULL);
		}
	}

	for (size_t i = 0; i < MAX_PROPS; i++)
	{
		if (props[i].layerY == 1)
		{
			sfRenderWindow_drawSprite(_renderWindow, props[i].sprite, NULL);
		}
	}

	for (size_t i = 0; i < MAX_PROPS; i++)
	{
		if (props[i].layerY == 2)
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

#pragma endregion


sfBool IsPositionOccupied(sfVector2f position, float minDistance)
{
	for (size_t i = 0; i < MAX_PROPS; i++)
	{
		sfVector2f existingPos = sfSprite_getPosition(props[i].sprite);
		float distance = sqrtf(((position.x - existingPos.x) * (position.x - existingPos.x)) + ((position.y - existingPos.y)* (position.y - existingPos.y)));
		if (distance < minDistance)
		{
			return sfTrue;
		}
	}
	return sfFalse;
}

void NewProps(Props* _props)
{
	if (_props == NULL) return;

	sfSprite_setTexture(_props->sprite, texture[rand() % MAX_PROPS_TEXTURE], sfTrue);

	// Ensure unique position
	sfVector2f position;
	do {
		_props->layerY = (rand() % 3);
		int randomX = (rand() % SCREEN_WIDTH) + (SCREEN_WIDTH * 1.5f);
		int randomY = 0;

		switch (_props->layerY)
		{
		case 0:
			randomY = POS_HIGHT_Y;
			break;
		case 1:
			randomY = MIDDLEGROUND;
			break;
		case 2:
			randomY = FORGROUND;
			break;
		}
		position = (sfVector2f){ (float)randomX, (float)randomY };
	} while (IsPositionOccupied(position, PROP_MIN_DISTANCE));

	sfSprite_setPosition(_props->sprite, position);
	SetSpriteOrigin(&_props->sprite, (sfVector2f) { 2, 1 });
}

Props* GetAllProps(void)
{
	return props;
}

Props* GetProps(size_t _index)
{
	if (_index >= MAX_PROPS)
	{
		return NULL;
	}
	return &props[_index];
}
