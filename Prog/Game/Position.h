#ifndef POSITION_H
#define POSITION_H

#include "Common.h"

#define GROUND_RIGHT -100
#define GROUND_LEFT SCREEN_WIDTH + 100

#define BACKGROUND 498
#define MIDDLEGROUND 850
#define FORGROUND 1000

#define ENEMY_MAX 6
#define ENEMY_MAX_PER_POS_Y 2

sfVector2f RandomSpawn(void);
int RandomExitPos(void);
int RandomMapPos(void);
void IncreaseNbEnemyPositionGround(sfSprite* _sprite);
void DecreaseNbEnemyPositionGround(sfSprite* _sprite);

typedef struct PositionData
{
	short nbEnemyInBackground;
	short nbEnemyInMiddleground;
	short nbEnemyInDownground;	
}PositionData;

#endif