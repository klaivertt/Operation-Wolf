#pragma once
#ifndef MAGAZINE_H
#define MAGAZINE_H

#include "Common.h"
#include "Sprite.h"
#include "Player.h"

#define MAGAZINE_NUMBER_MAX 5

typedef struct Magazine
{
	sfSprite* sprite[MAGAZINE_NUMBER_MAX];
	sfTexture* texture;
}Magazine;

void LoadMagazine();
void ReloadMagazine();
void DrawMagazine(sfRenderWindow* _renderWindow);
void CleanupMagazine();

#endif // !MAGAZINE_H

