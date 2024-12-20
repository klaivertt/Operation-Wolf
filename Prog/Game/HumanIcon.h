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


//* @brief Loads the icon resources into memory.
//*
//* This function initializes and prepares the icon resources
//* (e.g., textures, sprites) for use in the application.
void LoadIcon();


//* @brief Draws the icon onto the specified render window.
//*
//* @param _renderWindow Pointer to the render window (sfRenderWindow)
//*                      where the icon should be drawn.
void DrawIcon(sfRenderWindow* _renderWindow);


//* @brief Frees the memory and resources associated with the icon.
//*
//* This function ensures proper cleanup by deallocating any resources
//* (e.g., textures, sprites) used for the icon to prevent memory leaks.
void CleanupIcon();


#endif // !HUMANICON_H