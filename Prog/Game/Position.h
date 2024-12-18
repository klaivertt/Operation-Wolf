#ifndef POSITION_H
#define POSITION_H

#include "Common.h"
#include "Collision.h"
#include "Map.h"

#define CHARACTERS_MAX_PER_GROUND 3

sfVector2f RandomSpawn(void);
int RandomExitPos(void);
int RandomMapPos(void);

void IncreaseNbCharactersPositionGround(sfSprite* _sprite);
void DecreaseNbCharactersPositionGround(sfSprite* _sprite);

sfBool EnemyShootBehindProps(sfSprite* _sprite);

typedef struct PositionData
{
	short charactersInBackground;
	short charactersInMiddleground;
	short charactersInDownground;
}PositionData;



#endif