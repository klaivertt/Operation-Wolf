#include "Map.h"

Map map = { 0 };

#pragma region Define Function
void LoadBackground(void);
void MoveBackground(sfSprite* _sprite, float _y);
void CleanupBackground(void);

void LoadProps(void);
void UpdateProps(float _dt);
void CleanupProps(void);
#pragma endregion

#pragma region Game Loop
void LoadMap(void)
{
	LoadBackground();
	LoadProps();
}

void UpdateMap(float _dt)
{
	//float moveX = BACKGROUND_SPEED * _dt;
	MoveBackground(map.background, -BACKGROUND_SPEED * _dt);
	UpdateProps(_dt);
}

void DrawMap(sfRenderWindow* _renderWindow)
{
	sfRenderWindow_drawSprite(_renderWindow, map.background, NULL);
}

void CleanupMap(void)
{
	CleanupProps();
}

#pragma endregion

void LoadBackground(void)
{
	sfTexture* textBackground = sfTexture_createFromFile("Assets/Sprites/Map/Bakcground.png", NULL);
	map.background = sfSprite_create();

	sfSprite_setPosition(map.background, (sfVector2f) { 0, 0 });
	sfTexture_setRepeated(textBackground, sfTrue);
	sfSprite_setTexture(map.background, textBackground, sfTrue);

	sfIntRect textRect = sfSprite_getTextureRect(map.background);
	textRect.width *= 2;
	sfSprite_setTextureRect(map.background, textRect);
}

void MoveBackground(sfSprite* _sprite, float _x)
{
	sfSprite_move(_sprite, (sfVector2f) { _x, 0 });

	sfFloatRect rect = sfSprite_getGlobalBounds(_sprite);

	if (sfSprite_getPosition(_sprite).x < -rect.width / 2)
	{
		sfSprite_move(_sprite, (sfVector2f) { rect.width / 2, 0 });
	}
}

void CleanupBackground(void)
{
	sfSprite_destroy(map.background);
}

void LoadProps(void)
{
	sfTexture* propsText = sfTexture_createFromFile("Assets/Sprites/Map/props.png", NULL);

	for (size_t i = 0; i < MAX_PROPS; i++)
	{
		map.props[i].sprite = sfSprite_create();
		sfSprite_setTexture(map.props[i].sprite, propsText, sfTrue);

		// Randomize x position and choose one of 3 fixed y positions
		map.props[i].layerY = (rand() % 3) + 1;
		int randomX = rand() % SCREEN_WIDTH;
		int randomY = PROP_HEIGHT_STEP * map.props[i].layerY;

		sfVector2f position = { (float)randomX, (float)randomY };
		sfSprite_setPosition(map.props[i].sprite, position);
	}
}

void UpdateProps(float _dt)
{
	for (size_t i = 0; i < MAX_PROPS; i++)
	{
		float move = -BACKGROUND_SPEED * _dt;

		sfSprite_move(map.props[i].sprite, (sfVector2f) { move, 0 });
	}
}

void DrawThirdPlan(sfRenderWindow* _renderWindow)
{
	for (size_t i = 0; i < MAX_PROPS; i++)
	{
		if (map.props[i].layerY == 1)
		{
			sfRenderWindow_drawSprite(_renderWindow, map.props[i].sprite, NULL);
		}
	}

}

void DrawSecondPlan(sfRenderWindow* _renderWindow)
{
	for (size_t i = 0; i < MAX_PROPS; i++)
	{
		if (map.props[i].layerY == 2)
		{
			sfRenderWindow_drawSprite(_renderWindow, map.props[i].sprite, NULL);
		}
	}

}

void DrawFistPlan(sfRenderWindow* _renderWindow)
{
	for (size_t i = 0; i < MAX_PROPS; i++)
	{
		if (map.props[i].layerY == 3)
		{
			sfRenderWindow_drawSprite(_renderWindow, map.props[i].sprite, NULL);
		}
	}
}

void CleanupProps(void)
{
	for (size_t i = 0; i < MAX_PROPS; i++)
	{
		sfSprite_destroy(map.props[i].sprite);
	}
}
