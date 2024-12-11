#pragma once
#ifndef MAP_H
#define MAP_H

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


void LoadMap(void);
void UpdateMap(float _dt);
void DrawMap(sfRenderWindow* _renderWindow);
void CleanupMap(void);



#endif