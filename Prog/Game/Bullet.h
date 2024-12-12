#pragma once
#ifndef BULLTE_H
#define BULLET_H

#include "Common.h"
#include "Sprite.h"
#include "Player.h"

typedef struct Bullet
{
	sfSprite* sprite[BULLET_NUMBER_MAX];
	sfTexture* texture;
}Bullet;

void LoadBullet();
void DrawBullet(sfRenderWindow* _renderWindow);
void CleanupBullet();

#endif // !BULLTE_H

