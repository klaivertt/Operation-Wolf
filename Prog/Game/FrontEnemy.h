//#pragma once
//#ifndef FRONTGENEMY_H
//#define FRONTENEMY_H
//
//#include "Common.h"
//#include "Sprite.h"
//#include "Timer.h"
//
//#include "Animations.h"
//#include "Position.h"
//#include "Drop.h"
//
//#include "EnemySound.h"
//
//
////24 Enemies maximum 
//
//#define SHOOT_DELAY_FRONTENEMY 1
//#define MAX_SPAWN_DELAY_FRONTENEMY 40
//
//#define DAMAGE_FRONTENEMY 5
//#define TOTAL_LIFE_FRONTENEMY 1
//#define SPEED_FRONTENEMY 8
//#define DEATH_DELAY_FRONTENEMY 0.3f
//
//#pragma region enum
//
//typedef enum FrontEnemyState
//{
//	WAIT_TO_SPAWN,
//	WALK,
//	SHOOT,
//	DEAD,
//
//}FrontEnemyState;
//
////typedef enum EnemyType
////{
////	SOLDIER,
////}EnemyType;
//
//
//#pragma endregion
//
//#pragma region struct
//typedef struct Anim
//{
//	Animation walk;
//	Animation waitToShoot;
//	Animation shoot;
//	Animation dead;
//}Anim;
//
//typedef struct FrontEnemy
//{
//	//EnemyType type;
//	FrontEnemyState state;
//
//	int life;
//	float speed;
//
//	int targetedPositon;
//
//	sfBool haveAlreadyShoot;
//
//	sfBool doDamageToPlayer;
//
//	Timer waitToShootTimer;
//	Timer shootTimer;
//	Timer waitTimer;
//	Timer deadTimer;
//
//	Anim anim;
//	sfSprite* sprite;
//
//}FrontEnemy;
//
//typedef struct FrontEnemyData
//{
//	FrontEnemy enemy[ENEMY_MAX];
//	sfTexture* spriteSheet;
//
//}FrontEnemyData;
//#pragma endregion
//
//
//
//#endif