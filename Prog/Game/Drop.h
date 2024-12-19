#pragma once
#ifndef DROP_H
#define DROP_H

#include "Common.h"
#include "Sprite.h"
#include "map.h"

#define MAX_DROP 4

typedef enum DropState
{
	ON_FIELD,
	OFF_FIELD
}DropState;

typedef enum Drop
{
	HEALTH,
	AMMO,
	NONE
}Drop;

typedef struct DropItem
{
	sfSprite* sprite;
	DropState state;
	sfIntRect rect;
	Drop typeDrop;
}DropItem;

typedef struct DropData
{
	sfTexture* ammoTexture;
	sfTexture* healthTexture;
	DropItem drop[MAX_DROP];
}DropData;

void LoadDrop();
void DrawDrop(sfRenderWindow* _renderWindow);

void MoveDrop();
void CleanupDrop();

void CreateDrop(sfVector2f _vector, Drop _state);

void SetDropState(DropItem* _drop, DropState _state);
sfBool VerifPlayerClickOnDrop(sfVector2f _mousePos, int _dropNB);

DropItem* GetAllDrop();

void ResetDrop(int _nb);
#endif