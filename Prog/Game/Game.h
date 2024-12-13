#ifndef GAME_H
#define GAME_H

#include "Common.h"
#include "State.h"
#include "Player.h"
#include "Enemy.h"
#include "Map.h"


typedef struct GameData
{
	Image background;

}GameData;


//* @brief Loads the game resources.
//*
//* Initializes the game state, including loading assets, setting up levels,
//* and preparing all required game systems.
void LoadGame(void);


//* @brief Handles keyboard input in the game.
//*
//* Processes a key press event to perform specific actions in the game,
//* such as character movement or triggering gameplay mechanics.
//*
//* @param _renderWindow Pointer to the sfRenderWindow where the game is running.
//* @param _key The key event containing information about the pressed key.
void KeyPressedGame(sfRenderWindow* _renderWindow, sfKeyEvent _key);

//* @brief Handles mouse button input in the game.
//*
//* Processes a mouse button press event to interact with the game,
//* such as clicking on objects or triggering actions.
//*
//* @param _renderWindow Pointer to the sfRenderWindow where the game is running.
//* @param _mouseButton The mouse button event containing information about the click.
void MouseButtonPressedGame(sfRenderWindow* const _renderWindow, sfMouseButtonEvent _mouseButton);


//* @brief Handles mouse movement in the game.
//*
//* Processes a mouse movement event to update game elements,
//* such as cursor tracking or UI hover effects.
//*
//* @param _renderWindow Pointer to the sfRenderWindow where the game is running.
//* @param _mouseMove The mouse move event containing information about the movement.
void MouseMovedGame(sfRenderWindow* const _renderWindow, sfMouseMoveEvent _mouseMove);


//* @brief Updates the game state.
//*
//* Updates game logic, animations, physics, and other dynamic behaviors.
//* This function should be called every frame.
//*
//* @param _dt Delta time (time elapsed since the last update).
void UpdateGame(float _dt);


//* @brief Draws the game on the given render window.
//*
//* Renders all game elements, including the player, environment, UI, and other visuals.
//*
//* @param _renderWindow Pointer to the sfRenderWindow where the game will be drawn.
void DrawGame(sfRenderWindow* _renderWindow);


//* @brief Cleans up the game resources.
//*
//* Frees memory and releases resources allocated for the game, such as textures,
//* sprites, and other dynamic data. This function should be called when exiting the game.
void CleanupGame(void);


#endif // !GAME_H