#pragma once
#ifndef HealthBar_H
#define HealthBAr_H

#include "Common.h"
#include "Sprite.h"
#include "player.h"


//* @brief Loads the resources required for the health bar.
//*
//* This function initializes and prepares the health bar's resources,
//* such as textures, sprites, or shapes, for use in the application. 
void LoadHealthBar();


//* @brief Updates the state of the health bar.
//*
//* This function adjusts the health bar to reflect the current health value,
//* recalculating its size, color, or other properties based on the health status. 
void UpdateBar();


//* @brief Draws the health bar onto the specified render window.
//*
//* @param _renderWindow Pointer to the render window (sfRenderWindow)
//*                      where the health bar should be drawn. 
void DrawHealthBar(sfRenderWindow* _renderWindow);


//* @brief Frees the memory and resources associated with the health bar.
//*
//* This function ensures proper cleanup by deallocating any resources
//* (e.g., textures, shapes) used for the health bar to prevent memory leaks.
void CleanupHealthBar();


#endif // !HealthBar_H

