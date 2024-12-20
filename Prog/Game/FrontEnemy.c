#include "FrontEnemy.h"

//Return True if is on targeted Position

void WaitToSpawnFE(FrontEnemy* _enemy, float _dt);
void WalkFE(FrontEnemy* _enemy, float _dt);
void ShootFE(FrontEnemy* _enemy, float _dt);
void DeadFE(FrontEnemy* _enemy, sfTexture** _texture, float _dt);

sfBool MoveFE(FrontEnemy* _enemy, sfSprite** _sprite);


FrontEnemy* GetFrontEnemy(void)
{
	//return &enemyData.enemy;
}

FrontEnemyState GetState_FrontEnemy(FrontEnemy* _enemy)
{
	return _enemy->state;
}

void SetState_FrontEnemy(FrontEnemy* _enemy, FrontEnemyState _state)
{

	if (_state != _enemy->state)
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

sfBool VerifPlayerKillFrontEnemy(sfVector2f _mousePos, short i)
{
	//sfBool click = MouseClickOnSpritePixel(_mousePos, enemyData.enemy.sprite);
	//if (click)
	//{
	//	SetFrontEnemyState(&enemyData.enemy, DEAD_FE);
	//	return sfTrue;
	//}

	//return sfFalse;
}

int PlayerDamageFE(void)
{
	
}




void LoadFrontEnemy(FrontEnemy* _enemy, sfTexture** _texture)
{
	_enemy->state = FE_WAIT_TO_SPAWN;
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


	sfVector2f pos = { SCREEN_WIDTH / 2,SCREEN_HEIGHT };
	sfIntRect rect = { 0,0, 1908 / 4, 489 };
	sfVector2f origin = { 0.5,1 };
	CreateSprite(&_enemy->sprite, *_texture, pos, rect, origin);

	sfFloatRect gb = sfSprite_getGlobalBounds(_enemy->sprite);
	pos.y += gb.height;
	sfSprite_setPosition(_enemy->sprite, pos);

	_enemy->targetedPositon = pos.y - gb.height;
	_enemy->spawnPosition = pos.y;

	CreateAnimation(&_enemy->anim.walk, &_enemy->sprite, _texture, 4, 1, 1, sfTrue, (sfVector2f) { 2, 0 });
	CreateAnimation(&_enemy->anim.shoot, &_enemy->sprite, _texture, 4, 2, 2, sfTrue, (sfVector2f) { 0, 0 });
	CreateAnimation(&_enemy->anim.dead, &_enemy->sprite, _texture, 4, 1, 1, sfTrue, (sfVector2f) { 3, 0 });
}

void UpdateFrontEnemy(FrontEnemy* _enemy, sfTexture** _texture, float _dt)
{
	//sfVector2f ok = sfSprite_getPosition(_enemy->sprite);
	//printf("x : %f  y : %f\n", ok.x, ok.y);
	printf("ok");
	switch (_enemy->state)
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
		SetState_MovingEnemy(_enemy, FE_WALK);
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
		CreateDrop(sfSprite_getPosition(_enemy->sprite), Drop_MovingEnemy());
		LoadFrontEnemy(_enemy, _texture);
	}
}


sfBool MoveFE(FrontEnemy* _enemy, sfSprite** _sprite)
{
	sfVector2f pos = sfSprite_getPosition(*_sprite);

	pos.y = (float)_enemy->targetedPositon;

	return MoveSpriteToTarget(_sprite, pos, _enemy->speed, sfFalse);
}