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
		CreateSprite(&dropData.drop[i].sprite, dropData.ammoTexture, position, (sfIntRect) { 0 }, origin);
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
		if (dropData.drop[i].state == ON_FIELD)
		{
			sfSprite_move(dropData.drop[i].sprite, GetBackGroundSpeed());
			sfVector2f dropPosition = sfSprite_getPosition(dropData.drop[i].sprite);

			// Vérifier si le drop est hors de l'écran
			if (dropPosition.x < -100)
			{
				SetDropState(&dropData.drop[i], OFF_FIELD);
				sfSprite_setPosition(dropData.drop[i].sprite, (sfVector2f) { -100, -100 });
			}
		}
	}
}

void CreateDrop(sfVector2f _vector, Drop _state)
{
	sfVector2u size = { 0 };
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
					size = sfTexture_getSize(dropData.healthTexture);
				}
				else
				{
					sfSprite_setTexture(dropData.drop[i].sprite, dropData.ammoTexture, sfFalse);
					size = sfTexture_getSize(dropData.ammoTexture);
				}
				fined = sfTrue;
				sfSprite_setTextureRect(dropData.drop[i].sprite, (sfIntRect) { 0, 0, size.x, size.y });
			}
		}

	}
}


void CleanupDrop()
{
	if (dropData.ammoTexture) sfTexture_destroy(dropData.ammoTexture);
	if (dropData.healthTexture) sfTexture_destroy(dropData.healthTexture);

	for (int i = 0; i < MAX_DROP; i++)
	{
		if (dropData.drop[i].sprite) sfSprite_destroy(dropData.drop[i].sprite);
	}
}

void SetDropState(DropItem* _dropItem, DropState _state)
{
	_dropItem->state = _state;
}

sfBool VerifPlayerClickOnDrop(sfVector2f _mousePos, int _dropNB)
{
	if (dropData.drop[_dropNB].state == ON_FIELD)
	{
		sfBool click = MouseClickOnSpritePixel(_mousePos, dropData.drop[_dropNB].sprite);
		if (click)
		{
			ResetDrop(_dropNB);
			return sfTrue;
		}
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