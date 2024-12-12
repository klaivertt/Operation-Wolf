#pragma once
#ifndef MAGAZINE_H
#define MAGAZINE_H

#include "Common.h"
#include "Sprite.h"
#include "Bullet.h"

#define MAGAZINE_NUMBER_MAX 5

typedef struct Magazine
{
	sfSprite* sprite[MAGAZINE_NUMBER_MAX];
	sfTexture* texture;
	int magazineNumber;
}Magazine;

void LoadMagazine();
void UpdateMagazine();
void ReloadMagazine();
void DrawMagazine(sfRenderWindow* _renderWindow);
void CleanupMagazine();

#endif // !MAGAZINE_H

