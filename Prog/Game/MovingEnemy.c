#include "MovingEnemy.h"

void WaitToSpawn(MovingEnemy* _enemy, float _dt);
void Walk(MovingEnemy* _enemy, float _dt);
void Shoot(MovingEnemy* _enemy, float _dt);
void Dead(MovingEnemy* _enemy, sfTexture** _texture, float _dt);

void Scale(MovingEnemy* _enemy, sfSprite** _sprite);
sfBool Move(MovingEnemy* _enemy, sfSprite** _sprite);

void SetState_MovingEnemy(MovingEnemy* _enemy, MovingEnemyState _enemyState);
MovingEnemyState GetState_MovingEnemy(MovingEnemy* _enemy);

Drop Drop_MovingEnemy(void);

//Imported function

int DamageToPlayer_MovingEnemy(MovingEnemy* _enemy)
{
	if (_enemy->doDamageToPlayer)
	{
		_enemy->doDamageToPlayer = sfFalse;
		return ME_DAMAGE;
	}
	return 0;
}

sfBool VerifPlayerKill_MovingEnemy(MovingEnemy* _enemy, sfVector2f _mousePos)
{
	sfBool click = MouseClickOnSpritePixel(_mousePos, _enemy->sprite);
	if (click)
	{
		SetState_MovingEnemy(_enemy, ME_DEAD);
		return sfTrue;
	}
	return sfFalse;
}

//Main Function

void LoadMovingEnemy(MovingEnemy* _enemy, sfTexture** _texture)
{
	_enemy->state = ME_WAIT_TO_SPAWN;
	_enemy->life = ME_TOTAL_LIFE;

	_enemy->targetedPositon = RandomMapPos();

	float speedMultiplicator = (1 + rand() % 6) / 10.0f;
	_enemy->speed = ME_MAX_SPEED * (1 - speedMultiplicator);

	_enemy->haveAlreadyShoot = sfFalse;
	_enemy->doDamageToPlayer = sfFalse;

	//TIMER
	float delay = ME_SHOOT_DELAY * 1.5f;
	InitTimer(&_enemy->shootTimer, delay);

	delay = rand() % ME_MAX_SPAWN_DELAY + (float)(rand() % 10) / 10;
	InitTimer(&_enemy->waitTimer, delay);

	delay = ME_DEATH_DELAY;
	InitTimer(&_enemy->deadTimer, delay);


	int random = 1 + rand() % 2;
	switch (random)
	{
	case 1:
		*_texture = sfTexture_createFromFile("Assets/Sprites/Game/Characters/Sprite-MovingSoldier1.png", NULL);
		break;
	case 2:
		*_texture = sfTexture_createFromFile("Assets/Sprites/Game/Characters/Sprite-MovingSoldier2.png", NULL);
		break;
	}
	sfVector2f pos = RandomSpawn();
	sfIntRect rect = { 0,0,753 / 5,208 };
	sfVector2f origin = { 0.5,1 };
	CreateSprite(&_enemy->sprite, *_texture, pos, rect, origin);


	CreateAnimation(&_enemy->anim.walk, &_enemy->sprite, _texture, 5, 2, 5, sfTrue, (sfVector2f) { 0, 0 });
	CreateAnimation(&_enemy->anim.shoot, &_enemy->sprite, _texture, 5, 2, 2, sfTrue, (sfVector2f) { 2, 0 });
	CreateAnimation(&_enemy->anim.dead, &_enemy->sprite, _texture, 5, 1, 1, sfTrue, (sfVector2f) { 4, 0 });

	IncreaseNbCharactersPositionGround(_enemy->sprite);

	_enemy->ground = (int)pos.y;
}

void UpdateMovingEnemy(MovingEnemy* _enemy, sfTexture** _texture, float _dt)
{
	switch (_enemy->state)
	{
	case ME_WAIT_TO_SPAWN:

		WaitToSpawn(_enemy, _dt);
		break;
	case ME_WALK:

		Walk(_enemy, _dt);
		break;
	case ME_SHOOT:

		Shoot(_enemy, _dt);
		break;

	case ME_DEAD:

		Dead(_enemy,_texture, _dt);
		break;
	}

	if (_enemy->state != ME_WAIT_TO_SPAWN)
	{
		sfSprite_move(_enemy->sprite, GetBackGroundSpeed());
	}

	if (_enemy->state == ME_WALK || _enemy->state == ME_DEAD)
	{
		Scale(_enemy, &_enemy->sprite);
	}
}

void DrawMovingEnemy(MovingEnemy* _enemy, sfRenderWindow* _renderWindow, int _ground)
{
	int enemyGround = _enemy->ground;
	if (enemyGround == _ground)
	{
		sfRenderWindow_drawSprite(_renderWindow, _enemy->sprite, NULL);
	}
}

