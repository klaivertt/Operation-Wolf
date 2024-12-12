#include "Score.h"

Score score;

void LoadScore()
{
	score.font = sfFont_createFromFile("Assets/Fonts/Prototype.ttf");
	score.text = sfText_create();
	sfText_setFont(score.text, score.font);

	sfVector2f position = { SCREEN_WIDTH / 3, SCREEN_HEIGHT / 3 };
	sfVector2f origin = { 0.5 , 1 };

	score.score = 0;
	score.highScore = 0;
}

void UpdateScore(sfText* const _text, int _value)
{
	// Copy the value into the text
	char string[6];
	sprintf_s(string, sizeof(string), "%d", _value);
	sfText_setString(_text, string);
}

//add the ennemi score to the actual score
void AddScore(int _score)
{
	score.score += _score;
}

void DrawScore(sfRenderWindow* _renderWindow)
{
	sfRenderWindow_drawText(_renderWindow, score.text, NULL);
}

void CleanupScore()
{
	sfFont_destroy(score.font);
	score.font = NULL;
}