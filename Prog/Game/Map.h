#pragma once
#ifndef MAP_H
#define MAP_H

#include "Common.h"
#include "Sprite.h"

void LoadMap(void);
void UpdateMap(float _dt);
void DrawMap(sfRenderWindow* _renderWindow);
void CleanupMap(void);

#endif