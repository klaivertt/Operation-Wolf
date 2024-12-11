#ifndef MENU_H
#define MENU_H

#include "Common.h"
#include "State.h"
#include "Sprite.h"


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

void LoadMenu(void);
void KeyPressedMenu(sfRenderWindow* _renderWindow, sfKeyEvent _key);
void MouseButtonPressedMenu(sfRenderWindow* const _renderWindow, sfMouseButtonEvent _mouseButtonEvent);
void MouseMovedMenu(sfRenderWindow* const _renderWindow, sfMouseMoveEvent _mouseMove);
void UpdateMenu(float _dt);
void DrawMenu(sfRenderWindow* _renderWindow);
void CleanupMenu(void);

#endif // !MENU_H
