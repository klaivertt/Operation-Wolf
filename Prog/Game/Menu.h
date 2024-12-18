#ifndef MENU_H
#define MENU_H

#include "Common.h"
#include "State.h"
#include "Sprite.h"
#include "MenuMusic.h"

typedef struct UserInterface
{

	sfTexture* textureWhiteButton;

	sfSprite* playButtonSprite;
	sfSprite* exitButtonSprite;

}UserInterface;

typedef struct MenuData
{
	Image background;
	UserInterface userInterface;

}MenuData;


//* @brief Loads the menu resources.
//*
//* Initializes all necessary resources for the main menu, such as loading textures,
//* setting up UI elements, and preparing other assets for rendering.

void LoadMenu(void);


//* @brief Handles keyboard input in the menu.
//*
//* Processes key press events to perform actions in the menu, such as navigating through
//* options or selecting items.
//*
//* @param _renderWindow Pointer to the sfRenderWindow where the menu is displayed.
//* @param _key The key event containing information about the pressed key.
void KeyPressedMenu(sfRenderWindow* _renderWindow, sfKeyEvent _key);


//* @brief Handles mouse button input in the menu.
//*
//* Processes mouse button press events to interact with the menu, such as clicking on buttons
//* or selecting options.
//*
//* @param _renderWindow Pointer to the sfRenderWindow where the menu is displayed.
//* @param _mouseButtonEvent The mouse button event containing information about the click.
void MouseButtonPressedMenu(sfRenderWindow* const _renderWindow, sfMouseButtonEvent _mouseButtonEvent);


//* @brief Handles mouse movement in the menu.
//*
//* Processes mouse movement events to update UI elements, such as hovering over buttons
//* or other interactive menu components.
//*
//* @param _renderWindow Pointer to the sfRenderWindow where the menu is displayed.
//* @param _mouseMove The mouse move event containing information about the movement.
void MouseMovedMenu(sfRenderWindow* const _renderWindow, sfMouseMoveEvent _mouseMove);


//* @brief Updates the menu state.
//*
//* This function updates any dynamic behaviors in the menu, such as animations, transitions,
//* or input handling.
//*
//* @param _dt Delta time (time elapsed since the last update).
void UpdateMenu(float _dt);


//* @brief Draws the menu on the given render window.
//*
//* Renders all elements of the menu, including buttons, text, background, and other UI components.
//*
//* @param _renderWindow Pointer to the sfRenderWindow where the menu will be drawn.
void DrawMenu(sfRenderWindow* _renderWindow);


//* @brief Cleans up the menu resources.
//*
//* Releases all memory and resources allocated for the menu, such as textures,
//* sprites, and other dynamic data.
void CleanupMenu(void);


#endif // !MENU_H
