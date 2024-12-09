#include "../Game/Libs/Common.h"

#include "GameState.h"

#include "../Game/Menu/Menu.h"
#include "../Game/Game/Game.h"
#include "../Game/Libs/Text.h"

#pragma region Enum�rations



#pragma endregion

#pragma region Structures

typedef struct MainData
{
	sfRenderWindow* renderWindow;
	sfClock* clock;
	float deltaTime;
}MainData;

typedef struct GameData
{
	int null;
}GameData;

#pragma endregion

#pragma region D�claration GameLoop
void Load(MainData* const, GameData* const _data);
void LoadScreen(MainData* const _data);
void LoadClock(MainData* const _data);

void PollEvent(sfRenderWindow* const _render, GameData* const _gameData);

void UpdateDeltaTime(MainData* const _data);

void Update(float _dt, MainData* const _data, GameData* const _gameData);

void Draw(sfRenderWindow* const _render, GameData* const _gameData);

void Cleanup(MainData* const _data, GameData* const _gameData);

void OnKeyPressed(sfKeyEvent _key, sfRenderWindow* const _render, GameData* const _gameData);

void OnMousePressed(sfMouseButtonEvent _button, sfRenderWindow* const _render, GameData* const _gameData);

void OnMouseMoved(sfMouseMoveEvent _mouse, GameData* const _gameData);
#pragma endregion

#pragma region GameLoop

int main(void)
{
	MainData mainData = { 0 };
	GameData gameData = { 0 };

	Load(&mainData, &gameData);

	// Game loop
	while (sfRenderWindow_isOpen(mainData.renderWindow))
	{
		// Gestion des �v�nements
		PollEvent(mainData.renderWindow, &gameData);

		// Appelle de la fonction Update, toutes les frames
		UpdateDeltaTime(&mainData);
		Update(mainData.deltaTime, &mainData, &gameData);

		// Appelle de la fonction Draw, toutes les frames
		sfRenderWindow_clear(mainData.renderWindow, sfColor_fromRGB(0, 0, 0));
		Draw(mainData.renderWindow, &gameData);
		sfRenderWindow_display(mainData.renderWindow);
	}

	// Cleanup
	Cleanup(&mainData, &gameData);

	return EXIT_SUCCESS;
}

void Load(MainData* const _data, GameData* const _game)
{
	LoadScreen(_data);
	LoadClock(_data);

	SetGameState(MENU);

	LoadTextManager();
	LoadGame();
	LoadMenu();
}

// Fonction qui cr�e la fen�tre et l'affiche
void LoadScreen(MainData* const _data)
{
	sfVideoMode mode = { SCREEN_W, SCREEN_H, 32 };
	_data->renderWindow = sfRenderWindow_create(mode, GAME_NAME, sfClose, NULL);
	sfRenderWindow_setFramerateLimit(_data->renderWindow, MAX_FPS);
	sfRenderWindow_setVerticalSyncEnabled(_data->renderWindow, VSYNC);
	sfRenderWindow_setKeyRepeatEnabled(_data->renderWindow, sfFalse);

	sfImage* image = sfImage_createFromFile("Assets/Icon.png");
	sfVector2u size = sfImage_getSize(image);
	sfRenderWindow_setIcon(_data->renderWindow, size.x, size.y, sfImage_getPixelsPtr(image));

	sfRenderWindow_setMouseCursorVisible(_data->renderWindow, sfFalse);
}

// Fonction qui charge la clock pour le DeltaTime
void LoadClock(MainData* const _data)
{
	_data->clock = sfClock_create();
}

void PollEvent(sfRenderWindow* const _render, GameData* const _game)
{
	sfEvent event;
	while (sfRenderWindow_pollEvent(_render, &event))
	{
		switch (event.type)
		{
		case sfEvtClosed:
			sfRenderWindow_close(_render);
			break;
		case sfEvtKeyPressed:
			OnKeyPressed(event.key, _render, _game);
			break;
		case sfEvtMouseButtonPressed:
			OnMousePressed(event.mouseButton, _render ,_game);
			break;
		case sfEvtMouseMoved:
			OnMouseMoved(event.mouseMove, _game);
			break;
		default:
			break;
		}
	}
}

void UpdateDeltaTime(MainData* const _mainData)
{
	_mainData->deltaTime = sfTime_asSeconds(sfClock_restart(_mainData->clock));
}

void Update(float _dt, MainData* const _data, GameData* const _game)
{
	enum GameState state = GetGameState();

	switch (state)
	{
	case MENU:
		break;
	case GAME:
		UpdateGame(_dt, _data->renderWindow);
		break;
	default:
		break;
	}

}

void Draw(sfRenderWindow* const _render, GameData* const _game)
{
	enum GameState state = GetGameState();

	switch (state)
	{
	case MENU:
		DrawMenu(_render);
		break;
	case GAME:
		DrawGame(_render);
		break;
	default:
		break;
	}
}

void Cleanup(MainData* const _data, GameData* const _game)
{
	sfRenderWindow_destroy(_data->renderWindow);
	sfClock_destroy(_data->clock);

	_data->renderWindow = NULL;
	_data->clock = NULL;

	CleanMenu();
}

void OnKeyPressed(sfKeyEvent _key, sfRenderWindow* const _render, GameData* const _game)
{
	enum GameState state = GetGameState();

	switch (state)
	{
	case MENU:
		OnKeyPressedMenu(_key, _render);
		break;
	case GAME:
		OnKeyPressedGame(_key, _render);
		break;
	default:
		break;
	}
}

void OnMousePressed(sfMouseButtonEvent _mouse, sfRenderWindow* const _render, GameData* const _game)
{
	enum GameState state = GetGameState();

	switch (state)
	{
	case MENU:
		break;
	case GAME:
		OnMousePressedGame(_mouse, _render);
		break;
	default:
		break;
	}
}

void OnMouseMoved(sfMouseMoveEvent _mouse, GameData* const _game)
{
	enum GameState state = GetGameState();

	switch (state)
	{
	case MENU:
		break;
	case GAME:
		break;
	default:
		break;
	}
}

#pragma endregion
