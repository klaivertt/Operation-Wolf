#include "GameOver.h"

void LoadGameOver(void)
{
	printf("LOAD GAME OVER\n");
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
}

void CleanupGameOver(void)
{
	printf("CLEANUP GAME OVER\n");
}
