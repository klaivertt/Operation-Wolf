#ifndef HOSTAGE_H
#define HOSTAGE_H

#include "Common.h"
#include "Sprite.h"
#include "Map.h"
#include "Position.h"

#define HOSTAGE_MAX 1

#pragma region enum
typedef enum HostageState
{
	H_WALK,
	H_DEAD
}HostageState;


#pragma endregion

#pragma region struct
typedef struct Hostage
{

	HostageState state;

	int life;
	int speed;
	int maxSpeed;

	int targetedPositon;
}Hostage;

typedef struct HostageData
{
	Hostage hostage[HOSTAGE_MAX];
	sfSprite* hostageSprite[HOSTAGE_MAX];

	int nbHostage;
	sfTexture* spriteSheet;

}HostageData;
#pragma endregion

void LoadHostage(short _hostageToLoad);
void UpdateHostage(float _dt);
void DrawHostage(sfRenderWindow* _renderWindow);
void CleanupHostage(void);

sfBool VerifPlayerKillHostage(sfVector2f _mousePos);
#endif