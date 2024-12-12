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
	MoveBackground(map.background, -BACKGROUND_SPEED * _dt);
	UpdateProps(_dt, BACKGROUND_SPEED);
}

void DrawMap(sfRenderWindow* _renderWindow)
{
	sfRenderWindow_drawSprite(_renderWindow, map.background, NULL);
}

void CleanupMap(void)
{
	CleanupProps();
	CleanupBackground();
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

void DrawThirdPlan(sfRenderWindow* _renderWindow)
{
	
	DrawThirdPlanProps(_renderWindow);
}

void DrawSecondPlan(sfRenderWindow* _renderWindow)
{
	DrawSecondPlanProps(_renderWindow);
}

void DrawFistPlan(sfRenderWindow* _renderWindow)
{
	DrawFistPlanProps(_renderWindow);
}
