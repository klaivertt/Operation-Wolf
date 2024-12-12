#pragma once
#ifndef SCORE_H
#define SCORE_H

#include "Common.h"
#include "Sprite.h"

typedef struct Score
{
	sfFont* font;
	sfText* text;

	int score;
	int highScore;
}Score;

void LoadScore();
void UpdateScore(sfText* const _text, int _value);
void AddScore(int _score);
void DrawScore(sfRenderWindow* _renderWindow);
void CleanupScore();

#endif // SCORE_H

