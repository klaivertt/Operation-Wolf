#ifndef POSITION_H
#define POSITION_H

#include "Common.h"
#include "Collision.h"
#include "Map.h"

#define ENEMY_MAX_PER_POS_Y 2

sfVector2f RandomSpawn(void);
int RandomExitPos(void);
int RandomMapPos(void);

void IncreaseNbEnemyPositionGround(sfSprite* _sprite);
void DecreaseNbEnemyPositionGround(sfSprite* _sprite);

sfBool EnemyShootBehindProps(sfSprite* _sprite);

typedef struct PositionData
{
	short nbEnemyInBackground;
	short nbEnemyInMiddleground;
	short nbEnemyInDownground;	
}PositionData;



#endif