#include "Game.h"

GameData gameData;

void LoadGame(void)
{
	LoadGameMusic();
	LoadGameSounds();
	LoadMap();
	LoadEnemy(0, MOVING_ENEMY);
	LoadEnemy(0, FRONT_ENEMY);
	LoadHostage(0);
	LoadPlayer();
	LoadHUD();
	LoadDrop();
}

void KeyPressedGame(sfRenderWindow* _renderWindow, sfKeyEvent _key)
{
	switch (_key.code)
	{
	case sfKeyEscape:
		SetGameState(MENU);
		break;
	case sfKeySpace:
		SetGameState(GAME_OVER);
		break;
	default:
		break;
	}
}

void MouseButtonPressedGame(sfRenderWindow* const _renderWindow, sfMouseButtonEvent _mouseButton)
{
	MouseButtonPressedPlayer(_renderWindow, _mouseButton);
}

void MouseMovedGame(sfRenderWindow* const _renderWindow, sfMouseMoveEvent _mouseMove)
{
	GetMousePositionPlayer(_mouseMove);
}

void UpdateGame(float _dt)
{
	UpdateGameMusic(_dt);
	UpdateEnemy(_dt, MOVING_ENEMY);
	UpdateEnemy(_dt, FRONT_ENEMY);
	UpdateHostage(_dt);
	UpdateMap(_dt);
	UpdateHUD(_dt);
	UpdateDrop(_dt);
	UpdatePlayer(_dt);

	if (IsPlayerDead())
	{
		SetGameState(GAME_OVER);
	}
}

void DrawGame(sfRenderWindow* _renderWindow)
{
	sfRenderWindow_setMouseCursorVisible(_renderWindow, sfFalse);

	DrawMap(_renderWindow);
	DrawThirdPlan(_renderWindow);

	DrawDrop(_renderWindow);
	
	DrawEnemy(_renderWindow,MOVING_ENEMY, BACKGROUND);
	DrawHostage(_renderWindow, BACKGROUND);


	DrawEnemy(_renderWindow, MOVING_ENEMY, MIDDLEGROUND);
	DrawHostage(_renderWindow, MIDDLEGROUND);
	
	DrawProps(_renderWindow, MIDDLEGROUND);

	DrawEnemy(_renderWindow, MOVING_ENEMY, FORGROUND);
	DrawHostage(_renderWindow, FORGROUND);
	DrawProps(_renderWindow, FORGROUND);
	DrawSecondPlan(_renderWindow);
	
	DrawEnemy(_renderWindow, FRONT_ENEMY, 0);

	DrawHUD(_renderWindow);
	DrawPlayer(_renderWindow);
}

void CleanupGame(void)
{
	CleanupGameMusic();
	CleanupGameSound();
	CleanupPlayer();
	CleanupEnemy(MOVING_ENEMY);
	CleanupEnemy(FRONT_ENEMY);
	CleanupMap();
	CleanupHUD();
	CleanupHostage();
}

