#include "Game.h"

GameData gameData;

void LoadGame(void)
{
	printf("LOAD GAME\n");

	LoadMap();
	LoadEnemies(NULL);
	LoadHostage(NULL);
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
	UpdatePlayer(_dt);
	UpdateEnemy(_dt);
	UpdateHostage(_dt);
	UpdateMap(_dt);
	UpdateHUD(_dt);
	//MoveDrop();
}

void DrawGame(sfRenderWindow* _renderWindow)
{
	DrawMap(_renderWindow);
	DrawThirdPlan(_renderWindow);

	DrawHostage(_renderWindow, BACKGROUND);
	DrawEnemy(_renderWindow, BACKGROUND);

	DrawHostage(_renderWindow, MIDDLEGROUND);
	DrawEnemy(_renderWindow, MIDDLEGROUND);
	
	DrawProps(_renderWindow);

	DrawHostage(_renderWindow, FORGROUND);
	DrawEnemy(_renderWindow, FORGROUND);
	DrawLayer2Props(_renderWindow);
	DrawSecondPlan(_renderWindow);

	DrawHUD(_renderWindow);
	DrawDrop(_renderWindow);
	DrawPlayer(_renderWindow);
}

void CleanupGame(void)
{
	CleanupPlayer();
	CleanupMap();
	CleanupHUD();
	CleanupHostage();
	printf("CLEANUP GAME\n");
}

