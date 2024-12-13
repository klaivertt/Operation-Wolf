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

//* @brief The LoadBullet function does not return any parameters, it just clamps the load.
//*
//* Loads the hud from the balls and transmits it to hud
void LoadBullet(void);

//* @brief Draws all active bullets on the given render window.
//*
//* This function iterates through all bullets and renders each one
//* on the provided window.Only bullets that are currently active.
//*
//* @param _renderWindow Pointer to the CSFML render window where the bullets will be drawn.
void DrawBullet(sfRenderWindow* _renderWindow);

//* @brief the CleanupBullet function is used to reload pointers and bullet values for the hud.
void CleanupBullet(void);

#endif // !BULLTE_H

