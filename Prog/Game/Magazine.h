#pragma once
#ifndef MAGAZINE_H
#define MAGAZINE_H

#include "Common.h"
#include "Sprite.h"

#define MAGAZINE_NUMBER_MAX 5

typedef struct Magazine
{
	sfSprite* sprite[MAGAZINE_NUMBER_MAX];
	sfTexture* texture;
}Magazine;

void LoadMagazine();
void UpdateMagazine();
void DrawMagazine(sfRenderWindow* _renderWindow);
void CleanupMagazine();

#endif // !MAGAZINE_H

