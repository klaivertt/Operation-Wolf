#include "ObjectsClickVerif.h"


sfBool VerifClickOnEnemy(sfMouseButtonEvent _mouseButton)
{
	sfBool killEnemy = sfFalse;

	sfVector2f pos = { _mouseButton.x, _mouseButton.y };
	Enemy* enemy = GetAllEnemy();

	for (short i = 0; i < ENEMY_MAX; i++)
	{
		if (!VerifClickOnProps(_mouseButton, enemy[i].ground))
		{
			killEnemy = VerifPlayerKillEnemy(pos, i);
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
	sfVector2f pos = { _mouseButton.x, _mouseButton.y };

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
		sfVector2f mouse = { _mouseButton.x, _mouseButton.y };

		if (pos.y == _enemyGround)
		{
			collision = MouseClickOnSpritePixel(mouse, props[i].sprite);
		}
		if (collision)
		{
			return sfTrue;
		}
	}
	return sfFalse;
}