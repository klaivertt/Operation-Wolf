#include "Map.h"

Map map = { 0 };

#pragma region Define Function
void LoadBackground(void);
void MoveBackground(sfSprite* _sprite, float _y);
void CleanupBackground(void);

#pragma endregion

#pragma region Game Loop
void LoadMap(void)
{
	LoadBackground();
	LoadProps();
}

void UpdateMap(float _dt)
{
	MoveBackground(map.space, -SPACE_SPEED * _dt);
	MoveBackground(map.background, -BACKGROUND_SPEED * _dt);
	MoveBackground(map.balcony, -BACKGROUND_SPEED * _dt);
	UpdateProps(_dt, BACKGROUND_SPEED);
	map.bgSpeed.x = -BACKGROUND_SPEED * _dt;
}

void DrawMap(sfRenderWindow* _renderWindow)
{
	sfRenderWindow_drawSprite(_renderWindow, map.space, NULL);
}

void CleanupMap(void)
{
	CleanupProps();
	CleanupBackground();
}

#pragma endregion

void LoadBackground(void)
{
	sfTexture* textSpace = sfTexture_createFromFile("Assets/Sprites/Map/Space.png", NULL);
	map.space = sfSprite_create();

	sfSprite_setPosition(map.space, (sfVector2f) { 0, 0 });
	sfTexture_setRepeated(textSpace, sfTrue);
	sfSprite_setTexture(map.space, textSpace, sfTrue);

	sfIntRect textRect = sfSprite_getTextureRect(map.space);
	textRect.width *= 2;
	sfSprite_setTextureRect(map.space, textRect);
	
	sfTexture* textBackground = sfTexture_createFromFile("Assets/Sprites/Map/Background.png", NULL);
	map.background = sfSprite_create();

	sfSprite_setPosition(map.background, (sfVector2f) { 0, 0 });
	sfTexture_setRepeated(textBackground, sfTrue);
	sfSprite_setTexture(map.background, textBackground, sfTrue);

	textRect = sfSprite_getTextureRect(map.background);
	textRect.width *= 2;
	sfSprite_setTextureRect(map.background, textRect);
	
	sfTexture* textBalcony = sfTexture_createFromFile("Assets/Sprites/Map/Balcony.png", NULL);
	map.balcony = sfSprite_create();

	sfSprite_setPosition(map.balcony, (sfVector2f) { 0, 0 });
	sfTexture_setRepeated(textBalcony, sfTrue);
	sfSprite_setTexture(map.balcony, textBalcony, sfTrue);

	textRect = sfSprite_getTextureRect(map.balcony);
	textRect.width *= 2;
	sfSprite_setTextureRect(map.balcony, textRect);
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
	map.background = NULL;

	sfSprite_destroy(map.space);
	map.space = NULL;

	sfSprite_destroy(map.balcony);
	map.balcony = NULL;
}

void DrawThirdPlan(sfRenderWindow* _renderWindow)
{
	sfRenderWindow_drawSprite(_renderWindow, map.background, NULL);
}

void DrawSecondPlan(sfRenderWindow* _renderWindow)
{
	sfRenderWindow_drawSprite(_renderWindow, map.balcony, NULL);
}


sfVector2f GetBackGroundSpeed()
{
	return map.bgSpeed;
}