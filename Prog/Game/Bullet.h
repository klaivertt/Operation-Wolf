#pragma once
#ifndef BULLTE_H
#define BULLET_H

#define BULLET_NUMBER_MAX 15

#include "Common.h"
#include "Sprite.h"

typedef struct Bullet
{
	sfSprite* sprite[BULLET_NUMBER_MAX];
	sfTexture* texture;
}Bullet;

void LoadBullet();
void UpdateBullet(float _dt);
void DrawBullet(sfRenderWindow* _renderWindow);
void CleanupBullet();

#endif // !BULLTE_H

