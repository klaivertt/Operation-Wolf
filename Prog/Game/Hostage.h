#pragma once
#ifndef HOSTAGE_H
#define HOSTAGE_H

#include "Common.h"
#include "Sprite.h"

#define POS_RIGHT_X -100
#define POS_LEFT_X SCREEN_WIDTH + 100
#define POS_HIGHT_Y 200
#define POS_MIDDLE_Y 400
#define POS_DOWN_Y 600

#define HOSTAGE_MAX 1

#pragma region enum
typedef enum HostageState
{
	WALK,
	DEAD,

}HostageState;


#pragma endregion

#pragma region struct
typedef struct Hostage
{

	HostageState state;

	int life;
	int speed;

	int targetedPositon;
}Hostage;

typedef struct HostageData
{
	Hostage hostage[HOSTAGE_MAX];
	sfSprite* hostageSprite[HOSTAGE_MAX];

	int nbhostage;
	sfTexture* spriteSheet;

}HostageData;
#pragma endregion

void LoadHostage(void);
void KeyPressedHostage(sfRenderWindow* _renderWindow, sfKeyEvent _key);
void MouseButtonPressedHostage(sfRenderWindow* const _renderWindow, sfMouseButtonEvent _mouseButton);
void MouseMovedHostage(sfRenderWindow* const _renderWindow, sfMouseMoveEvent _mouseMove);
void UpdateHostage(float _dt);
void DrawHostage(sfRenderWindow* _renderWindow);
void CleanupHostage(void);

sfBool VerifPlayerKillHostage(sfVector2f _mousePos);
HostageState GetHostageState(Hostage* _enemy);
void SetHostageState(Hostage* _enemy, HostageState _state);
#endif