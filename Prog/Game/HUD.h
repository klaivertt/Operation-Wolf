#pragma once
#ifndef HUD_H
#define HUD_H

#include "Common.h"
#include "Sprite.h"
#include "Bullet.h"
#include "Magazine.h"
#include "Score.h"

typedef struct HUDData
{
	Magazine magazine;
	Bullet bullet;
	Score score;
}HUDData;

void LoadHUD();
void UpdateHUD(float _dt);
void MouseButtonPressedHUD(sfRenderWindow* const _renderWindow, sfMouseButtonEvent _mouseButton);
void DrawHUD(sfRenderWindow* _renderWindow);
void CleanupHUD();

#endif // !HUD_H

