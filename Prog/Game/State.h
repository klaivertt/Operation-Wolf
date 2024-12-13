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


 * @brief Sets the current game state.
 *
 * Updates the game's state to the specified value, which determines the
 * current phase of the game (e.g., menu, playing, paused, game over).
 *
 * @param _gameState The new game state to set.
 
void SetGameState(GameState _gameState);


 * @brief Gets the current game state.
 *
 * Returns the current state of the game, allowing other systems to
 * determine the active phase and act accordingly.
 *
 * @return The current GameState.

GameState GetGameState(void);


#endif // !STATE_H
