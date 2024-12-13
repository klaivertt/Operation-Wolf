#pragma once
#ifndef GRENADE_H
#define GRENADE_H

#include "Common.h"
#include "Sprite.h"
#include "Player.h"

#define GRENADE_NUMBER_MAX 5

typedef struct Grenade
{
	sfSprite* sprite[GRENADE_NUMBER_MAX];
	sfTexture* texture;
}Grenade;

//* @brief Loads the magazine resources such as textures and sprites.
//*
//* This function initializes the sprites and assigns the texture to them.
//* It prepares the magazine for use in the game.
void LoadGrenade();


//* @brief Draws the magazine on the given render window.
//*
//* Loops through the sprites and renders them on the provided render window.
//*
//* @param _renderWindow Pointer to the sfRenderWindow where the magazine will be drawn.
void DrawGrenade(sfRenderWindow* _renderWindow);


//* @brief Cleans up the resources used by the magazine.
//*
//* Releases the memory allocated for textures and sprites.
//* This function should be called to avoid memory leaks when the magazine is no longer needed.
void CleanupGrenade();

#endif // !GRENADE_H

