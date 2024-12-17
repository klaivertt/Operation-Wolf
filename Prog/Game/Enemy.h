#pragma once
#ifndef ENEMY_H
#define ENEMY_H

#include "Common.h"
#include "Sprite.h"
#include "Timer.h"

#include "Animations.h"
#include "Position.h"


//24 Enemies maximum 
#define ENEMY_MAX 5

#define SHOOT_DELAY 10
#define MAX_SPAWN_DELAY 2

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
	SOLDIER,
}EnemyType;

typedef enum Drop
{
	HEALTH,
	AMMO,
	NONE
}Drop;

#pragma endregion

#pragma region struct
typedef struct Anim
{
	Animation walk;
	Animation waitToShoot;
	Animation shoot;
	Animation dead;
}Anim;

typedef struct Enemy
{
	EnemyType type;
	EnemyState state;
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

	

}Enemy;

typedef struct EnemyData
{
	Enemy enemy[ENEMY_MAX];
	sfTexture* spriteSheet;

}EnemyData;
#pragma endregion

// NULL for Load Every Enemies
void LoadEnemies(short _enemyToLoad);
void KeyPressedEnemy(sfRenderWindow* _renderWindow, sfKeyEvent _key);
void MouseButtonPressedEnemy(sfRenderWindow* const _renderWindow, sfMouseButtonEvent _mouseButton);
void MouseMovedEnemy(sfRenderWindow* const _renderWindow, sfMouseMoveEvent _mouseMove);
void UpdateEnemy(float _dt);
void DrawEnemy(sfRenderWindow* _renderWindow, int _ground);
void CleanupEnemy(void);



sfBool GetEnemyState(Enemy* _enemy);
void SetEnemyState(Enemy* _enemy, EnemyState _state);

sfBool VerifPlayerKillEnemy(sfVector2f _mousePos);

int PlayerDamage(void);

Drop EnemyDrop(void);

#endif