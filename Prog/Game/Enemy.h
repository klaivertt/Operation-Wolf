#pragma once
#ifndef ENEMY_H
#define ENEMY_H

#include "Common.h"
#include "Sprite.h"

#define BASE_SPEED 300

#define POS_RIGHT_X -100
#define POS_LEFT_X 1124

#define POS_HIGHT_Y 300
#define POS_MIDDLE_Y 600
#define POS_DOWN_Y 900

typedef enum EnemyState
{
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

typedef struct Enemy
{
	EnemyType type;
	EnemyState state;
	Drop drop;

	int life;
	int damage;
	int speedMultiplicator;
	float waitTime;
	sfSprite* sprite;

}Enemy;

typedef struct EnemyData
{
	Enemy enemy[5];

	sfIntRect animSoldier[9];
	int nbSoldierSprite;

	sfTexture* spriteSheet;

}EnemyData;


void LoadEnemy(void);
void KeyPressedEnemy(sfRenderWindow* _renderWindow, sfKeyEvent _key);
void MouseButtonPressedEnemy(sfRenderWindow* const _renderWindow, sfMouseButtonEvent _mouseButton);
void MouseMovedEnemy(sfRenderWindow* const _renderWindow, sfMouseMoveEvent _mouseMove);
void UpdateEnemy(float _dt);
void DrawEnemy(sfRenderWindow* _renderWindow);
void CleanupEnemy(void);



#endif