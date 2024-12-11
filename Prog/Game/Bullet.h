#pragma once
#ifndef BULLTE_H
#define BULLET_H

#include "Common.h"
#include "Sprite.h"

void LoadBullet();
void UpdateBullet();
void DrawBullet(sfRenderWindow* _renderWindow);
void CleanupBullet();

#endif // !BULLTE_H

