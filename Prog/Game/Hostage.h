#pragma once
#ifndef HOSTAGE_H
#define HOSTAGE_H

#include "Common.h"
#include "Sprite.h"
#include "Timer.h"

#include "Animations.h"
#include "Position.h"

#include "HostageSound.h"

#define HOSTAGE_MAX 1

#define MAX_HOSTAGE_SPAWN_DELAY 15

#define TOTAL_LIFE 1
#define MAX_SPEED 8
#define DEATH_DELAY 0.5f

#pragma region enum

typedef enum HostageState
{
	H_WAIT,
	H_WALK,
	H_DEAD,

}HostageState;
#pragma endregion

#pragma region struct
typedef struct HostageAnim
{
	Animation walk;
	Animation dead;
}HostageAnim;

typedef struct Hostage
{
	HostageState state;

	int life;
	float speed;

	int targetedPositon;

	int ground;

	Timer waitTimer;
	Timer deadTimer;

	HostageAnim anim;
	sfSprite* sprite;



}Hostage;

typedef struct HostageData
{
	Hostage hostage[HOSTAGE_MAX];
	sfTexture* spriteSheet;

}HostageData;
#pragma endregion

// NULL for Load Every Enemies
void LoadHostage(short _enemyToLoad);
void UpdateHostage(float _dt);
void DrawHostage(sfRenderWindow* _renderWindow, int _ground);
void CleanupHostage(void);

HostageState GetHostageState(Hostage* _enemy);
void SetHostageState(Hostage* _enemy, HostageState _state);
sfBool VerifPlayerKillHostage(sfVector2f _mousePos);

#endif