#include "Map.h"

Map map = { 0 };

void MoveBackground(sfSprite* _sprite, float _y);

void LoadMap(void)
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

void UpdateMap(float _dt)
{
	//float moveX = BACKGROUND_SPEED * _dt;
	MoveBackground(map.background, -BACKGROUND_SPEED * _dt);
}

void DrawMap(sfRenderWindow* _renderWindow)
{
	sfRenderWindow_drawSprite(_renderWindow, map.background, NULL);
}

void CleanupMap(void)
{
}

void MoveBackground(sfSprite* _sprite, float _x)
{
	sfSprite_move(_sprite, (sfVector2f) { _x, 0 });

	sfFloatRect rect = sfSprite_getGlobalBounds(_sprite);

	if (sfSprite_getPosition(_sprite).x < -rect.width / 2)
	{
		sfSprite_move(_sprite, (sfVector2f) { rect.width / 2 , 0});
	}
}
