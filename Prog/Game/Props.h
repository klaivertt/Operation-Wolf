#ifndef PROPS_H
#define PROPS_H

#include "Common.h"
#include "Sprite.h"

#define MAX_PROPS 10
#define PROP_HEIGHT_STEP (SCREEN_HEIGHT/4)

#define MAX_PROPS_TEXTURE 2

typedef struct Props
{
	sfSprite* sprite;
	int layerY;
}Props;

void LoadProps(void);
void UpdateProps(float _dt, float _bacgroundSpeed);
void CleanupProps(void);

void DrawThirdPlanProps(sfRenderWindow* _renderWindow);

void DrawSecondPlanProps(sfRenderWindow* _renderWindow);

void DrawFistPlanProps(sfRenderWindow* _renderWindow);
#endif