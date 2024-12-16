#include "GameOver.h"

GameOverData data = { 0 };

void LoadGameOver(void)
{
	printf("LOAD GAME OVER\n");
	data.font = sfFont_createFromFile("Assets/Fonts/Prototype.ttf");

	data.gameOver = sfText_create();
	sfText_setCharacterSize(data.gameOver, 145);
	sfText_setFont(data.gameOver, data.font);

	char buffer[11];
	snprintf(buffer, sizeof(buffer), "Game Over");
	sfText_setString(data.gameOver, buffer);

	sfFloatRect gameOverSize = sfText_getGlobalBounds(data.gameOver);
	sfText_setOrigin(data.gameOver, (sfVector2f) { (float)gameOverSize.width / 2, gameOverSize.height / 2 });

	sfVector2f gameOverPosition = { SCREEN_WIDTH / 2 , SCREEN_HEIGHT * 0.2f };
	sfText_setPosition(data.gameOver, gameOverPosition);
	
	data.text[0] = sfText_create();
	data.text[1] = sfText_create();
	data.text[2] = sfText_create();

	// Définir les propriétés des textes
	sfText_setFont(data.text[0], data.font);
	sfText_setFont(data.text[1], data.font);
	sfText_setFont(data.text[2], data.font);

	sfText_setCharacterSize(data.text[0], 35);
	sfText_setCharacterSize(data.text[1], 35);
	sfText_setCharacterSize(data.text[2], 35);

	sfText_setString(data.text[0], "Press 'Space' to restart");
	sfText_setString(data.text[1], "or");
	sfText_setString(data.text[2], "'Escape' to quit");

	// Centrer chaque ligne horizontalement
	sfFloatRect bounds1 = sfText_getGlobalBounds(data.text[0]);
	sfFloatRect bounds2 = sfText_getGlobalBounds(data.text[1]);
	sfFloatRect bounds3 = sfText_getGlobalBounds(data.text[2]);

	sfText_setOrigin(data.text[0], (sfVector2f) { bounds1.width / 2, bounds1.height / 2 });
	sfText_setOrigin(data.text[1], (sfVector2f) { bounds2.width / 2, bounds2.height / 2 });
	sfText_setOrigin(data.text[2], (sfVector2f) { bounds3.width / 2, bounds3.height / 2 });

	// Calcul des positions (espacement vertical)
	sfText_setPosition(data.text[0], (sfVector2f) { SCREEN_WIDTH / 2, SCREEN_HEIGHT * 0.4f - 45 });
	sfText_setPosition(data.text[1], (sfVector2f) { SCREEN_WIDTH / 2, SCREEN_HEIGHT * 0.4f - 10});
	sfText_setPosition(data.text[2], (sfVector2f) { SCREEN_WIDTH / 2, SCREEN_HEIGHT * 0.4f + 45 });
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
