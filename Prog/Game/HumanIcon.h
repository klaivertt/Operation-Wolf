#pragma once
#ifndef HUMANICON_H
#define HUMANICON_H

#include "Common.h"
#include "Sprite.h"
#include "Text.h"

typedef struct Icone
{
	Image Hostage;
	Image Enemy;

	sfText* enemyLeft;
	sfText* hostageLeft;
}Icone;

void LoadIcon();
void DrawIcon(sfRenderWindow* _renderWindow);
void CleanupIcon();

#endif // !HUMANICON_H