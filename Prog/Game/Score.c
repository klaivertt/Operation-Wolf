#include "Score.h"

Score score;

void LoadScore()
{
	char scoreString = "5";
	int fontSize = 30;

	sfVector2f positionScore = { SCREEN_WIDTH / 3 , 30 };
	sfVector2f positionHighScore = { SCREEN_WIDTH / 2 + 30 * 20 , 30 };

	score.score = InitText("0", fontSize, positionScore);
	score.highScore= InitText("0", fontSize, positionHighScore);

	score.actualScore = 0;
	if (score.isLoaded)
	{
		score.topScore = 0;
		score.isLoaded = sfFalse;
	}
}

void UpdateScoreText(sfText* _text, int _value)
{
	UpdateText(&score.score, "%d", score.actualScore);
}

//add the ennemi score to the actual score
void UpdateScore(int _score)
{
	score.actualScore += _score;
	UpdateScoreText(score.score, score.actualScore);
	SetHighScore();
}

int GetScore()
{
	return score.actualScore;
}

int GetMaxScore()
{
	return score.topScore;
}

void DrawScore(sfRenderWindow* _renderWindow)
{
	sfRenderWindow_drawText(_renderWindow, score.score, NULL);
	//sfRenderWindow_drawText(_renderWindow, score.highScore, NULL);
}

void SetHighScore()
{
	if (score.actualScore > score.topScore)
	{
		score.topScore = score.actualScore;
		UpdateScoreText(score.highScore, score.topScore);
	}
}

void CleanupScore()
{
	sfFont_destroy(score.font);
	score.font = NULL;

	sfText_destroy(score.score);
	score.score = NULL;

	sfText_destroy(score.highScore);
	score.score = NULL;
}