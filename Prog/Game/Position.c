#include "Position.h"

PositionData positionData;

sfVector2f RandomSpawn(void)
{
	int pos[2] = { 1 + rand() % 2, 1 + rand() % 3 };
	sfVector2f finalPos = { 0 };

	for (short i = 0; i < 2; i++)
	{

		switch (pos[i])
		{
		case 1:

			if (i == 0)
			{
				finalPos.x = GROUND_LEFT;
				break;
			}
			if (i == 1 && positionData.nbEnemyInBackground < ENEMY_MAX_PER_POS_Y)
			{
				finalPos.y = BACKGROUND;
				break;
			}

		case 2:

			if (i == 0)
			{
				finalPos.x = GROUND_RIGHT;
				break;
			}
			if (i == 1 && positionData.nbEnemyInMiddleground < ENEMY_MAX_PER_POS_Y)
			{
				finalPos.y = MIDDLEGROUND;
				break;
			}
		case 3:
			if (positionData.nbEnemyInDownground < ENEMY_MAX_PER_POS_Y)
			{
				finalPos.y = FORGROUND;
				break;
			}
		default:
			if (positionData.nbEnemyInBackground < ENEMY_MAX_PER_POS_Y)
			{
				finalPos.y = BACKGROUND;
			}
			else if (positionData.nbEnemyInMiddleground < ENEMY_MAX_PER_POS_Y)
			{
				finalPos.y = MIDDLEGROUND;
			}
			else if ((positionData.nbEnemyInDownground < ENEMY_MAX_PER_POS_Y))
			{
				finalPos.y = FORGROUND;
			}
			break;
		}

	}

	return finalPos;

}

int RandomExitPos(void)
{
	int pos = rand() % 2;

	switch (pos)
	{
	case 0:
		return GROUND_RIGHT;

	case 1:
		return GROUND_LEFT;
	}

	return 0;
}

int RandomMapPos(void)
{
	return SCREEN_WIDTH * 0.05 + rand() % SCREEN_WIDTH * 0.90;
}

void IncreaseNbEnemyPositionGround(sfSprite* _sprite)
{
	sfVector2f pos = sfSprite_getPosition(_sprite);
	int posY = pos.y;
	switch (posY)
	{
	case BACKGROUND:
		positionData.nbEnemyInBackground += 1;
		break;
	case MIDDLEGROUND:
		positionData.nbEnemyInMiddleground += 1;
		break;
	case FORGROUND:
		positionData.nbEnemyInDownground += 1;
		break;
	default:
		printf("\nIncreaseVariablesNbEnemyPos error : problem with enemy position Y : %d", posY);
		break;
	}
}

void DecreaseNbEnemyPositionGround(sfSprite* _sprite)
{
	sfVector2f pos = sfSprite_getPosition(_sprite);
	int posY = pos.y;
	switch (posY)
	{
	case BACKGROUND:
		positionData.nbEnemyInBackground -= 1;
		break;
	case MIDDLEGROUND:
		positionData.nbEnemyInMiddleground -= 1;
		break;
	case FORGROUND:
		positionData.nbEnemyInDownground -= 1;
		break;
	default:
		printf("\nDecreaseVariablesNbEnemyPos error : problem with enemy position Y : %d", posY);
		break;
	}

}