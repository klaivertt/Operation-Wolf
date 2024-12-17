#include "Score.h"

Score score;

void LoadScore()
{
	score.font = sfFont_createFromFile("Assets/Fonts/Prototype.ttf");
	score.score = sfText_create();
	score.highScore = sfText_create();

	sfText_setFont(score.score, score.font);;
	sfText_setFont(score.highScore, score.font);;
	
	sfText_setString(score.score, "0");
	sfText_setString(score.highScore, "0");
	
	sfText_setOutlineThickness(score.score, 2);
	sfText_setOutlineThickness(score.highScore, 2);
	
	sfText_setOutlineColor(score.score, sfBlack);
	sfText_setOutlineColor(score.highScore, sfBlack);
	
	sfText_setCharacterSize(score.score, 30);
	sfText_setCharacterSize(score.highScore, 30);

	sfFloatRect sizeActualScore = sfText_getGlobalBounds(score.score);
	sfFloatRect sizeHighScore = sfText_getGlobalBounds(score.highScore);

	sfText_setOrigin(score.score, (sfVector2f) { sizeActualScore.width / 2, sizeActualScore.height });
	sfText_setOrigin(score.highScore, (sfVector2f) { sizeHighScore.width / 2, sizeHighScore.height });

	sfText_setPosition(score.score, (sfVector2f) { SCREEN_WIDTH / 3, sizeActualScore.height });
	sfText_setPosition(score.highScore, (sfVector2f) { SCREEN_WIDTH / 2 + sizeActualScore.width * 20, sizeHighScore.height});

	score.actualScore = 0;
	score.topScore = 120;
}

void UpdateScoreText(sfText* _text, int _value)
{
	// Copy the value into the text
	char string[10];
	sprintf_s(string, sizeof(string), "%d", _value);
	sfText_setString(_text, string);
}

//add the ennemi score to the actual score
void UpdateScore(int _score)
{
	score.actualScore += _score;
	UpdateScoreText(score.score, score.actualScore);
	SetHighScore();
}

void DrawScore(sfRenderWindow* _renderWindow)
{
	sfRenderWindow_drawText(_renderWindow, score.score, NULL);
	sfRenderWindow_drawText(_renderWindow, score.highScore, NULL);
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