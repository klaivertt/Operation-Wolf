#include "Game.h"

GameData gameData;

void LoadGame(void)
{
	printf("LOAD GAME\n");

	//Background
	gameData.background.sprite = sfSprite_create();
	gameData.background.texture = sfTexture_createFromFile("Assets/Sprites/Backgrounds/Game.png", NULL);

	sfSprite_setTexture(gameData.background.sprite, gameData.background.texture, sfTrue);

	sfVector2f position = { 0,SCREEN_HEIGHT };
	sfFloatRect globalBounds = sfSprite_getGlobalBounds(gameData.background.sprite);

	sfSprite_setOrigin(gameData.background.sprite, (sfVector2f) { 0, globalBounds.height });
	sfSprite_setPosition(gameData.background.sprite, position);

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
	UpdateMap(_dt);
}

void DrawGame(sfRenderWindow* _renderWindow)
{
	sfRenderWindow_drawSprite(_renderWindow, gameData.background.sprite, NULL);
	DrawMap(_renderWindow);
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

