#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "Common.h"
#include "Sprite.h"
#include "HUD.h"


typedef struct PlayerData
{
	Image cursor;
	Image bullet;
	sfVector2f mousePosition;
}PlayerData;

void LoadPlayer();
void DrawPlayer(sfRenderWindow* _renderWindow);
void UpdatePlayer(float _dt);
void GetMousePositionPlayer(sfMouseMoveEvent _mouseMoved);
void CleanupPlayer();

#endif // !PLAYER_H
