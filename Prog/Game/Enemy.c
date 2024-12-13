#include "Enemy.h"

EnemyData enemyData;

int temporaire = 0;

sfVector2f RandomSpawn(void);
int RandomExitPos(void);
int RandomMapPos(void);

//Return True if is on targeted Position
sfBool Move(Enemy* _enemy, int _position);

EnemyState GetEnemyState(Enemy* _enemy)
{
	return _enemy->state;
}

void SetEnemyState(Enemy* _enemy, EnemyState _state)
{
	_enemy->state = _state;
}

int PlayerDamage()
{
	int totalDamage = 0;
		
	if (enemyData.enemy[temporaire].doDamageToPlayer)
	{
		enemyData.enemy[temporaire].doDamageToPlayer = sfFalse;
		totalDamage += enemyData.enemy[temporaire].damage;
	}

	return totalDamage;
}



void LoadEnemy(void)
{
	if (enemyData.spriteSheet == NULL)
	{
		enemyData.spriteSheet = sfTexture_createFromFile("Assets/Sprites/Spritesheet.png", NULL);
	}

	sfVector2f pos = RandomSpawn();
	sfIntRect rect = { 23,23,50,98 };
	sfVector2f origin = { 0.5,1 };
	//pos = (sfVector2f){ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
	CreateSprite(&enemyData.enemy[temporaire].sprite, enemyData.spriteSheet, pos, rect, origin);

	ReloadEnemy(&enemyData.enemy[temporaire]);
}

void ReloadEnemy(Enemy* _enemy)
{
	_enemy->state = WALK;
	_enemy->life = 1;
	_enemy->damage = 1;
	_enemy->speed = 5;

	_enemy->targetedPositon = RandomMapPos();

	_enemy->haveAlreadyShoot = sfFalse;
	_enemy->doDamageToPlayer = sfFalse;

	float TimeBeforeShooting = 1;
	InitTimer(&_enemy->timer, TimeBeforeShooting);

	sfVector2f pos = RandomSpawn();
	sfSprite_setPosition(_enemy->sprite, pos);
}


void KeyPressedEnemy(sfRenderWindow* _renderWindow, sfKeyEvent _key)
{

}

void MouseButtonPressedEnemy(sfRenderWindow* const _renderWindow, sfMouseButtonEvent _mouseButton)
{

}

void MouseMovedEnemy(sfRenderWindow* const _renderWindow, sfMouseMoveEvent _mouseMove)
{

}

void UpdateEnemy(float _dt)
{

	sfBool notMoving, timerEnd;

	switch (enemyData.enemy[temporaire].state)
	{
	case WALK:

		notMoving = Move(&enemyData.enemy[temporaire], enemyData.enemy[temporaire].targetedPositon);
		if (notMoving)
		{
			if (enemyData.enemy[temporaire].haveAlreadyShoot)
			{
				SetEnemyState(&enemyData.enemy[temporaire], DEAD);
			}
			else
			{
				SetEnemyState(&enemyData.enemy[temporaire], SHOOT);
			}
		}
			
		break;

	case SHOOT:
		UpdateTimer(_dt, &enemyData.enemy[temporaire].timer);
		timerEnd = IsTimerFinished(&enemyData.enemy[temporaire].timer);
		if (timerEnd){
			enemyData.enemy[temporaire].doDamageToPlayer = sfTrue;
			SetEnemyState(&enemyData.enemy[temporaire], WALK);
			enemyData.enemy[temporaire].targetedPositon = RandomExitPos();
			enemyData.enemy[temporaire].haveAlreadyShoot = sfTrue;
		}
		break;

	case DEAD:
		printf("dead\n");
		ReloadEnemy(&enemyData.enemy[temporaire]);
		break;
	}

}

void DrawEnemy(sfRenderWindow* _renderWindow)
{

	sfRenderWindow_drawSprite(_renderWindow, enemyData.enemy[temporaire].sprite, NULL);
		
}

void CleanupEnemy(void)
{

}



//Fonction Local
sfVector2f RandomSpawn(void)
{
	int pos[2] = { 1 + rand() % 2, 1 + rand() % 3 };
	sfVector2f finalPos = { 0 };

	for (short i = 0; i < 2; i++)
	{

		switch (pos[i])
		{
		case 1:

			if (i == 0)  finalPos.x = POS_LEFT_X;
			if (i == 1)  finalPos.y = POS_HIGHT_Y;
			break;
		case 2:

			if (i == 0)  finalPos.x = POS_RIGHT_X;
			if (i == 1)  finalPos.y = POS_MIDDLE_Y;
			break;

		case 3:

			finalPos.y = POS_DOWN_Y;
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
		return POS_RIGHT_X;

	case 1:
		return POS_LEFT_X;
	}

	printf("error : RandomExitPos");
	return 0;
}

int RandomMapPos(void)
{
	return SCREEN_WIDTH * 0.05 + rand() % SCREEN_WIDTH * 0.90;
}


sfBool Move(Enemy* _enemy, int _targetedPosition)
{
	sfVector2f pos = sfSprite_getPosition(enemyData.enemy[temporaire].sprite);
	pos.x = _targetedPosition;
	return MoveSpriteToTarget(&enemyData.enemy[temporaire].sprite, pos, enemyData.enemy[temporaire].speed, sfFalse);
}



////Verifer position
//sfVector2f ok = sfSprite_getPosition(enemyData.enemy[temporaire].sprite);
//printf("\npos origin : %f %f\n", ok.x, ok.y);