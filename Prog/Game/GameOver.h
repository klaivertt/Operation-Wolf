#ifndef GAME_OVER_H
#define GAME_OVER_H

#include "Common.h"
#include "State.h"
#include "Score.h"

#define MAX_TEXT 3
typedef struct GameOverData
{
	sfTexture* texture;
	sfSprite* sprite;
	sfFont* font;
	sfText* gameOver;
	sfText* text[MAX_TEXT];
}GameOverData;


//* @brief Loads the game over resources.
//*
//* Initializes all necessary resources for the game over screen, such as loading textures,
//* setting up UI elements, and preparing other assets for rendering.
void LoadGameOver(void);


//* @brief Handles keyboard input during the game over screen.
//*
//* Processes key press events to perform actions such as navigating or retrying the game
//* when the game over screen is active.
//*
//* @param _renderWindow Pointer to the sfRenderWindow where the game over screen is displayed.
//* @param _key The key event containing information about the pressed key.
void KeyPressedGameOver(sfRenderWindow* _renderWindow, sfKeyEvent _key);


//* @brief Handles mouse button input during the game over screen.
//*
//* Processes mouse button press events to interact with the game over screen, such as
//* clicking to restart the game or exit.
//*
//* @param _renderWindow Pointer to the sfRenderWindow where the game over screen is displayed.
//* @param _mouseButton The mouse button event containing information about the click.
void MouseButtonPressedGameOver(sfRenderWindow* const _renderWindow, sfMouseButtonEvent _mouseButton);


//* @brief Handles mouse movement during the game over screen.
//*
//* Processes mouse movement events to update UI elements, such as hovering over buttons
//* or interactive components on the game over screen.
//*
//* @param _renderWindow Pointer to the sfRenderWindow where the game over screen is displayed.
//* @param _mouseMove The mouse move event containing information about the movement.
void MouseMovedGameOver(sfRenderWindow* const _renderWindow, sfMouseMoveEvent _mouseMove);


//* @brief Updates the game over screen state.
//*
//* This function updates dynamic elements of the game over screen, such as animations or effects,
//* based on the elapsed time.
//*
//* @param _dt Delta time (time elapsed since the last update).
void UpdateGameOver(float _dt);


//* @brief Draws the game over screen on the given render window.
//*
//* Renders all elements of the game over screen, including text, buttons, background, and any
//* other visual components.
//*
//* @param _renderWindow Pointer to the sfRenderWindow where the game over screen will be drawn.
void DrawGameOver(sfRenderWindow* _renderWindow);


//* @brief Cleans up the resources used by the game over screen.
//*
//* Releases all memory and resources allocated for the game over screen, such as textures,
//* sprites, and other dynamic data.
void CleanupGameOver(void);


#endif // !GAME_OVER_H