void CleanupMovingEnemy(MovingEnemy* _enemy, sfTexture** _texture)
{
	if (_enemy->sprite != NULL)
	{
		sfSprite_destroy(_enemy->sprite);
		_enemy->sprite = NULL;
	}

	CleanUpAnimation(&_enemy->anim.walk, &_enemy->sprite, _texture);
	CleanUpAnimation(&_enemy->anim.waitToShoot, &_enemy->sprite, _texture);
	CleanUpAnimation(&_enemy->anim.shoot, &_enemy->sprite, _texture);
	CleanUpAnimation(&_enemy->anim.dead, &_enemy->sprite, _texture);

}

//LOCAL FUNCTION

//Update

void WaitToSpawn(MovingEnemy* _enemy, float _dt)
{
	sfBool timerEnd;
	UpdateTimer(_dt, &_enemy->waitTimer);
	timerEnd = IsTimerFinished(&_enemy->waitTimer);
	if (timerEnd)
	{
		SetState_MovingEnemy(_enemy, ME_WALK);
	}
}

void Walk(MovingEnemy* _enemy, float _dt)
{
	sfBool notMoving;

	UpdateAnimation(&_enemy->anim.walk, &_enemy->sprite, _dt);
	notMoving = Move(_enemy, &_enemy->sprite);
	if (notMoving)
	{
		if (_enemy->haveAlreadyShoot)
		{
			SetState_MovingEnemy(_enemy, ME_DEAD);
		}
		else
		{
			SetState_MovingEnemy(_enemy, ME_SHOOT);
		}
	}
}

void Shoot(MovingEnemy* _enemy, float _dt)
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
		SetState_MovingEnemy(_enemy, ME_WALK);
		_enemy->targetedPositon = RandomExitPos();
	}
}

void Dead(MovingEnemy* _enemy, sfTexture** _texture, float _dt)
{

	UpdateAnimation(&_enemy->anim.dead, &_enemy->sprite, _dt);
	UpdateTimer(_dt, &_enemy->deadTimer);
	sfBool endDeadAnimation = IsTimerFinished(&_enemy->deadTimer);
	if (endDeadAnimation)
	{
		DecreaseNbCharactersPositionGround(_enemy->sprite);
		CreateDrop(sfSprite_getPosition(_enemy->sprite), Drop_MovingEnemy());
		LoadMovingEnemy(_enemy, _texture);
	}
}

//Sprite

void Scale(MovingEnemy* _enemy, sfSprite** _sprite)
{
	sfVector2f pos = sfSprite_getPosition(*_sprite);

	sfVector2f scale = { 1,1 };
	if (pos.x < _enemy->targetedPositon)

		if (_enemy->state == ME_WALK)
		{
			scale.x = -1;
			sfVector2f pos = sfSprite_getPosition(*_sprite);


			if (pos.x < _enemy->targetedPositon)
			{
				scale.x = -1;
			}

		}

	sfSprite_setScale(*_sprite, scale);
}

sfBool Move(MovingEnemy* _enemy, sfSprite** _sprite)
{
	sfVector2f pos = sfSprite_getPosition(*_sprite);

	pos.x = (float)_enemy->targetedPositon;

	return MoveSpriteToTarget(_sprite, pos, _enemy->speed, sfFalse);
}

//State

void SetState_MovingEnemy(MovingEnemy* _enemy, MovingEnemyState _enemyState)
{
	if (_enemyState != _enemy->state)
	{
		switch (_enemyState)
		{
		case ME_WALK:
			ResetAnimation(&_enemy->anim.walk, &_enemy->sprite);
			break;
		case ME_SHOOT:
			ResetAnimation(&_enemy->anim.shoot, &_enemy->sprite);
			break;
		case ME_DEAD:
			ResetAnimation(&_enemy->anim.dead, &_enemy->sprite);

			sfVector2f pos = sfSprite_getPosition(_enemy->sprite);
			if (pos.x > 0 && pos.x < SCREEN_WIDTH)
			{
				PlaySound_EnemyDie();
			}

			break;
		default:
			break;
		}
		_enemy->state = _enemyState;
	}

}

MovingEnemyState GetState_MovingEnemy(MovingEnemy* _enemy)
{
	return _enemy->state;
}

//Drop

Drop Drop_MovingEnemy(void)
{
	int dropChance = 1 + rand() % 100;

	if (dropChance >= 20 && dropChance <= 45)
	{

		return AMMO;
	}
	else if (dropChance <= 20)
	{
		return HEALTH;
	}
	return NONE;
}