#pragma once
#ifndef HUD_H
#define HUD_H

#include "Common.h"
#include "Sprite.h"
#include "Bullet.h"
#include "Magazine.h"

typedef struct HUDData
{
	Image Bullet;
}HUDData;

void LoadHUD();
void UpdateHUD(float _dt);
void DrawHUD(sfRenderWindow* _renderWindow);
void CleanupHUD();

#endif // !HUD_H

