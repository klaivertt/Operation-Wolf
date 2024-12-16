#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "Common.h"
#include "Sprite.h"
#include "Enemy.h"
#include "State.h"
#include "Grenade.h"
#include "score.h"
#include "HealthBar.h"

#define BULLET_NUMBER_MAX 16
#define GRENADE_NUMBER_MAX 1
#define MAX_HP 20

typedef enum PlayerState
{
	ALIVE,
	NOT_ALIVE,
}PlayerState;

typedef struct PlayerData
{
	Image cursor;
	sfVector2f mousePosition;
	PlayerState state;

	Score score;

	int HP;
	int magazineNumber;
	int bulletNumber;
	int grenadeNumber;
}PlayerData;

void LoadPlayer();
void DrawPlayer(sfRenderWindow* _renderWindow);
void UpdatePlayer(float _dt);
void GetDamage();
void GetMousePositionPlayer(sfMouseMoveEvent _mouseMoved);
void CleanupPlayer();

void MouseButtonPressedPlayer(sfRenderWindow* const _renderWindow, sfMouseButtonEvent _mouseButton);
int GetMagazine();
int GetBullet();
int GetGrenade();

void ReloadGrenade();

void VerifClickOnEnemy(sfMouseButtonEvent _mouseButton);

void ShootGrenade();

int GetPlayerState();

#endif // !PLAYER_H