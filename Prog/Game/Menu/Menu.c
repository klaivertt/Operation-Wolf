#include "Menu.h"
#include "../Libs/Collision.h"
#include "../Libs/Text.h"
#include "../Libs/Utilities.h"
#include "../GameState.h"
Menu menu = { 0 };

void LoadMenuBackground(void);
void DrawMenuBackground(sfRenderWindow*);

void LoadMenuButton(void);
void ButtonChangeState(sfRenderWindow* const _render);
void UpdateMenuButton(float);
void DrawMenuButton(sfRenderWindow*);

#pragma region GameLoop

void LoadMenu(void)
{
	LoadMenuBackground();
	LoadMenuButton();
}


void OnKeyPressedMenu(sfKeyEvent _key, sfRenderWindow* const _render)
{
	switch (_key.code)
	{
	case sfKeyZ:
		menu.currentButton--;
		if (menu.currentButton < 0)
		{
			menu.currentButton = MAX_BUTTONS - 1;
		}
		break;
	case sfKeyS:
		menu.currentButton++;
		if (menu.currentButton > MAX_BUTTONS - 1)
		{
			menu.currentButton = 0;
		}
		break;
	case sfKeyUp:
		menu.currentButton--;
		if (menu.currentButton < 0)
		{
			menu.currentButton = MAX_BUTTONS - 1;
		}
		break;
	case sfKeyDown:
		menu.currentButton++;
		if (menu.currentButton > MAX_BUTTONS - 1)
		{
			menu.currentButton = 0;
		}
		break;
	case sfKeySpace:
		ButtonChangeState(_render);
		break;
	case sfKeyEnter:
		ButtonChangeState(_render);
		break;
	default:
		break;
	}
}

void UpdateMenu(float _dt)
{
	UpdateMenuButton(_dt);
}

void DrawMenu(sfRenderWindow* _render)
{
	DrawMenuBackground(_render);
	DrawMenuButton(_render);
}

void CleanMenu(void)
{
}

#pragma endregion

#pragma region Background
void LoadMenuBackground(void)
{

}

void DrawMenuBackground(sfRenderWindow* _render)
{

}

#pragma endregion

#pragma region Buttons

void LoadMenuButton(void)
{
	menu.currentButton = 0;

	InitText(&menu.buttons[0].text, "Play", 40, (sfVector2f) { SCREEN_W / 2, SCREEN_H * 0.2 });
	sfFloatRect bound = sfText_getGlobalBounds(menu.buttons[0].text);
	sfText_setOrigin(menu.buttons[0].text, (sfVector2f) { bound.width / 2, bound.height / 2 });

	InitText(&menu.buttons[1].text, "Quit", 40, (sfVector2f) { SCREEN_W / 2, SCREEN_H * 0.4 });
	bound = sfText_getGlobalBounds(menu.buttons[1].text);
	sfText_setOrigin(menu.buttons[1].text, (sfVector2f) { bound.width / 2, bound.height / 2 });

	for (size_t i = 0; i < MAX_BUTTONS; i++)
	{
		float padding = 20.0f;
		bound = sfText_getGlobalBounds(menu.buttons[i].text);
		sfVector2f pos = sfText_getPosition(menu.buttons[i].text);

		printf("w: %.2f h: %.2f\n", bound.width, bound.height);

		CreateRect(&menu.buttons[i].rect, (sfVector2f) { bound.width + padding, bound.height + padding }, pos, sfColor_fromRGB(255, 255, 255), sfTrue);

		SetRectOrigin(&menu.buttons[i].rect, (sfVector2f) { 2, 2.5f });
	}
}


void ButtonChangeState(sfRenderWindow* const _render)
{
	switch (menu.currentButton)
	{
	case 0:
		SetGameState(GAME);
		break;
	case 1:
		sfRenderWindow_close(_render);
		break;
	default:
		break;
	}
}

void UpdateMenuButton(float _dt)
{
}

void DrawMenuButton(sfRenderWindow* _render)
{
	for (size_t i = 0; i < MAX_BUTTONS; i++)
	{
		sfRenderWindow_drawText(_render, menu.buttons[i].text, NULL);
	}

	sfRenderWindow_drawRectangleShape(_render, menu.buttons[menu.currentButton].rect, NULL);
}

#pragma endregion