#include "FrontEnemy.h"

//Return True if is on targeted Position

void WaitToSpawnFE(FrontEnemy* _enemy, float _dt);
void WalkFE(FrontEnemy* _enemy, float _dt);
void ShootFE(FrontEnemy* _enemy, float _dt);
void DeadFE(FrontEnemy* _enemy, sfTexture** _texture, float _dt);

sfBool MoveFE(FrontEnemy* _enemy, sfSprite** _sprite);

FrontEnemyState GetState_FrontEnemy(FrontEnemy* _enemy)
{
	return _enemy->state;
}

void SetState_FrontEnemy(FrontEnemy* _enemy, FrontEnemyState _state)
{

	if (_state != GetState_FrontEnemy(_enemy))
	{
		switch (_state)
		{
		case FE_WALK:
			ResetAnimation(&_enemy->anim.walk, &_enemy->sprite);
			break;
		case FE_SHOOT:
			ResetAnimation(&_enemy->anim.shoot, &_enemy->sprite);
			break;
		case FE_DEAD:
			ResetAnimation(&_enemy->anim.dead, &_enemy->sprite);
			sfFloatRect gb = sfSprite_getGlobalBounds(_enemy->sprite);
			if (gb.top < SCREEN_WIDTH)
			{
				PlaySound_EnemyDie();
			}

			break;
		default:
			break;
		}
		_enemy->state = _state;
	}

}


sfBool VerifPlayerKill_FrontEnemy(FrontEnemy* _enemy, sfVector2f _mousePos)
{
	sfBool click = MouseClickOnSpritePixel(_mousePos, _enemy->sprite);
	if (click)
	{
		SetState_FrontEnemy(_enemy, FE_DEAD);
		return sfTrue;
	}

	return sfFalse;
}

int DamageToPlayer_FrontEnemy(FrontEnemy* _enemy)
{
	return FE_DAMAGE;
}




void LoadFrontEnemy(FrontEnemy* _enemy, sfTexture** _texture)
{
	//Variable
	SetState_FrontEnemy(_enemy, FE_WAIT_TO_SPAWN);
	_enemy->life = FE_TOTAL_LIFE;
	_enemy->speed = FE_SPEED;

	_enemy->haveAlreadyShoot = sfFalse;
	_enemy->doDamageToPlayer = sfFalse;

	//TIMER
	float delay = FE_SHOOT_DELAY * 1.5f;
	InitTimer(&_enemy->shootTimer, delay);

	delay = (float)(rand() % FE_MAX_SPAWN_DELAY);
	InitTimer(&_enemy->waitTimer, delay);

	delay = FE_DEATH_DELAY;
	InitTimer(&_enemy->deadTimer, delay);


	*_texture = sfTexture_createFromFile("Assets/Sprites/Characters/front_enemy.png", NULL);


	sfVector2f pos = { 0,0 };
	sfIntRect rect = { 0,0, 1908 / 4, 489 };
	sfVector2f origin = { 0.5,1 };
	CreateSprite(&_enemy->sprite, *_texture, pos, rect, origin);

	//Position
	sfFloatRect gb = sfSprite_getGlobalBounds(_enemy->sprite);
	pos.y = SCREEN_HEIGHT + gb.height;

	pos.x = (float) (1 + rand() % SCREEN_WIDTH);
	if (pos.x < gb.width / 2)
	{
		pos.x = gb.width / 2;
	}
	else if (pos.x > SCREEN_WIDTH - gb.width / 2)
	{
		pos.x = SCREEN_WIDTH - gb.width / 2;
	}

	sfSprite_setPosition(_enemy->sprite, pos);

	_enemy->targetedPositon = (int)(pos.y - gb.height);
	_enemy->spawnPosition = (int)pos.y;

	//Animation
	CreateAnimation(&_enemy->anim.walk, &_enemy->sprite, _texture, 4, 1, 1, sfTrue, (sfVector2f) { 2, 0 });
	CreateAnimation(&_enemy->anim.shoot, &_enemy->sprite, _texture, 4, 2, 2, sfTrue, (sfVector2f) { 0, 0 });
	CreateAnimation(&_enemy->anim.dead, &_enemy->sprite, _texture, 4, 1, 1, sfTrue, (sfVector2f) { 3, 0 });
}

