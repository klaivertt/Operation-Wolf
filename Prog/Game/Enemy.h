#pragma once
#ifndef ENEMY_H
#define ENEMY_H

#include "Common.h"
#include "Sprite.h"
#include "Timer.h"
#include "Map.h"
#include "Animations.h"
#include "Position.h"



//24 Enemies maximum 


#define SHOOT_DELAY 1.5f
#define MAX_SPAWN_DELAY 2

#define DAMAGE 1
#define TOTAL_LIFE 1
#define MAX_SPEED 8

#pragma region enum

typedef enum EnemyState
{
	WAIT,
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
	sfTexture* texture;

	Animation* walk;
	Animation* shoot;
	Animation* dead;
}Anim;

typedef struct Enemy
{
	EnemyType type;
	EnemyState state;
	Drop drop;

	int life;
	float speed;

	int targetedPositon;


	sfBool haveAlreadyShoot;

	sfBool doDamageToPlayer;

	Timer shootTimer;
	Timer waitTimer;

	Animation* currentAnimation;

}Enemy;

typedef struct EnemyData
{
	Enemy enemy[ENEMY_MAX];
	sfSprite* enemySprite[ENEMY_MAX];
	sfTexture* spriteSheet;



	Anim anim;

}EnemyData;
#pragma endregion

// NULL for Load Every Enemies
void LoadEnemies(short _enemyToLoad);
void KeyPressedEnemy(sfRenderWindow* _renderWindow, sfKeyEvent _key);
void MouseButtonPressedEnemy(sfRenderWindow* const _renderWindow, sfMouseButtonEvent _mouseButton);
void MouseMovedEnemy(sfRenderWindow* const _renderWindow, sfMouseMoveEvent _mouseMove);
void UpdateEnemy(float _dt);
void DrawEnemy(sfRenderWindow* _renderWindow);
void CleanupEnemy(void);



sfBool GetEnemyState(Enemy* _enemy);
void SetEnemyState(Enemy* _enemy, EnemyState _state);

sfBool VerifPlayerKillEnemy(sfVector2f _mousePos);


int PlayerDamage(void);

#endif