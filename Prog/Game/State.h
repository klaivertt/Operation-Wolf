#ifndef STATE_H
#define STATE_H

#pragma region Enum
typedef enum GameState
{
	MENU,
	GAME,
	GAME_OVER
}GameState;
#pragma endregion

void SetGameState(GameState _gameState);
GameState GetGameState(void);

#endif // !STATE_H