void UpdateFrontEnemy(FrontEnemy* _enemy, sfTexture** _texture, float _dt)
{
	switch (GetState_FrontEnemy(_enemy))
	{
	case FE_WAIT_TO_SPAWN:

		WaitToSpawnFE(_enemy, _dt);
		break;
	case FE_WALK:

		WalkFE(_enemy, _dt);
		break;
	case FE_SHOOT:

		ShootFE(_enemy, _dt);
		break;

	case FE_DEAD:

		DeadFE(_enemy, _texture, _dt);
		break;
	}

}

void DrawFrontEnemy(FrontEnemy* _enemy, sfRenderWindow* _renderWindow)
{

	sfRenderWindow_drawSprite(_renderWindow, _enemy->sprite, NULL);
	
}

void CleanupFrontEnemy(FrontEnemy* _enemy)
{

}


//Local Function

void WaitToSpawnFE(FrontEnemy* _enemy, float _dt)
{
	sfBool timerEnd;
	UpdateTimer(_dt, &_enemy->waitTimer);
	timerEnd = IsTimerFinished(&_enemy->waitTimer);
	if (timerEnd)
	{
		SetState_FrontEnemy(_enemy, FE_WALK);
	}
}

void WalkFE(FrontEnemy* _enemy, float _dt)
{
	sfBool notMoving;

	UpdateAnimation(&_enemy->anim.walk, &_enemy->sprite, _dt);
	notMoving = MoveFE(_enemy, &_enemy->sprite);
	if (notMoving)
	{
		if (_enemy->haveAlreadyShoot)
		{
			SetState_FrontEnemy(_enemy, FE_DEAD);
		}
		else
		{
			SetState_FrontEnemy(_enemy, FE_SHOOT);
		}
	}
}

void ShootFE(FrontEnemy* _enemy, float _dt)
{
	sfBool timerEnd;

	UpdateAnimation(&_enemy->anim.shoot, &_enemy->sprite, _dt);
	UpdateTimer(_dt, &_enemy->shootTimer);
	timerEnd = IsTimerFinished(&_enemy->shootTimer);
	int actualFrame = GetAnimCurrentFrame(&_enemy->anim.shoot);
	if (actualFrame == 2 && !_enemy->haveAlreadyShoot)
	{
		if (EnemyShootBehindProps(_enemy->sprite))
		{
			_enemy->doDamageToPlayer = sfFalse;
			_enemy->haveAlreadyShoot = sfFalse;
		}
		else
		{
			_enemy->doDamageToPlayer = sfTrue;
			_enemy->haveAlreadyShoot = sfTrue;
			PlaySound_EnemyShoot();
		}
	}
	if (timerEnd)
	{
		SetState_FrontEnemy(_enemy, FE_WALK);
		_enemy->targetedPositon = _enemy->spawnPosition;
	}
}

void DeadFE(FrontEnemy* _enemy,sfTexture** _texture, float _dt)
{
	UpdateAnimation(&_enemy->anim.dead, &_enemy->sprite, _dt);
	UpdateTimer(_dt, &_enemy->deadTimer);
	sfBool endDeadAnimation = IsTimerFinished(&_enemy->deadTimer);
	if (endDeadAnimation)
	{
		DecreaseNbCharactersPositionGround(_enemy->sprite);
		LoadFrontEnemy(_enemy, _texture);
	}
}


sfBool MoveFE(FrontEnemy* _enemy, sfSprite** _sprite)
{
	sfVector2f pos = sfSprite_getPosition(*_sprite);

	pos.y = (float)_enemy->targetedPositon;

	return MoveSpriteToTarget(_sprite, pos, _enemy->speed, sfFalse);
}