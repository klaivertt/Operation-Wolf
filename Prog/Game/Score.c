#include "Score.h"

Score score;

void LoadScore()
{
	score.font = sfFont_createFromFile("Assets/Fonts/Prototype.ttf");
	score.score = sfText_create();

	sfText_setFont(score.score, score.font);;

	sfText_setString(score.score, "00000");

	sfText_setOutlineThickness(score.score, 2);


	sfText_setOutlineColor(score.score, sfBlack);


	sfText_setCharacterSize(score.score, 30);


	sfFloatRect sizeActualScore = sfText_getGlobalBounds(score.score);


	sfText_setOrigin(score.score, (sfVector2f) { sizeActualScore.width / 2, sizeActualScore.height });


	sfText_setPosition(score.score, (sfVector2f) { SCREEN_WIDTH / 2, SCREEN_HEIGHT * 0.2f });

	score.actualScore = 0;
}

void UpdateScore()
{
	// Copy the value into the text
	printf("_value = %d\n", score.actualScore);
	char string[6];
	sprintf_s(string, sizeof(string), "%d", score.actualScore);
	sfText_setString(score.score, string);
}

//add the ennemi score to the actual score
void AddScore(int _score)
{
	score.actualScore += _score;
}

void DrawScore(sfRenderWindow* _renderWindow)
{
	sfRenderWindow_drawText(_renderWindow, score.score, NULL);
}

void CleanupScore()
{
	sfFont_destroy(score.font);
	score.font = NULL;

	sfText_destroy(score.score);
	score.score = NULL;
}