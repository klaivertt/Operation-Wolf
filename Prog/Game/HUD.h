#pragma once
#ifndef HUD_H
#define HUD_H

#include "Common.h"
#include "Sprite.h"
#include "Bullet.h"
#include "Magazine.h"
#include "Score.h"
#include "HumanIcon.h"
#include "HealthBar.h"
#include "DamageWindow.h"

//*@brief Loads the resources needed for the HUD.
//*
//* This function initializes the data and resources associated with the HUD, such as
//* textures, fonts and other graphic elements.
void LoadHUD(void);


void UpdateHUD(float _dt);

//* @brief Draws the HUD in the specified rendering window.
//*
//* This function displays all HUD elements, such as score, loader,
//* and any other relevant information, on the game window.
//*
//* @param _renderWindow Pointer to the SFML window where the HUD will be displayed.
void DrawHUD(sfRenderWindow* _renderWindow);


//*@brief Releases resources associated with the HUD.
//*
//* This function cleans up the resources allocated to the HUD to prevent memory leaks.
//* This includes the destruction of textures, fonts or other loaded data
void CleanupHUD(void);


#endif // !HUD_H

