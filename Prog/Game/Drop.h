#pragma once
#ifndef DROP_H
#define DROP_H

#include "Common.h"
#include "Sprite.h"
#include "Enemy.h"

typedef struct DropData
{
	Image heal;

}DropData;

typedef enum DropState
{
	ON_FIELD,
	OFF_FIELD,
}DropState;

void LoadDrop();
void DrawDrop(sfRenderWindow* _renderWindow);

void MoveDrop();
void CleanupDrop();

#endif