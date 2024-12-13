#pragma once
#ifndef ENEMY_H
#define ENEMY_H

#include "Common.h"
#include "Sprite.h"
#include "Timer.h"

#define POS_RIGHT_X -100
#define POS_LEFT_X SCREEN_WIDTH + 100
#define POS_HIGHT_Y 200
#define POS_MIDDLE_Y 400
#define POS_DOWN_Y 600

#define ENEMY_MAX 5

#pragma region enum
typedef enum EnemyState
{
	WALK,
	SHOOT,
	DEAD,
	WAIT,

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
	int speed;

	int targetedPositon;

	sfBool haveAlreadyShoot;

	sfBool doDamageToPlayer;

	Timer timer;

}Enemy;

typedef struct EnemyData
{
	Enemy enemy[5];
	sfSprite* enemySprite[5];

	sfIntRect animEnemy[9];
	int nbEnemy;

	sfTexture* spriteSheet;

}EnemyData;
#pragma endregion

void LoadEnemy(void);
void KeyPressedEnemy(sfRenderWindow* _renderWindow, sfKeyEvent _key);
void MouseButtonPressedEnemy(sfRenderWindow* const _renderWindow, sfMouseButtonEvent _mouseButton);
void MouseMovedEnemy(sfRenderWindow* const _renderWindow, sfMouseMoveEvent _mouseMove);
void UpdateEnemy(float _dt);
void DrawEnemy(sfRenderWindow* _renderWindow);
void CleanupEnemy(void);



EnemyState GetEnemyState(Enemy* _enemy);
void SetEnemyState(Enemy* _enemy, EnemyState _state);
sfSprite* GetEnemySprite(short _i);

int PlayerDamage(void);

#endif