//#include "FrontEnemy.h"
//
//FrontEnemyData frontEnemyData;
//
////Return True if is on targeted Position
//
//void WaitToSpawnFE(FrontEnemy* _enemy, float _dt);
//void WalkFE(FrontEnemy* _enemy, float _dt);
//void ShootFE(FrontEnemy* _enemy, float _dt);
//void DeadFE(FrontEnemy* _enemy, float _dt, short i);
//sfBool MoveFE(FrontEnemy* _enemy, sfSprite** _sprite);
//
//sfVector2f RandomPosFE(sfVector2f _pos, sfFloatRect _gb);
//sfVector2f SetTargetPosition(sfVector2f _pos, sfFloatRect _gb);
//
//FrontEnemy* GetFrontEnemy(void)
//{
//	return frontEnemyData.enemy;
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
//		case WALK:
//			ResetAnimation(&_enemy->anim.walk, &_enemy->sprite);
//			break;
//		case SHOOT:
//			ResetAnimation(&_enemy->anim.shoot, &_enemy->sprite);
//			break;
//		case DEAD:
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
//	sfBool click = MouseClickOnSpritePixel(_mousePos, frontEnemyData.enemy[i].sprite);
//	if (click)
//	{
//		SetEnemyState(&frontEnemyData.enemy[i], DEAD);
//		return sfTrue;
//	}
//
//	return sfFalse;
//}
//
//int PlayerDamage(void)
//{
//
//}
//
//
//
//
//void LoadFrontEnemies(void)
//{
//	frontEnemyData.enemy->state = WAIT_TO_SPAWN;
//	frontEnemyData.enemy->life = TOTAL_LIFE_FRONTENEMY;
//
//	float speedMultiplicator = (1 + rand() % 6) / 10.0f;
//	frontEnemyData.enemy->speed = SPEED_FRONTENEMY;
//
//	frontEnemyData.enemy->haveAlreadyShoot = sfFalse;
//	frontEnemyData.enemy->doDamageToPlayer = sfFalse;
//
//	//TIMER
//	float delay = SHOOT_DELAY_FRONTENEMY * 1.5f;
//	InitTimer(&frontEnemyData.enemy->shootTimer, delay);
//
//	delay = (float)(rand() % MAX_SPAWN_DELAY_FRONTENEMY);
//	InitTimer(&frontEnemyData.enemy->waitTimer, delay);
//
//	delay = DEATH_DELAY_FRONTENEMY;
//	InitTimer(&frontEnemyData.enemy->deadTimer, delay);
//
//	if (frontEnemyData.spriteSheet == NULL)
//	{
//		frontEnemyData.spriteSheet = sfTexture_createFromFile("Assets/Sprites/Characters/front_enemy.png", NULL);
//	}
//
//	sfVector2f pos = { 0,0 };
//
//	sfIntRect rect = { 0,0, 1908 / 4, 489 };
//	sfVector2f origin = { 0.5,1 };
//	CreateSprite(&frontEnemyData.enemy->sprite, frontEnemyData.spriteSheet, pos, rect, origin);
//
//	sfFloatRect gb = sfSprite_getGlobalBounds(&frontEnemyData.enemy->sprite);
//	pos = RandomPosFE(pos, gb);
//	sfSprite_setPosition(&frontEnemyData.enemy->sprite, pos);
//
//	frontEnemyData.enemy->targetedPositon = SetTargetedPosition(pos, gb);
//	
//
//	CreateAnimation(&frontEnemyData.enemy->anim.walk, &frontEnemyData.enemy->sprite, &frontEnemyData.spriteSheet, 4, 1, 1, sfTrue, (sfVector2f) { 2, 0 });
//	CreateAnimation(&frontEnemyData.enemy->anim.shoot, &frontEnemyData.enemy->sprite, &frontEnemyData.spriteSheet, 4, 2, 2, sfTrue, (sfVector2f) { 0, 0 });
//	CreateAnimation(&frontEnemyData.enemy->anim.dead, &frontEnemyData.enemy->sprite, &frontEnemyData.spriteSheet, 4, 1, 1, sfTrue, (sfVector2f) { 3, 0 });
//
//}
//
//void UpdateFrontEnemy(float _dt)
//{
//	switch (frontEnemyData.enemy->state)
//	{
//	case WAIT_TO_SPAWN:
//
//		//WaitToSpawn(&frontEnemyData.enemy, _dt);
//		break;
//	case WALK:
//
//		//Walk(&frontEnemyData.enemy, _dt);
//		break;
//	case SHOOT:
//
//		//Shoot(&frontEnemyData.enemy, _dt);
//		break;
//
//	case DEAD:
//
//		//Dead(&frontEnemyData.enemy, _dt, );
//		break;
//	}
//
//}
//
//void DrawFrontEnemy(sfRenderWindow* _renderWindow, int _ground)
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
//		SetFrontEnemyState(_enemy, WALK);
//	}
//}
//
//void WalkFE(FrontEnemy* _enemy, float _dt)
//{
//	sfBool notMoving;
//
//	UpdateAnimation(&_enemy->anim.walk, &_enemy->sprite, _dt);
//	notMoving = MoveFrontEnemy(_enemy, &_enemy->sprite);
//	if (notMoving)
//	{
//		if (_enemy->haveAlreadyShoot)
//		{
//			SetEnemyState(_enemy, DEAD);
//		}
//		else
//		{
//			SetEnemyState(_enemy, SHOOT);
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
//		SetFrontEnemyState(_enemy, WALK);
//	}
//}
//
//void DeadFE(FrontEnemy* _enemy, float _dt, short i)
//{
//
//}
//
//
//sfBool MoveFE(FrontEnemy* _enemy, sfSprite** _sprite)
//{
//	sfVector2f pos = sfSprite_getPosition(*_sprite);
//
//	pos.x = (float)_enemy->targetedPositon;
//
//	return MoveSpriteToTarget(_sprite, pos, _enemy->speed, sfFalse);
//}
//
//
//////Verifer position
////sfVector2f ok = sfSprite_getPosition(frontEnemyData.enemy[temporaire].sprite);
////printf("\npos origin : %f %f\Bn", ok.x, ok.y);
//
//
//sfVector2f RandomPosFE(sfVector2f _pos, sfFloatRect _gb)
//{
//
//	int random = 1 + rand() % 2;
//	int posOne, posTwo, screenOne, screenTwo;
//	float gbOne, gbTwo;
//	char firstRand;
//	switch (random)
//	{
//	case 1:
//		screenOne = SCREEN_WIDTH;
//		screenTwo = SCREEN_HEIGHT;
//		gbOne = _gb.width;
//		gbTwo = _gb.height;
//		firstRand = 1;
//		break;
//	case 2:
//		screenOne = SCREEN_HEIGHT;
//		screenTwo = SCREEN_WIDTH;
//		gbOne = _gb.height;
//		gbTwo = _gb.width;
//		firstRand = 2;
//		break;
//	}
//
//	random = 1 + rand() % 2;
//	switch (random)
//	{
//	case 1:
//		posOne = 0 - gbOne / 2;
//		break;
//	case 2:
//		posOne = screenOne + gbOne / 2;
//		break;
//	}
//
//	random = rand() % screenTwo;
//
//	if (random < 0 + gbTwo / 2)
//	{
//		posTwo = gbTwo / 2;
//	}
//	else if (random > screenTwo - gbTwo / 2)
//	{
//		posTwo = screenTwo - gbTwo / 2;
//	}
//
//	switch (firstRand)
//	{
//	case 1:
//		_pos.x = posOne;
//		_pos.y = posTwo;
//		break;
//	case 2:
//		_pos.x = posTwo;
//		_pos.y = posOne;
//		break;
//	}
//
//	return _pos;
//}
//
//sfVector2f SetTargetPosition(sfVector2f _pos, sfFloatRect _gb)
//{
//	if (_pos.x < 0)
//	{
//		return (sfVector2f) { 0 + _gb.width / 2, _pos.y };
//	}
//	else if (_pos.x > SCREEN_WIDTH)
//	{
//		return (sfVector2f) { SCREEN_WIDTH - _gb.width / 2, _pos.y };
//	}
//	else if (_pos.y < 0)
//	{
//		return (sfVector2f) { _pos.x, 0 + _gb.height / 2 };
//	}
//	else if (_pos.y > SCREEN_HEIGHT)
//	{
//		return (sfVector2f) { _pos.x, SCREEN_HEIGHT - _gb.height / 2, };
//	}
//}