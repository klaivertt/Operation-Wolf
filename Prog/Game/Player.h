#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "Common.h"
#include "Sprite.h"

typedef struct PlayerData
{
	Image cursor;
	Image bullet;
	sfVector2f mousePosition;
}PlayerData;

void LoadPlayer();
void DrawPlayer(sfRenderWindow* _renderWindow);
void UpdatePlayer();
void GetMousePositionPlayer(sfMouseMoveEvent _mouseMoved);
void CleanupPlayer();
void LoadCursor();
void LoadAmmo();

#endif // !PLAYER_H
