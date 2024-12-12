#include "Game.h"

GameData gameData;

void LoadGame(void)
{
	printf("LOAD GAME\n");

	LoadMap();
	LoadEnemy();
	LoadHUD();
	LoadPlayer();
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
	
}

void MouseMovedGame(sfRenderWindow* const _renderWindow, sfMouseMoveEvent _mouseMove)
{
	GetMousePositionPlayer(_mouseMove);
}

void UpdateGame(float _dt)
{
	UpdatePlayer(_dt);
	UpdateEnemy(_dt);
	UpdateMap(_dt);
}

void DrawGame(sfRenderWindow* _renderWindow)
{
	DrawMap(_renderWindow);
	DrawThirdPlan(_renderWindow);
	DrawSecondPlan(_renderWindow);
	DrawFistPlan(_renderWindow);
	DrawEnemy(_renderWindow);
	DrawHUD(_renderWindow);
	DrawPlayer(_renderWindow);
}

void CleanupGame(void)
{
	CleanupPlayer();
	CleanupMap();
	CleanupHUD();
	printf("CLEANUP GAME\n");
}

