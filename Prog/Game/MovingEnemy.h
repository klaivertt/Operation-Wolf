#pragma once
#ifndef MOVINGENEMY_H
#define MOVINGENEMY_H

#include "Common.h"
#include "Sprite.h"
#include "Timer.h"

#include "Animations.h"
#include "Position.h"
#include "Drop.h"

#include "EnemySound.h"

#define ME_SHOOT_DELAY 1
#define ME_MAX_SPAWN_DELAY 4

#define ME_DAMAGE 1
#define ME_TOTAL_LIFE 1
#define ME_MAX_SPEED 8
#define ME_DEATH_DELAY 0.5f

typedef enum MovingEnemyState
{
	ME_WAIT_TO_SPAWN,
	ME_WALK,
	ME_SHOOT,
	ME_DEAD,

}MovingEnemyState;

typedef struct Anim
{
	Animation walk;
	Animation waitToShoot;
	Animation shoot;
	Animation dead;
}Anim;

typedef struct Enemy
{
	MovingEnemyState state;

	Drop drop;

	int life;
	float speed;

	int targetedPositon;

	int ground;

	sfBool haveAlreadyShoot;

	sfBool doDamageToPlayer;

	Timer waitToShootTimer;
	Timer shootTimer;
	Timer waitTimer;
	Timer deadTimer;

	Anim anim;
	sfSprite* sprite;

}MovingEnemy;

void LoadMovingEnemy(MovingEnemy* _enemy, sfTexture** _texture);
void UpdateMovingEnemy(MovingEnemy* _enemy, sfTexture** _texture, float _dt);
void DrawMovingEnemy(MovingEnemy* _enemy, sfRenderWindow* _renderWindow, int _ground);
void CleanupMovingEnemy(MovingEnemy* _enemy);

int DamageToPlayer_MovingEnemy(MovingEnemy* _enemy);
sfBool VerifPlayerKill_MovingEnemy(MovingEnemy* _enemy, sfVector2f _mousePos);

#endif