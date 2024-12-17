#pragma once
#ifndef SCORE_H
#define SCORE_H

#include "Common.h"
#include "Sprite.h"

typedef struct Score
{
	sfFont* font;
	sfText* score;
	sfText* highScore;

	int actualScore;
	int topScore;
	sfBool isLoaded;
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
void UpdateScoreText(sfText* _text, int _value);


//* @brief Adds a value to the current score.
//*
//* Increases the score by the specified value, which can be positive or negative.
//*
//* @param _score The value to add to the current score.
void UpdateScore(int _score);


//* @brief Draws the score on the given render window.
//*
//* Renders the current score on the screen, typically at a HUD or overlay position.
//*
//* @param _renderWindow Pointer to the sfRenderWindow where the score will be drawn.
void DrawScore(sfRenderWindow* _renderWindow);

int GetScore()
{
	return score.actualScore;
}

int GetMaxScore()
{
	return score.topScore;
}

void SetHighScore();

//* @brief Cleans up the resources used by the score system.
//*
//* Frees memory and releases resources allocated for managing or displaying the score.
void CleanupScore();


#endif // SCORE_H

