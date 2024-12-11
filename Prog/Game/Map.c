#include "Map.h"

Map map = { 0 };

void MoveBackground(sfSprite* _sprite, float _y);

void LoadMap(void)
{
	sfTexture* background = sfTexture_createFromFile("Assets/Sprites/Map/Bakcground.png", NULL);
	CreateSprite(&map.background, background, (sfVector2f) { 0, 0 }, (sfIntRect) { 0 }, (sfVector2f) { 0, 0 });

	sfTexture_setRepeated(background, sfTrue);
	sfIntRect textRect = sfSprite_getTextureRect(background);
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

	if (sfSprite_getPosition(_sprite).x < -rect.height / 2)
	{
		sfSprite_move(_sprite, (sfVector2f) { 0, rect.height / 2 });
	}
}
