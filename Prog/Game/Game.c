#include "Game.h"

GameData gameData;

void LoadGame(void)
{
	printf("LOAD GAME\n");

	LoadGameMusic();
	LoadGameSounds();
	LoadMap();
	LoadEnemy(0, MOVING_ENEMY);
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
	UpdateHostage(_dt);
	UpdateMap(_dt);
	UpdateHUD(_dt);
	MoveDrop();
	UpdatePlayer(_dt);
}

void DrawGame(sfRenderWindow* _renderWindow)
{
	DrawMap(_renderWindow);
	DrawThirdPlan(_renderWindow);

	DrawDrop(_renderWindow);

	DrawHostage(_renderWindow, BACKGROUND);
	DrawEnemy(_renderWindow,MOVING_ENEMY, BACKGROUND);

	DrawHostage(_renderWindow, MIDDLEGROUND);
	DrawEnemy(_renderWindow, MOVING_ENEMY, MIDDLEGROUND);
	
	DrawProps(_renderWindow);

	DrawHostage(_renderWindow, FORGROUND);
	DrawEnemy(_renderWindow, MOVING_ENEMY, FORGROUND);
	DrawLayer2Props(_renderWindow);
	DrawSecondPlan(_renderWindow);

	DrawHUD(_renderWindow);
	DrawPlayer(_renderWindow);
}

void CleanupGame(void)
{
	CleanupGameMusic();
	CleanupGameSound();
	CleanupPlayer();
	CleanupEnemy(MOVING_ENEMY);
	CleanupMap();
	CleanupHUD();
	CleanupHostage();
	printf("CLEANUP GAME\n");
}

