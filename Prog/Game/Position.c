#include "Position.h"

PositionData positionData;

sfVector2f RandomSpawn(void)
{
	int pos[2] = { 1 + rand() % 2, 1 + rand() % 3 };
	sfVector2f finalPos = { 0,0 };

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
			if (i == 1 && positionData.charactersInBackground < CHARACTERS_MAX_PER_GROUND)
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
			if (i == 1 && positionData.charactersInMiddleground < CHARACTERS_MAX_PER_GROUND)
			{
				finalPos.y = MIDDLEGROUND;
				break;
			}
		case 3:
			if (positionData.charactersInDownground < CHARACTERS_MAX_PER_GROUND)
			{
				finalPos.y = FORGROUND;
				break;
			}
		default:
			if (positionData.charactersInBackground < CHARACTERS_MAX_PER_GROUND)
			{
				finalPos.y = BACKGROUND;
			}
			else if (positionData.charactersInMiddleground < CHARACTERS_MAX_PER_GROUND)
			{
				finalPos.y = MIDDLEGROUND;
			}
			else if ((positionData.charactersInDownground < CHARACTERS_MAX_PER_GROUND))
			{
				finalPos.y = FORGROUND;
			}
			break;
		}

	}
	printf("\ndebut : %f", finalPos.y);
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
	return (int)(SCREEN_WIDTH * 0.1 + rand() % SCREEN_WIDTH * 0.90);
}



void IncreaseNbCharactersPositionGround(sfSprite* _sprite)
{
	sfVector2f pos = sfSprite_getPosition(_sprite);
	int posY = (int)pos.y;
	switch (posY)
	{
	case BACKGROUND:
		positionData.charactersInBackground += 1;
		break;
	case MIDDLEGROUND:
		positionData.charactersInMiddleground += 1;
		break;
	case FORGROUND:
		positionData.charactersInDownground += 1;
		break;
	default:
		printf("\nIncreaseVariablesNbEnemyPos error : problem with enemy position Y : %d", posY);
		break;
	}
}

void DecreaseNbCharactersPositionGround(sfSprite* _sprite)
{
	sfVector2f pos = sfSprite_getPosition(_sprite);
	int posY = (int)pos.y;
	switch (posY)
	{
	case BACKGROUND:
		positionData.charactersInBackground -= 1;
		break;
	case MIDDLEGROUND:
		positionData.charactersInMiddleground -= 1;
		break;
	case FORGROUND:
		positionData.charactersInDownground -= 1;
		break;
	default:
		printf("\nDecreaseVariablesNbEnemyPos error : problem with enemy position Y : %d", posY);
		break;
	}
}


sfBool EnemyShootBehindProps(sfSprite* _sprite)
{
	Props* props = GetAllProps();

	sfFloatRect rectEnemy = sfSprite_getGlobalBounds(_sprite);
	rectEnemy = (sfFloatRect){ rectEnemy.left + 74, rectEnemy.top + 80, 5, 5 };

	for (short p = 0; p < MAX_PROPS; p++)
	{
		sfFloatRect rectProps = sfSprite_getGlobalBounds(props[p].sprite);
		sfBool collision = CollisionRectRect(&rectProps, &rectEnemy);

		if (collision)
		{
			return sfTrue;
		}

	}
	return sfFalse;
}