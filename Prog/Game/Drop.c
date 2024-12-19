#include "Drop.h"

DropData dropData;

void LoadDrop()
{
	sfIntRect rectHeal = { 1079, 1949, 50 , 44 };
	sfIntRect rectMagazine = { 866, 1964, 47 , 29 };
	sfVector2f position = { -100, -100 };
	sfVector2f origin = { 0.5 , 1 };

	dropData.ammoTexture = sfTexture_createFromFile("Assets/Sprites/Magazin.png", NULL);

	dropData.healthTexture = sfTexture_createFromFile("Assets/Sprites/Health.png", NULL);

	for (int i = 0; i < MAX_DROP; i++)
	{
		CreateSprite(&dropData.drop[i].sprite, dropData.ammoTexture, position, (sfIntRect){0}, origin);
		dropData.drop[i].state = OFF_FIELD;
	}
}

void DrawDrop(sfRenderWindow* _renderWindow)
{
	for (int i = 0; i < MAX_DROP; i++)
	{
		sfRenderWindow_drawSprite(_renderWindow, dropData.drop[i].sprite, NULL);
	}
}

void MoveDrop()
{
	for (int i = 0; i < MAX_DROP; i++)
	{
		sfSprite_move(dropData.drop[i].sprite, GetBackGroundSpeed());
	}
}

void CreateDrop(sfVector2f _vector, DropState _state)
{
	sfBool fined = sfFalse;
	for (size_t i = 0; i < MAX_DROP; i++)
	{
		if (!fined)
		{
			if (dropData.drop[i].state == OFF_FIELD)
			{
				SetDropState(&dropData.drop[i], ON_FIELD);
				sfSprite_setPosition(dropData.drop[i].sprite, _vector);
				dropData.drop[i].typeDrop = _state;
				if (_state == HEALTH)
				{
					sfSprite_setTexture(dropData.drop[i].sprite, dropData.healthTexture, sfFalse);
				}
				else
				{
					sfSprite_setTexture(dropData.drop[i].sprite, dropData.ammoTexture, sfFalse);
				}
				fined = sfTrue;
			}
		}		
	}
}

void CleanupDrop()
{

}

void SetDropState(DropItem* _dropItem, DropState _state)
{
	_dropItem->state = _state;
}

sfBool VerifPlayerClickOnDrop(sfVector2f _mousePos, int _dropNB)
{
	sfBool click = MouseClickOnSpritePixel(_mousePos, dropData.drop[_dropNB].sprite);
	if (click)
	{
		SetDropState(&dropData.drop[_dropNB], OFF_FIELD);
		return sfTrue;
	}
	return sfFalse;
}

DropItem* GetAllDrop()
{
	return dropData.drop;
}

void ResetDrop(int _nb)
{
	SetDropState(&dropData.drop[_nb], OFF_FIELD);
	sfSprite_setPosition(dropData.drop[_nb].sprite, (sfVector2f) { -100, -100 });
}