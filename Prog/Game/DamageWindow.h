#pragma once
#ifndef DAMAGEWINDOW_H
#define DAMAGEWINDOW_H

#define SPEED 6

#include "Common.h"
#include "Sprite.h"

typedef struct DamageWindow
{
	sfSprite* sprite;
	sfTexture* texture;
	float timer;

}DamageWindow;


//* @brief Loads the resources required for the damage window.
//*
//* This function initializes and prepares the resources needed for the damage window,
//* such as textures, fonts, and other UI elements, to be displayed in the application.
void LoadDamageWindow();

//* @brief Updates the state of the damage window based on the delta time.
//*
//* @param _dt The time elapsed (delta time) since the last frame, used to update animations,
//*            timers, or other time-dependent properties of the damage window.
void UpdateDamageWindow(float _dt);


//* @brief Draws the damage window onto the specified render window.
//*
//* @param _renderWindow Pointer to the render window (sfRenderWindow)
//*                      where the damage window should be drawn.
void DrawDamageWindow(sfRenderWindow* _renderWindow);

//* @brief Frees the memory and resources associated with the damage window.
//*
//* This function ensures proper cleanup by deallocating any resources (e.g., textures, fonts)
//* used for the damage window to prevent memory leaks.
void CleanupDamageWindow();

//* @brief Displays the damage window.
//*
//* This function makes the damage window visible, usually triggered when the player takes damage.
void DisplayDamageWindow(void);


#endif // !HealthBar_H

