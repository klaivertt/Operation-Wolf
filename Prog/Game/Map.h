#ifndef MAP_H
#define MAP_H

#include "Common.h"
#include "Sprite.h"


#define BACKGROUND_SPEED 200.f

typedef struct Map
{
	sfSprite* background;
}Map;
void LoadMap(void);
void UpdateMap(float _dt);
void DrawMap(sfRenderWindow* _renderWindow);
void CleanupMap(void);

#endif