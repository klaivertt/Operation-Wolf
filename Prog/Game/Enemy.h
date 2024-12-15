#pragma once
#ifndef ENEMY_H
#define ENEMY_H

#include "Common.h"
#include "Sprite.h"
#include "Timer.h"
#include "Map.h"

#define POS_RIGHT_X -100
#define POS_LEFT_X SCREEN_WIDTH + 100

#define POS_HIGHT_Y 498
#define POS_MIDDLE_Y 850
#define POS_DOWN_Y 1000

//24 Enemies maximum 
#define ENEMY_MAX 5
#define ENEMY_MAX_PER_POS_Y 2

#define SHOOT_DELAY 1.5f
#define MAX_SPAWN_DELAY 2


#pragma region enum
typedef enum PosY
{
	HIGHT,
	MIDDLE,
	DOWN,
}PosY;

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
typedef struct Enemy
{
	EnemyType type;
	EnemyState state;
	Drop drop;

	int life;
	int damage;
	float maxSpeed;

	int targetedPositon;


	sfBool haveAlreadyShoot;

	sfBool doDamageToPlayer;

	Timer shootTimer;
	Timer waitTimer;

}Enemy;

typedef struct EnemyData
{
	Enemy enemy[ENEMY_MAX];
	sfSprite* enemySprite[5];

	sfIntRect animEnemy[9];
	int nbEnemy;

	sfTexture* spriteSheet;

	short nbEnemyPosHIGHT;
	short nbEnemyPosMIDDLE;
	short nbEnemyPosDOWN;

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