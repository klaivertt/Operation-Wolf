#pragma once
#ifndef DAMAGEWINDOW_H
#define DAMAGEWINDOW_H

#define SPEED 6

#include "Common.h"
#include "Sprite.h"

typedef struct DamageWindow
{
	sfSprite* sprite;
	sfTexture* texture;
	float timer;

}DamageWindow;

void LoadDamageWindow();
void UpdateDamageWindow(float _dt);
void DrawDamageWindow(sfRenderWindow* _renderWindow);
void CleanupDamageWindow();

void DisplayDamageWindow(void);

#endif // !HealthBar_H

