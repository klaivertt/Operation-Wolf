#ifndef MAP_H
#define MAP_H

#include "Common.h"
#include "Sprite.h"
#include "Props.h"

#define BACKGROUND_SPEED 200.f

typedef struct Mapvoid SetSpriteOrigin(sfSprite** _sprite, sfVector2f divide)void SetSpriteOrigin(sfSprite** _sprite, sfVector2f divide)
{
	sfSprite* background;
}Map;

void LoadMap(void);
void UpdateMap(float _dt);
void DrawMap(sfRenderWindow* _renderWindow);
void CleanupMap(void);

void DrawThirdPlan(sfRenderWindow* _renderWindow);

void DrawSecondPlan(sfRenderWindow* _renderWindow);

void DrawFistPlan(sfRenderWindow* _renderWindow);
#endif