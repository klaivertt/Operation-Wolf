#ifndef MAP_H
#define MAP_H

#include "Common.h"
#include "Sprite.h"


#define BACKGROUND_SPEED 200.f
#define MAX_PROPS 10
#define PROP_HEIGHT_STEP 192

typedef struct Props
{
	sfSprite* sprite;
	int layerY;
}Props;

typedef struct Map
{
	sfSprite* background;
	Props props[MAX_PROPS];
}Map;

void LoadMap(void);
void UpdateMap(float _dt);
void DrawMap(sfRenderWindow* _renderWindow);
void CleanupMap(void);

void DrawThirdPlan(sfRenderWindow* _renderWindow);

void DrawSecondPlan(sfRenderWindow* _renderWindow);

void DrawFistPlan(sfRenderWindow* _renderWindow);
#endif