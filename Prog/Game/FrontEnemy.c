#include "FrontEnemy.h"

//Return True if is on targeted Position

void WaitToSpawnFE(FrontEnemy* _enemy, float _dt);
void WalkFE(FrontEnemy* _enemy, float _dt);
void ShootFE(FrontEnemy* _enemy, float _dt);
void DeadFE(FrontEnemy* _enemy, float _dt);

void WaitToSpawnFE(FrontEnemy* _enemy, float _dt);


FrontEnemy* GetFrontEnemy(void)
{
	//return &enemyData.enemy;
}

FrontEnemyState GetFrontEnemyState(FrontEnemy* _enemy)
{
	//return _enemy->state;
}

void SetFrontEnemyState(FrontEnemy* _enemy, FrontEnemyState _state)
{

	//if (_state != _enemy->state)
	//{
	//	switch (_state)
	//	{
	//	case WALK_FE:
	//		ResetAnimation(&_enemy->anim.walk, &_enemy->sprite);
	//		break;
	//	case SHOOT_FE:
	//		ResetAnimation(&_enemy->anim.shoot, &_enemy->sprite);
	//		break;
	//	case DEAD_FE:
	//		ResetAnimation(&_enemy->anim.dead, &_enemy->sprite);
	//		sfVector2f pos = sfSprite_getPosition(_enemy->sprite);
	//		if (pos.x > 0 && pos.x < SCREEN_WIDTH)
	//		{
	//			PlaySound_EnemyDie();
	//		}

	//		break;
	//	default:
	//		break;
	//	}
	//	_enemy->state = _state;
	//}

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
	//pos.y += gb.height;
	sfSprite_setPosition(_enemy->sprite, pos);

	_enemy->targetedPositon = (sfVector2f){ pos.x, pos.y - gb.height };
	_enemy->spawnPosition = pos;

	//CreateAnimation(&enemyData.enemy.anim.walk, &enemyData.enemy.sprite, &enemyData.spriteSheet, 4, 1, 1, sfTrue, (sfVector2f) { 2, 0 });
	//CreateAnimation(&enemyData.enemy.anim.shoot, &enemyData.enemy.sprite, &enemyData.spriteSheet, 4, 2, 2, sfTrue, (sfVector2f) { 0, 0 });
	//CreateAnimation(&enemyData.enemy.anim.dead, &enemyData.enemy.sprite, &enemyData.spriteSheet, 4, 1, 1, sfTrue, (sfVector2f) { 3, 0 });
}

void UpdateFrontEnemy(FrontEnemy* _enemy, sfTexture** _texture, float _dt)
{
	/*switch (enemyData.enemy.state)
	{
	case WAIT_TO_SPAWN_FE:

		WaitToSpawnFE(&enemyData.enemy, _dt);
		break;
	case WALK_FE:

		WalkFE(&enemyData.enemy, _dt);
		break;
	case SHOOT_FE:

		ShootFE(&enemyData.enemy, _dt);
		break;

	case DEAD_FE:

		DeadFE(&enemyData.enemy, _dt);
		break;
	}*/

}

void DrawFrontEnemy(FrontEnemy* _enemy, sfRenderWindow* _renderWindow)
{
	sfRenderWindow_drawSprite(_renderWindow,&_enemy->sprite,NULL );
}

void CleanupFrontEnemy(FrontEnemy* _enemy)
{

}


//Local Function

void WaitToSpawnFE(FrontEnemy* _enemy, float _dt)
{

}

void WalkFE(FrontEnemy* _enemy, float _dt)
{

}

void ShootFE(FrontEnemy* _enemy, float _dt)
{
	
}

void DeadFE(FrontEnemy* _enemy, float _dt)
{

}


