#pragma once
#ifndef ENEMY_H
#define ENEMY_H

#include "Common.h"
#include "Sprite.h"

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

typedef struct Enemy
{
	EnemyType type;
	EnemyState state;
	
	int life;
	int damage;
	float waitTime;
	

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