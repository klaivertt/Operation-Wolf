#pragma once
#ifndef MAGAZINE_H
#define MAGAZINE_H

#include "Common.h"
#include "Sprite.h"
#include "Player.h"


typedef struct Magazine
{
	sfSprite* sprite[MAGAZINE_NUMBER_MAX];
	sfTexture* texture;
}Magazine;

//* @brief Loads the magazine resources such as textures and sprites.
//*
//* This function initializes the sprites and assigns the texture to them.
//* It prepares the magazine for use in the game.
void LoadMagazine();


//* @brief Reloads the magazine.
//*
//* Resets the magazine state, typically used to "refill" it in a game context.
//* This function may reset sprite positions or internal counters as needed.
void ReloadMagazine();


//* @brief Draws the magazine on the given render window.
//*
//* Loops through the sprites and renders them on the provided render window.
//*
//* @param _renderWindow Pointer to the sfRenderWindow where the magazine will be drawn.
void DrawMagazine(sfRenderWindow* _renderWindow);


//* @brief Cleans up the resources used by the magazine.
//*
//* Releases the memory allocated for textures and sprites.
//* This function should be called to avoid memory leaks when the magazine is no longer needed.
void CleanupMagazine();
#endif // !MAGAZINE_H

