#pragma once
#ifndef ENEMY_H
#define ENEMY_H

#include "Common.h"
#include "Sprite.h"
#include "Timer.h"

#include "Animations.h"
#include "Position.h"
#include "Drop.h"

#include "EnemySound.h"

#include "MovingEnemy.h"
#include "FrontEnemy.h"

//24 Enemies maximum 


#define SHOOT_DELAY 1
#define MAX_SPAWN_DELAY 4

#define DAMAGE 1
#define TOTAL_LIFE 1
#define MAX_SPEED 8
#define DEATH_DELAY 0.5f



#pragma region enum

typedef enum EnemyState
{
	WAIT_TO_SPAWN,
	WALK,
	SHOOT,
	DEAD,

}EnemyState;

typedef enum EnemyType
{
	MOVING_ENEMY,
	FRONT_ENEMY

}EnemyType;


#pragma endregion

#pragma region struct

typedef struct EnemyData
{
	MovingEnemy movingEnemy[MOVING_ENEMY_MAX];
	FrontEnemy frontEnemy[FRONT_ENEMY_MAX];
	sfTexture* movingEnemySpriteSheet;
	sfTexture* frontEnemySpriteSheet;

}EnemyData;
#pragma endregion

// _enemyToLoad : NULL for Load Every Enemies
// "_enemyToLoad" is deosn't us if you chose FRONT_ENEMY for "_enemyType"
void LoadEnemy(short _enemyToLoad, EnemyType _enemyType);
void UpdateEnemy(float _dt, EnemyType _enemyType);
void DrawEnemy(sfRenderWindow* _renderWindow, EnemyType _enemyType, int _ground);
void CleanupEnemy(EnemyType _enemyType);

MovingEnemy* GetAllMovingEnemy(void);
FrontEnemy* GetAllFrontEnemy(void);

sfBool VerifPlayerKillEnemy(sfVector2f _mousePos, short _i);
int PlayerDamage(void);
#endif