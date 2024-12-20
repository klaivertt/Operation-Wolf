#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "Common.h"
#include "Sprite.h"
#include "State.h"
#include "score.h"
#include "HealthBar.h"
#include "DamageWindow.h"
#include "ObjectsClickVerif.h"

#include "PlayerSound.h"

#define BULLET_NUMBER_MAX 16
#define MAX_HP 15
#define MAGAZINE_NUMBER_MAX 5

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
}PlayerData;

void LoadPlayer();
void DrawPlayer(sfRenderWindow* _renderWindow);
void UpdatePlayer(float _dt);
void VerifGetDamage();
void GetMousePositionPlayer(sfMouseMoveEvent _mouseMoved);
void CleanupPlayer();

void MouseButtonPressedPlayer(sfRenderWindow* const _renderWindow, sfMouseButtonEvent _mouseButton);
int GetMagazine();
int GetBullet();

int GetPlayerHP();


sfBool IsPlayerDead();


void ResetPlayer();

int GetPlayerState();

#endif // !PLAYER_H