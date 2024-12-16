#include "Hostage.h"

HostageData hostageData;

//Return True if is on targeted Position
sfBool MoveHostage(Hostage* _hostage, sfSprite** _sprite);
void HostageMovement(sfSprite* _enemySprite, float _dt);


HostageState GetHostageState(Hostage* _enemy)
{
	return _enemy->state;
}

void SetHostageState(Hostage* _enemy, HostageState _state)
{
	_enemy->state = _state;
}

sfBool VerifPlayerKillHostage(sfVector2f _mousePos)
{
	for (short i = 0; i < HOSTAGE_MAX; i++)
	{
		sfBool click = MouseClickOnSpritePixel(_mousePos, hostageData.hostageSprite[i]);
		if (click)
		{
			SetHostageState(&hostageData.hostage[i], H_DEAD);
			return sfTrue;
		}
	}
	return sfFalse;
}

void LoadHostage(short _hostageToLoad)
{
	short i, max;
	//Every hostage
	if (_hostageToLoad == NULL)
	{
		i = 0;
		max = HOSTAGE_MAX;
	}
	else
	{
		i = _hostageToLoad - 1;
		max = i + 1;
	}

	for (i; i < max; i++)
	{
		hostageData.hostage[i].state = H_WALK;
		hostageData.hostage[i].life = 1;
		hostageData.hostage[i].maxSpeed = 8;

		hostageData.hostage[i].targetedPositon = RandomMapPos();

		float speedMultiplicator = (1 + rand() % 6) / 10.0f;
		hostageData.hostage[i].maxSpeed *= 1 - speedMultiplicator;

		if (hostageData.spriteSheet == NULL)
		{
			hostageData.spriteSheet = sfTexture_createFromFile("Assets/Sprites/Hostage.png", NULL);
		}

		sfVector2f pos = RandomSpawn();
		sfIntRect rect = { 0,0,753 / 5,208 };
		sfVector2f origin = { 0.5,1 };
		if (hostageData.hostageSprite[i] == NULL)
		{
			CreateSprite(&hostageData.hostageSprite[i], hostageData.spriteSheet, pos, rect, origin);
		}
		else
		{
			sfSprite_setTextureRect(hostageData.hostageSprite[i], rect);
			sfSprite_setOrigin(hostageData.hostageSprite[i], (sfVector2f) { (float)rect.width* origin.x, (float)rect.height* origin.y });
			sfSprite_setPosition(hostageData.hostageSprite[i], pos);
		}

		IncreaseNbEnemyPositionGround(hostageData.hostageSprite[i]);
	}

}

void UpdateHostage(float _dt)
{
	sfBool notMoving, timerEnd;

	for (short i = 0; i < HOSTAGE_MAX; i++)
	{
		switch (hostageData.hostage[i].state)
		{
		case H_WALK:

			break;
		case H_DEAD:
			DecreaseNbEnemyPositionGround(hostageData.hostageSprite[i]);
			LoadHostage(i + 1);
			break;
		};
		HostageMovement(hostageData.hostageSprite[i], _dt);
				
		//printf("position x : %f y : %f\n", sfSprite_getPosition(hostageData.hostageSprite[i]).x, sfSprite_getPosition(hostageData.hostageSprite[i]).y);
	}
}

void DrawHostage(sfRenderWindow* _renderWindow)
{
	for (short i = 0; i < HOSTAGE_MAX; i++)
	{
		sfRenderWindow_drawSprite(_renderWindow, hostageData.hostageSprite[i], NULL);
	}
}

void CleanupHostage(void)
{

}



//Local Function

sfBool MoveHostage(Hostage* _enemy, sfSprite** _sprite)
{
	sfVector2f pos = sfSprite_getPosition(*_sprite);

	pos.x = _enemy->targetedPositon;

	return MoveSpriteToTarget(_sprite, pos, _enemy->maxSpeed, sfFalse);
}

void HostageMovement(sfSprite* _enemySprite, float _dt)
{

	sfSprite_move(_enemySprite, GetBackGroundSpeed());

	//Verifer position
}