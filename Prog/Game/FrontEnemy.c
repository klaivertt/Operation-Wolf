#include "FrontEnemy.h"

//FrontEnemyData enemyData;
//
////Return True if is on targeted Position
//
//void WaitToSpawnFE(FrontEnemy* _enemy, float _dt);
//void WalkFE(FrontEnemy* _enemy, float _dt);
//void ShootFE(FrontEnemy* _enemy, float _dt);
//void DeadFE(FrontEnemy* _enemy, float _dt);
//
//void WaitToSpawn(FrontEnemy* _enemy, float _dt);
//
//
//FrontEnemy* GetFrontEnemy(void)
//{
//	return &enemyData.enemy;
//}
//
//FrontEnemyState GetFrontEnemyState(FrontEnemy* _enemy)
//{
//	return _enemy->state;
//}
//
//void SetFrontEnemyState(FrontEnemy* _enemy, FrontEnemyState _state)
//{
//
//	if (_state != _enemy->state)
//	{
//		switch (_state)
//		{
//		case WALK_FE:
//			ResetAnimation(&_enemy->anim.walk, &_enemy->sprite);
//			break;
//		case SHOOT_FE:
//			ResetAnimation(&_enemy->anim.shoot, &_enemy->sprite);
//			break;
//		case DEAD_FE:
//			ResetAnimation(&_enemy->anim.dead, &_enemy->sprite);
//			sfVector2f pos = sfSprite_getPosition(_enemy->sprite);
//			if (pos.x > 0 && pos.x < SCREEN_WIDTH)
//			{
//				PlaySound_EnemyDie();
//			}
//
//			break;
//		default:
//			break;
//		}
//		_enemy->state = _state;
//	}
//
//}
//
//sfBool VerifPlayerKillFrontEnemy(sfVector2f _mousePos, short i)
//{
//	sfBool click = MouseClickOnSpritePixel(_mousePos, enemyData.enemy.sprite);
//	if (click)
//	{
//		SetFrontEnemyState(&enemyData.enemy, DEAD_FE);
//		return sfTrue;
//	}
//
//	return sfFalse;
//}
//
//int PlayerDamageFE(void)
//{
//	return 0;
//}
//
//
//
//
//void LoadFrontEnemy(void)
//{
//	enemyData.enemy.state = WAIT_TO_SPAWN_FE;
//	enemyData.enemy.life = TOTAL_LIFE_FRONTENEMY;
//
//	float speedMultiplicator = (1 + rand() % 6) / 10.0f;
//	enemyData.enemy.speed = SPEED_FRONTENEMY;
//
//	enemyData.enemy.haveAlreadyShoot = sfFalse;
//	enemyData.enemy.doDamageToPlayer = sfFalse;
//
//	//TIMER
//	float delay = SHOOT_DELAY_FRONTENEMY * 1.5f;
//	InitTimer(&enemyData.enemy.shootTimer, delay);
//
//	delay = (float)(rand() % MAX_SPAWN_DELAY_FRONTENEMY);
//	InitTimer(&enemyData.enemy.waitTimer, delay);
//
//	delay = DEATH_DELAY_FRONTENEMY;
//	InitTimer(&enemyData.enemy.deadTimer, delay);
//
//
//	enemyData.spriteSheet = sfTexture_createFromFile("Assets/Sprites/Characters/front_enemy.png", NULL);
//	
//
//	sfVector2f pos = { 0,0 };
//
//	sfIntRect rect = { 0,0, 1908 / 4, 489 };
//	sfVector2f origin = { 0.5,1 };
//	CreateSprite(&enemyData.enemy.sprite, enemyData.spriteSheet, pos, rect, origin);
//
//	sfFloatRect gb = sfSprite_getGlobalBounds(enemyData.enemy.sprite);
//	pos = RandomPosFE(pos, gb);
//	pos = (sfVector2f){ 500,500 };
//	sfSprite_setPosition(enemyData.enemy.sprite, pos);
//
//	enemyData.enemy.targetedPositon = SetTargetPosition(pos, gb);
//	enemyData.enemy.spawnPosition = pos;
//
//	//CreateAnimation(&enemyData.enemy.anim.walk, &enemyData.enemy.sprite, &enemyData.spriteSheet, 4, 1, 1, sfTrue, (sfVector2f) { 2, 0 });
//	//CreateAnimation(&enemyData.enemy.anim.shoot, &enemyData.enemy.sprite, &enemyData.spriteSheet, 4, 2, 2, sfTrue, (sfVector2f) { 0, 0 });
//	//CreateAnimation(&enemyData.enemy.anim.dead, &enemyData.enemy.sprite, &enemyData.spriteSheet, 4, 1, 1, sfTrue, (sfVector2f) { 3, 0 });
//}
//
//void UpdateFrontEnemy(float _dt)
//{
//	/*switch (enemyData.enemy.state)
//	{
//	case WAIT_TO_SPAWN_FE:
//
//		WaitToSpawnFE(&enemyData.enemy, _dt);
//		break;
//	case WALK_FE:
//
//		WalkFE(&enemyData.enemy, _dt);
//		break;
//	case SHOOT_FE:
//
//		ShootFE(&enemyData.enemy, _dt);
//		break;
//
//	case DEAD_FE:
//
//		DeadFE(&enemyData.enemy, _dt);
//		break;
//	}*/
//
//}
//
//void DrawFrontEnemy(sfRenderWindow* _renderWindow)
//{
//
//}
//
//void CleanupFrontEnemy(void)
//{
//
//}
//
//
////Local Function
//
//void WaitToSpawnFE(FrontEnemy* _enemy, float _dt)
//{
//	sfBool timerEnd;
//	UpdateTimer(_dt, &_enemy->waitTimer);
//	timerEnd = IsTimerFinished(&_enemy->waitTimer);
//	if (timerEnd)
//	{
//		SetFrontEnemyState(_enemy, WALK_FE);
//	}
//}
//
//void WalkFE(FrontEnemy* _enemy, float _dt)
//{
//	sfBool notMoving;
//
//	UpdateAnimation(&_enemy->anim.walk, &_enemy->sprite, _dt);
//	notMoving = MoveSpriteToTarget(&_enemy->sprite, _enemy->targetedPositon, _enemy->speed, sfFalse);
//	if (notMoving)
//	{
//		if (_enemy->haveAlreadyShoot)
//		{
//			SetFrontEnemyState(_enemy, DEAD_FE);
//		}
//		else
//		{
//			SetFrontEnemyState(_enemy, SHOOT_FE);
//		}
//	}
//}
//
//void ShootFE(FrontEnemy* _enemy, float _dt)
//{
//	sfBool timerEnd;
//
//	UpdateAnimation(&_enemy->anim.shoot, &_enemy->sprite, _dt);
//	UpdateTimer(_dt, &_enemy->shootTimer);
//	timerEnd = IsTimerFinished(&_enemy->shootTimer);
//	int actualFrame = GetAnimCurrentFrame(&_enemy->anim.shoot);
//	if (actualFrame == 2 && !_enemy->haveAlreadyShoot)
//	{
//		if (EnemyShootBehindProps(_enemy->sprite))
//		{
//			_enemy->doDamageToPlayer = sfFalse;
//			_enemy->haveAlreadyShoot = sfFalse;
//		}
//		else
//		{
//			_enemy->doDamageToPlayer = sfTrue;
//			_enemy->haveAlreadyShoot = sfTrue;
//			PlaySound_EnemyShoot();
//		}
//	}
//	if (timerEnd)
//	{
//		SetFrontEnemyState(_enemy, WALK_FE);
//	}
//}
//
//void DeadFE(FrontEnemy* _enemy, float _dt)
//{
//
//}



////Verifer position
//sfVector2f ok = sfSprite_getPosition(frontEnemyData.enemy[temporaire].sprite);
//printf("\npos origin : %f %f\Bn", ok.x, ok.y);


