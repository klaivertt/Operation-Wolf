#ifndef PROPS_H
#define PROPS_H

#include "Common.h"
#include "Sprite.h"

#define MAX_PROPS 8
#define PROP_HEIGHT_STEP (SCREEN_HEIGHT/4)

#define MAX_PROPS_TEXTURE 3

#define PROP_MIN_DISTANCE 120

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

void DrawFirstPlanProps(sfRenderWindow* _renderWindow);

Props* GetAllProps(void);
Props* GetProps(size_t _index);
#endif