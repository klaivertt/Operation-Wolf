#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "Common.h"
#include "Sprite.h"
#include "Enemy.h"

#define BULLET_NUMBER_MAX 15

typedef struct PlayerData
{
	Image cursor;
	sfVector2f mousePosition;

	int HP;
	int magazineNumber;
	int bulletNumber;
}PlayerData;

void LoadPlayer();
void DrawPlayer(sfRenderWindow* _renderWindow);
void UpdatePlayer(float _dt);
void GetDamage(int _damage);
void GetMousePositionPlayer(sfMouseMoveEvent _mouseMoved);
void CleanupPlayer();

void MouseButtonPressedPlayer(sfRenderWindow* const _renderWindow, sfMouseButtonEvent _mouseButton);
int GetMagazine();
int GetBullet();

#endif // !PLAYER_H
