#pragma once
#ifndef HealthBar_H
#define HealthBAr_H

#include "Common.h"
#include "Sprite.h"
#include "player.h"

void LoadHealthBar();
void UpdateBar();
void DrawHealthBar(sfRenderWindow* _renderWindow);
void CleanupHealthBar();

#endif // !HealthBar_H

