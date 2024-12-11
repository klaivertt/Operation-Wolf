#include "State.h"
#include "Menu.h"
#include "Game.h"
#include "GameOver.h"

GameState gameState;

void SetGameState(GameState _gameState)
{
	switch (gameState)
	{
	case GAME:

		CleanupGame();
		break;

	case MENU:

		CleanupMenu();
		break;

	case GAME_OVER:

		CleanupGameOver();
		break;
	}

    gameState = _gameState;

	switch (gameState)
	{
	case GAME:

		LoadGame();
		break;

	case MENU:

		LoadMenu();
		break;

	case GAME_OVER:

		LoadGameOver();
		break;
	}
}

GameState GetGameState(void)
{
    return gameState;
}
