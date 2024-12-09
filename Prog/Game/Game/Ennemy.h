#ifndef ENNEMY_H
#define ENNEMY_H

#include "../Libs/Common.h"
#include "../Libs/Animations.h"
#include "../Libs/Collision.h"

typedef enum EnnemyState
{
	IDLE,
	WALK,
	ATTACK,
	HURT,
	DEAD
}EnnemyState;

typedef struct EnnemyAnim
{
	Animation idle;
	Animation walk;
	Animation hurt;
	Animation attack;
	Animation dead;
	Animation* current;
}EnnemyAnim;

typedef struct Ennemy
{
	EnnemyAnim anim;
	EnnemyState state;
} Ennemy;


void LoadEnnemy(void);
void UpdateEnnemy(float _dt);
void DrawEnnemy(sfRenderWindow* _render);
#endif