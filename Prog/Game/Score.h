#pragma once
#ifndef SCORE_H
#define SCORE_H

#include "Common.h"
#include "Sprite.h"

typedef struct Score
{
	sfFont* font;
	sfText* score;

	int actualScore;
	int highScore;
}Score;


//* @brief Loads the score system.
//*
//* Initializes the resources and variables required for tracking and displaying the score.
//* This includes setting initial values and preparing any graphical components.
void LoadScore();


//* @brief Updates the score system.
//*
//* Handles any dynamic updates to the score, such as animations or effects,
//* and prepares the score for rendering.
void UpdateScore();


//* @brief Adds a value to the current score.
//*
//* Increases the score by the specified value, which can be positive or negative.
//*
//* @param _score The value to add to the current score.
void AddScore(int _score);


*@brief Draws the score on the given render window.
*
* Renders the current score on the screen, typically at a HUD or overlay position.
*
*@param _renderWindow Pointer to the sfRenderWindow where the score will be drawn.

void DrawScore(sfRenderWindow * _renderWindow);


*@brief Cleans up the resources used by the score system.
*
* Frees memory and releases resources allocated for managing or displaying the score.

void CleanupScore();


#endif // SCORE_H

