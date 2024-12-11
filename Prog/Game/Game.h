#ifndef GAME_H
#define GAME_H

#include "Common.h"
#include "State.h"
#include "Player.h"
#include "Map.h"

typedef struct Enemy
{
	sfSprite* anim[];


}Enemy;


typedef struct GameData
{
	Image background;
	
}GameData;

void LoadGame(void);
void KeyPressedGame(sfRenderWindow* _renderWindow, sfKeyEvent _key);
void MouseButtonPressedGame(sfRenderWindow* const _renderWindow, sfMouseButtonEvent _mouseButton);
void MouseMovedGame(sfRenderWindow* const _renderWindow, sfMouseMoveEvent _mouseMove);
void UpdateGame(float _dt);
void DrawGame(sfRenderWindow* _renderWindow);
void CleanupGame(void);

#endif // !GAME_H