#include "GameOver.h"

GameOverData data = { 0 };

void LoadGameOver(void)
{
	printf("LOAD GAME OVER\n");

	InitText(&data.gameOver, "Game Over", 145, (sfVector2f) { SCREEN_WIDTH / 2, SCREEN_HEIGHT * 0.2f });

	sfFloatRect gameOverSize = sfText_getGlobalBounds(data.gameOver);
	sfText_setOrigin(data.gameOver, (sfVector2f) { (float)gameOverSize.width / 2, gameOverSize.height / 2 });

	InitText(&data.text[0], "Press 'Space' to restart", 35, (sfVector2f) { SCREEN_WIDTH / 2, SCREEN_HEIGHT * 0.4f - 45 });
	InitText(&data.text[1], "or", 35, (sfVector2f) { SCREEN_WIDTH / 2, SCREEN_HEIGHT * 0.4f - 10 });
	InitText(&data.text[2], "'Escape' to quit", 35, (sfVector2f) { SCREEN_WIDTH / 2, SCREEN_HEIGHT * 0.4f + 45 });

	// Centrer chaque ligne horizontalement
	sfFloatRect bounds1 = sfText_getGlobalBounds(data.text[0]);
	sfFloatRect bounds2 = sfText_getGlobalBounds(data.text[1]);
	sfFloatRect bounds3 = sfText_getGlobalBounds(data.text[2]);

	sfText_setOrigin(data.text[0], (sfVector2f) { bounds1.width / 2, bounds1.height / 2 });
	sfText_setOrigin(data.text[1], (sfVector2f) { bounds2.width / 2, bounds2.height / 2 });
	sfText_setOrigin(data.text[2], (sfVector2f) { bounds3.width / 2, bounds3.height / 2 });
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
	sfRenderWindow_drawText(_renderWindow, data.gameOver, NULL);
	for (size_t i = 0; i < MAX_TEXT; i++)
	{
		sfRenderWindow_drawText(_renderWindow, data.text[i], NULL);
	}
	//DrawScore(_renderWindow);
}

void CleanupGameOver(void)
{
	printf("CLEANUP GAME OVER\n");
}
