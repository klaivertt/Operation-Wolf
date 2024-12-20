#include "ObjectsClickVerif.h"


sfBool VerifClickOnEnemy(sfMouseButtonEvent _mouseButton)
{
	sfBool killEnemy = sfFalse;

	sfVector2f pos = { (float)_mouseButton.x, (float)_mouseButton.y };
	MovingEnemy* moveEnemy = GetAllMovingEnemy();
	MovingEnemy* frontEnemy = GetAllMovingEnemy();

	for (short i = FRONT_ENEMY_MAX - 1; i >= 0; i--)
	{
		if (VerifPlayerKillEnemy(pos, i, FRONT_ENEMY))
		{
			return sfTrue;
		}
	}
	//Decremente for touch the last enemy draw in first
	for (short i = MOVING_ENEMY_MAX - 1; i >= 0; i--)
	{
		
		if (!VerifClickOnProps(_mouseButton, moveEnemy[i].ground))
		{
			killEnemy = VerifPlayerKillEnemy(pos, i,MOVING_ENEMY);
		}
		if (killEnemy)
		{
			return sfTrue;
		}
	}
	return sfFalse;
}

sfBool VerifClickOnHostage(sfMouseButtonEvent _mouseButton)
{
	sfVector2f pos = { (float)_mouseButton.x, (float)_mouseButton.y };

	sfBool killHostage = VerifPlayerKillHostage(pos);
	if (killHostage)
	{
		return sfTrue;
	}
	return sfFalse;
}

sfBool VerifClickOnProps(sfMouseButtonEvent _mouseButton, int _enemyGround)
{
	sfBool collision = sfFalse;
	for (short i = 0; i < MAX_PROPS; i++)
	{
		Props* props = GetAllProps();
		sfVector2f pos = sfSprite_getPosition(props[i].sprite);
		sfVector2f mouse = { (float)_mouseButton.x, (float)_mouseButton.y };
		if (pos.y == _enemyGround + PLACEMENT_CORRECTION)
		{
			collision = MouseClickOnSpritePixel(mouse,props[i].sprite);
		}
		if (collision)
		{
			return sfTrue;
		}
	}
	return sfFalse;
}


int VerifClickOnDrop(sfMouseButtonEvent _mousePos)
{
	sfVector2f pos = { (float)_mousePos.x, (float)_mousePos.y };
	sfBool click =sfFalse;

	DropItem* drop = GetAllDrop();
	for (int i = 0; i < MAX_DROP; i++)
	{
		sfBool click = MouseClickOnSpritePixel(pos, drop[i].sprite);
		if (click)
		{
			return i;
		}
	}
	return -1;
}

