#ifndef MENU_H
#define MENU_H

#include "../Libs/Common.h"
#include "../Libs/Animations.h"
#include "../Libs/Collision.h"
#include "../Libs/Text.h"
#include "../Libs/Utilities.h"
#include "../GameState.h"

#define MAX_BUTTONS 2

typedef struct Button
{
	sfRectangleShape* rect;
	sfText* text;
}Button;

typedef struct Menu
{
	Images background;
	Button buttons[MAX_BUTTONS];
	int currentButton;
}Menu;

void LoadMenu(void);
void OnKeyPressedMenu(sfKeyEvent _key, sfRenderWindow* const _render);
void UpdateMenu(float);
void DrawMenu(sfRenderWindow*);
void CleanMenu(void);

#endif