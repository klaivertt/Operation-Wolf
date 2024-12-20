#pragma once
#ifndef FRONTENEMY_H
#define FRONTENEMY_H

#include "Common.h"
#include "Sprite.h"
#include "Timer.h"

#include "Animations.h"
#include "Position.h"
#include "Drop.h"

#include "EnemySound.h"

#define FE_SHOOT_DELAY 1
#define FE_MAX_SPAWN_DELAY 25

#define FE_DAMAGE 3
#define FE_TOTAL_LIFE 1
#define FE_SPEED 20
#define FE_DEATH_DELAY 0.5f

typedef enum FrontEnemyState
{
	FE_WAIT_TO_SPAWN,
	FE_WALK,
	FE_SHOOT,
	FE_DEAD,

}FrontEnemyState;

typedef struct AnimFE
{
	Animation walk;
	Animation waitToShoot;
	Animation shoot;
	Animation dead;
}AnimFE;

typedef struct FrontEnemy
{
	FrontEnemyState state;

	Drop drop;

	int life;
	float speed;

	int targetedPositon;
	int spawnPosition;

	sfBool haveAlreadyShoot;

	sfBool doDamageToPlayer;

	Timer waitToShootTimer;
	Timer shootTimer;
	Timer waitTimer;
	Timer deadTimer;

	AnimFE anim;
	sfSprite* sprite;

}FrontEnemy;

void LoadFrontEnemy(FrontEnemy* _enemy, sfTexture** _texture);
void UpdateFrontEnemy(FrontEnemy* _enemy, sfTexture** _texture, float _dt);
void DrawFrontEnemy(FrontEnemy* _enemy, sfRenderWindow* _renderWindow);
void CleanupFrontEnemy(FrontEnemy* _enemy, sfTexture** _texture);

int DamageToPlayer_FrontEnemy(FrontEnemy* _enemy);
sfBool VerifPlayerKill_FrontEnemy(FrontEnemy* _enemy, sfVector2f _mousePos);

#endif