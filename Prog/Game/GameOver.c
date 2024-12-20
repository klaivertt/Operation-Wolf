#include "GameOver.h"

GameOverData data = { 0 };

void LoadGameOver(void)
{
	LoadGameOverSounds();
	PlaySound_PlayerDeath();

	//Background
	data.background.sprite = sfSprite_create();

	data.background.texture = sfTexture_createFromFile("Assets/Sprites/GameOverBackground(prog).png", NULL);

	sfSprite_setTexture(data.background.sprite, data.background.texture, sfTrue);

	sfVector2f position = { 0,SCREEN_HEIGHT };
	sfFloatRect globalBounds = sfSprite_getGlobalBounds(data.background.sprite);

	sfSprite_setOrigin(data.background.sprite, (sfVector2f) { 0, globalBounds.height });
	sfSprite_setPosition(data.background.sprite, position);


	sfVector2f screen = { SCREEN_WIDTH,SCREEN_HEIGHT };


	data.gameOver = InitText("Game Over", 145, (sfVector2f) { SCREEN_WIDTH / 2, SCREEN_HEIGHT * 0.2f });

	sfFloatRect gameOverSize = sfText_getGlobalBounds(data.gameOver);
	sfText_setOrigin(data.gameOver, (sfVector2f) { (float)gameOverSize.width / 2, gameOverSize.height / 2 });

	data.text[0] = InitText("Press 'Space' to restart", 35, (sfVector2f) { SCREEN_WIDTH / 2, SCREEN_HEIGHT * 0.4f - 45 });
	data.text[1] = InitText("or", 35, (sfVector2f) { SCREEN_WIDTH / 2, SCREEN_HEIGHT * 0.4f - 10 });
	data.text[2] = InitText("'Escape' to return Menu", 35, (sfVector2f) { SCREEN_WIDTH / 2, SCREEN_HEIGHT * 0.4f + 45 });

	// Centrer chaque ligne horizontalement
	sfFloatRect bounds1 = sfText_getGlobalBounds(data.text[0]);
	sfFloatRect bounds2 = sfText_getGlobalBounds(data.text[1]);
	sfFloatRect bounds3 = sfText_getGlobalBounds(data.text[2]);

	sfText_setOrigin(data.text[0], (sfVector2f) { bounds1.width / 2, bounds1.height / 2 });
	sfText_setOrigin(data.text[1], (sfVector2f) { bounds2.width / 2, bounds2.height / 2 });
	sfText_setOrigin(data.text[2], (sfVector2f) { bounds3.width / 2, bounds3.height / 2 });

	data.score = InitTextWithValue("Score : %d", GetScore(), 30, (sfVector2f) { SCREEN_WIDTH / 2, SCREEN_HEIGHT * 0.70f });
	data.maxScore = InitTextWithValue("Max Score : %d", GetMaxScore(), 30, (sfVector2f) { SCREEN_WIDTH / 2, SCREEN_HEIGHT * 0.73f });

	sfFloatRect scoreBounds = sfText_getGlobalBounds(data.score);
	sfFloatRect maxScoreBounds = sfText_getGlobalBounds(data.maxScore);

	sfText_setOrigin(data.score, (sfVector2f) { scoreBounds.width / 2, scoreBounds.height / 2 });
	sfText_setOrigin(data.maxScore, (sfVector2f) { maxScoreBounds.width / 2, maxScoreBounds.height / 2 });
}

void KeyPressedGameOver(sfRenderWindow* _renderWindow, sfKeyEvent _key)
{
	switch (_key.code)
	{
	case sfKeyEscape:
		SetGameState(MENU);
		break;
	case sfKeySpace:
		SetGameState(GAME);
		break;
	default:
		break;
	}
}

void MouseButtonPressedGameOver(sfRenderWindow* const _renderWindow, sfMouseButtonEvent _mouseButton)
{

}

void MouseMovedGameOver(sfRenderWindow* const _renderWindow, sfMouseMoveEvent _mouseMove)
{

}

void UpdateGameOver(float _dt)
{
}

void DrawGameOver(sfRenderWindow* _renderWindow)
{
	sfRenderWindow_drawSprite(_renderWindow, data.background.sprite, NULL);

	sfRenderWindow_setMouseCursorVisible(_renderWindow, sfTrue);

	sfRenderWindow_drawText(_renderWindow, data.gameOver, NULL);
	for (size_t i = 0; i < MAX_TEXT; i++)
	{
		sfRenderWindow_drawText(_renderWindow, data.text[i], NULL);
	}
	sfRenderWindow_drawText(_renderWindow, data.score, NULL);
	sfRenderWindow_drawText(_renderWindow, data.maxScore, NULL);
}

void CleanupGameOver(void)
{
	sfText_destroy(data.gameOver);
	data.gameOver = NULL;

	sfText_destroy(data.maxScore);
	data.maxScore = NULL;

	sfText_destroy(data.score);
	data.score = NULL;

	for (short i = 0; i < MAX_TEXT; i++)
	{
		sfText_destroy(data.text[i]);
		data.text[i] = NULL;
	}

	//Background
	sfSprite_destroy(data.background.sprite);
	data.background.sprite = NULL;

	sfTexture_destroy(data.background.texture);
	data.background.texture = NULL;
}
