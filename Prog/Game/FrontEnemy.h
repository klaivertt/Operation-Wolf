#pragma once
#ifndef FRONTGENEMY_H
#define FRONTENEMY_H

//#include "common.h"
//#include "sprite.h"
//#include "timer.h"
//
//#include "animations.h"
//#include "position.h"
//#include "drop.h"
//
//#include "enemysound.h"
//
//
////24 enemies maximum 
//
//#define shoot_delay_frontenemy 1
//#define max_spawn_delay_frontenemy 40
//
//#define damage_frontenemy 5
//#define total_life_frontenemy 1
//#define speed_frontenemy 8
//#define death_delay_frontenemy 0.3f
//
//#pragma region enum
//
//typedef enum frontenemystate
//{
//	wait_to_spawn_fe,
//	walk_fe,
//	shoot_fe,
//	dead_fe
//
//}frontenemystate;
//
////typedef enum enemytype
////{
////	soldier,
////}enemytype;
//
//
//#pragma endregion
//
//#pragma region struct
//typedef struct animfe
//{
//	animation walk;
//	animation waittoshoot;
//	animation shoot;
//	animation dead;
//}animfe;
//
//typedef struct frontenemy
//{
//	//enemytype type;
//	frontenemystate state;
//
//	int life;
//	float speed;
//
//	sfvector2f targetedpositon;
//	sfvector2f spawnposition;
//
//	sfbool havealreadyshoot;
//
//	sfbool dodamagetoplayer;
//
//	timer waittoshoottimer;
//	timer shoottimer;
//	timer waittimer;
//	timer deadtimer;
//
//	animfe anim;
//	sfsprite* sprite;
//
//}frontenemy;
//
//typedef struct frontenemydata
//{
//	frontenemy enemy;
//	sftexture* spritesheet;
//
//}frontenemydata;
//#pragma endregion
//
//frontenemy* getfrontenemy(void);
//frontenemystate getfrontenemystate(frontenemy* _enemy);
//void setfrontenemystate(frontenemy* _enemy, frontenemystate _state);
//sfbool verifplayerkillfrontenemy(sfvector2f _mousepos, short i);
//int playerdamagefe(void);
//
//void loadfrontenemy(void);
//void updatefrontenemy(float _dt);
//void drawfrontenemy(sfrenderwindow* _renderwindow);
//void cleanupfrontenemy(void);
#endif