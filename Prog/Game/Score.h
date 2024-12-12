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

void LoadScore();
void UpdateScore();
void AddScore(int _score);
void DrawScore(sfRenderWindow* _renderWindow);
void CleanupScore();

#endif // SCORE_H

