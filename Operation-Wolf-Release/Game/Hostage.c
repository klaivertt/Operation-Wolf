#include "Hostage.h"

HostageData hostageData;

//Return True if is on targeted Position
sfBool MoveHostage(Hostage* _hostage, sfSprite** _sprite);


HostageState GetHostageState(Hostage* _enemy)
{
	return _enemy->state;
}

void SetHostageState(Hostage* _hostage, HostageState _state)
{
	
	if (_hostage->state != _state)
	{
		switch (_state)
		{
		case H_WALK:
			ResetAnimation(&_hostage->anim.walk, &_hostage->sprite);
			break;
		case H_DEAD:
			ResetAnimation(&_hostage->anim.dead, &_hostage->sprite);
			sfVector2f pos = sfSprite_getPosition(_hostage->sprite);
			if (pos.x > 0 && pos.x < SCREEN_WIDTH)
			{
				PlaySound_HostageDie();
			}
			else
			{
				_hostage->hasLeaveArea = sfTrue;
			}
			break;
		default:
			break;
		}
		_hostage->state = _state;
	}
	
}

sfBool HostageHasLeaveArea(void)
{
	for (short i = 0; i < HOSTAGE_MAX; i++)
	{
		if (hostageData.hostage[i].hasLeaveArea)
		{
			hostageData.hostage[i].hasLeaveArea = sfFalse;
			return sfTrue;
		}
	}
	return sfFalse;
}

void LoadHostage(short _hostageToLoad)
{
	short i, max;
	//Every hostage
	if (_hostageToLoad == 0)
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
		hostageData.hostage[i].state = H_WAIT;
		hostageData.hostage[i].life = 1;

		float speedMultiplicator = (1 + rand() % 6) / 10.0f;
		hostageData.hostage[i].speed = ME_MAX_SPEED * (1 - speedMultiplicator);

		hostageData.hostage[i].hasLeaveArea = sfFalse;

		//TIMER
		float delay = (float)(rand() % MAX_HOSTAGE_SPAWN_DELAY);
		InitTimer(&hostageData.hostage[i].waitTimer, delay);

		delay = ME_DEATH_DELAY;
		InitTimer(&hostageData.hostage[i].deadTimer, delay);


		if (hostageData.spriteSheet == NULL)
		{
			hostageData.spriteSheet = sfTexture_createFromFile("Assets/Sprites/Game/Characters/Hostage.png", NULL);
		}

		sfVector2f pos = RandomSpawn();
		
		sfIntRect rect = { 0,0,360 / 3, 189 };
		sfVector2f origin = { 0.5,1 };

		CreateSprite(&hostageData.hostage[i].sprite, hostageData.spriteSheet, pos, rect, origin);

		sfVector2f scale = { 1,1 };
		if (pos.x == GROUND_RIGHT)
		{
			hostageData.hostage[i].targetedPositon = GROUND_LEFT;
			scale.x = -1;
		}
		else
		{
			hostageData.hostage[i].targetedPositon = GROUND_RIGHT;
		}
		sfSprite_setScale(hostageData.hostage->sprite, scale);

		CreateAnimation(&hostageData.hostage[i].anim.walk, &hostageData.hostage[i].sprite, &hostageData.spriteSheet, 3, 2, 5, sfTrue, (sfVector2f) { 0, 0 });
		CreateAnimation(&hostageData.hostage[i].anim.dead, &hostageData.hostage[i].sprite, &hostageData.spriteSheet, 3, 1, 1, sfTrue, (sfVector2f) { 2, 0 });

		hostageData.hostage[i].ground = (int)pos.y;
	}
}

void UpdateHostage(float _dt)
{
	sfBool notMoving, timerEnd;

	for (short i = 0; i < HOSTAGE_MAX; i++)
	{
		switch (hostageData.hostage[i].state)
		{
		case H_WAIT:

			UpdateTimer(_dt, &hostageData.hostage[i].waitTimer);
			timerEnd = IsTimerFinished(&hostageData.hostage[i].waitTimer);
			if (timerEnd)
			{
				SetHostageState(&hostageData.hostage[i], H_WALK);
			}
			break;
		case H_WALK:

			UpdateAnimation(&hostageData.hostage[i].anim.walk, &hostageData.hostage[i].sprite, _dt);

			notMoving = MoveHostage(&hostageData.hostage[i], &hostageData.hostage[i].sprite);
			if (notMoving)
			{
				SetHostageState(&hostageData.hostage[i], H_DEAD);
			}
			break;
		case H_DEAD:

			UpdateAnimation(&hostageData.hostage[i].anim.dead, &hostageData.hostage[i].sprite, _dt);
			UpdateTimer(_dt, &hostageData.hostage[i].deadTimer);
			timerEnd = IsTimerFinished(&hostageData.hostage[i].deadTimer);
			if (timerEnd)
			{
				DecreaseNbCharactersPositionGround(hostageData.hostage[i].sprite);
				LoadHostage(i + 1);
			}
			break;
		};
	}

	if (hostageData.hostage->state != H_WAIT)
	{
		sfSprite_move(hostageData.hostage->sprite, GetBackGroundSpeed());
	}
}

void DrawHostage(sfRenderWindow* _renderWindow, int _ground)
{
	for (short i = 0; i < HOSTAGE_MAX; i++)
	{
		int enemyGround = hostageData.hostage[i].ground;
		if (enemyGround == _ground)
		{
			sfRenderWindow_drawSprite(_renderWindow, hostageData.hostage[i].sprite, NULL);
		}
	}

}

void CleanupHostage(void)
{
	sfTexture_destroy(hostageData.spriteSheet);
	hostageData.spriteSheet = NULL;

	for (short i = 0; i < HOSTAGE_MAX; i++)
	{
		sfSprite_destroy(hostageData.hostage[i].sprite);
		hostageData.hostage[i].sprite = NULL;

		CleanUpAnimation(&hostageData.hostage->anim.dead, &hostageData.hostage[i].sprite, &hostageData.spriteSheet);
		CleanUpAnimation(&hostageData.hostage->anim.walk, &hostageData.hostage[i].sprite, &hostageData.spriteSheet);
	}
	

}

//Local Function

sfBool MoveHostage(Hostage* _enemy, sfSprite** _sprite)
{
	sfVector2f pos = sfSprite_getPosition(*_sprite);

	pos.x = (float)_enemy->targetedPositon;

	return MoveSpriteToTarget(_sprite, pos, _enemy->speed, sfFalse);
}

sfBool VerifPlayerKillHostage(sfVector2f _mousePos)
{
	for (short i = 0; i < HOSTAGE_MAX; i++)
	{
		sfBool click = MouseClickOnSpritePixel(_mousePos, hostageData.hostage[i].sprite);
		if (click)
		{
			SetHostageState(&hostageData.hostage[i], H_DEAD);
			return sfTrue;
		}
	}
	return sfFalse;
}

Hostage* GetHostage(void)
{
	return hostageData.hostage;
}	