#include "Common.h"
#include "State.h"
#include "Menu.h"
#include "Game.h"
#include "GameOver.h"
#include "Text.h"

#pragma region Struct
typedef struct MainData
{
	sfRenderWindow* renderWindow;
	sfClock* clock;

}MainData;
#pragma endregion

#pragma region GameLoop
void Load(MainData* const _mainData);
void PollEvent(MainData* const _mainData);
void KeyPressed(sfRenderWindow* const _renderWindow, sfKeyEvent _key);
void MouseButtonPressed(sfRenderWindow* const _renderWindow, sfMouseButtonEvent _mouseButtonEvent);
void MouseMoved(sfRenderWindow* const _renderWindow, sfMouseMoveEvent _mouseMove);
void Update(MainData* const _mainData);
void Draw(MainData* const _mainData);
void Cleanup(MainData* const _mainData);
#pragma endregion

#pragma region Functions
void LoadMainData(MainData* const _mainData);
void CleanupMainData(MainData* const _mainData);
#pragma endregion


int main(void)
{
	MainData mainData = { 0 };

	Load(&mainData);
	while (sfRenderWindow_isOpen(mainData.renderWindow))
	{
		PollEvent(&mainData);
		Update(&mainData);
		Draw(&mainData);
	}
	Cleanup(&mainData);

	//system("pause");
	return EXIT_SUCCESS;
}

void Load(MainData* const _mainData)
{
	srand(_getpid());

	LoadMainData(_mainData);
	LoadTextManager();
	SetGameState(MENU);
}

void PollEvent(MainData* const _mainData)
{
	sfEvent event;
	while (sfRenderWindow_pollEvent(_mainData->renderWindow, &event))
	{
		switch (event.type)
		{
		case sfEvtClosed:
			sfRenderWindow_close(_mainData->renderWindow);
			break;
		case sfEvtKeyPressed:

			KeyPressed(_mainData->renderWindow, event.key);
			break;
		case sfEvtMouseButtonPressed:
			MouseButtonPressed(_mainData->renderWindow, event.mouseButton);
			break;
		case sfEvtMouseMoved:
			MouseMoved(_mainData->renderWindow, event.mouseMove);
			break;
		default:
			break;
		}
	}
}

void KeyPressed(sfRenderWindow* const _renderWindow, sfKeyEvent _key)
{
	switch (GetGameState())
	{
	case MENU:
		KeyPressedMenu(_renderWindow, _key);
		break;
	case GAME:
		KeyPressedGame(_renderWindow, _key);
		break;
	case GAME_OVER:
		KeyPressedGameOver(_renderWindow, _key);
		break;
	default:
		break;
	}
}

void MouseButtonPressed(sfRenderWindow* const _renderWindow, sfMouseButtonEvent _mouseButton)
{
	switch (GetGameState())
	{
	case MENU:
		MouseButtonPressedMenu(_renderWindow, _mouseButton);
		break;
	case GAME:
		MouseButtonPressedGame(_renderWindow, _mouseButton);
		break;
	case GAME_OVER:
		MouseButtonPressedGameOver(_renderWindow, _mouseButton);
		break;
	default:
		break;
	}
}

void MouseMoved(sfRenderWindow* const _renderWindow, sfMouseMoveEvent _mouseMove)
{
	switch (GetGameState())
	{
	case MENU:
		MouseMovedMenu(_renderWindow, _mouseMove);
		break;
	case GAME:
		MouseMovedGame(_renderWindow, _mouseMove);
		break;
	case GAME_OVER:
		MouseMovedGameOver(_renderWindow, _mouseMove);
		break;
	default:
		break;
	}
}

void Update(MainData* const _mainData)
{
	float dt = sfTime_asSeconds(sfClock_restart(_mainData->clock));

	switch (GetGameState())
	{
	case MENU:
		UpdateMenu(dt);
		break;
	case GAME:
		UpdateGame(dt);
		break;
	case GAME_OVER:
		UpdateGameOver(dt);
		break;
	default:
		break;
	}
}

void Draw(MainData* const _mainData)
{
	sfRenderWindow_clear(_mainData->renderWindow, sfBlack);

	switch (GetGameState())
	{
	case MENU:
		DrawMenu(_mainData->renderWindow);
		break;
	case GAME:
		DrawGame(_mainData->renderWindow);
		break;
	case GAME_OVER:
		DrawGameOver(_mainData->renderWindow);
		break;
	default:
		break;
	}

	sfRenderWindow_display(_mainData->renderWindow);
}

void Cleanup(MainData* const _mainData)
{
	CleanupMainData(_mainData);

	switch (GetGameState())
	{
	case MENU:
		CleanupMenu();
		break;
	case GAME:
		CleanupGame();
		break;
	case GAME_OVER:
		CleanupGameOver();
		break;
	default:
		break;
	}
}

void LoadMainData(MainData* const _mainData)
{
	_mainData->clock = sfClock_create();
	sfVideoMode videoMode = { SCREEN_WIDTH, SCREEN_HEIGHT, BPP };
	_mainData->renderWindow = sfRenderWindow_create(videoMode, "Game", sfDefaultStyle, NULL);
	sfRenderWindow_setFramerateLimit(_mainData->renderWindow, 60);
	sfRenderWindow_setKeyRepeatEnabled(_mainData->renderWindow, sfFalse);
}

void CleanupMainData(MainData* const _mainData)
{
	sfClock_destroy(_mainData->clock);
	_mainData->clock = NULL;
	sfRenderWindow_destroy(_mainData->renderWindow);
	_mainData->renderWindow = NULL;
}
