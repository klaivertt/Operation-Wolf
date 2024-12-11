#ifndef GAME_OVER_H
#define GAME_OVER_H

#include "Common.h"
#include "State.h"
typedef struct GameOverData
{
	sfTexture* texture;
	sfSprite* sprite;
}GameOverData;

void LoadGameOver(void);
void KeyPressedGameOver(sfRenderWindow* _renderWindow, sfKeyEvent _key);
void MouseButtonPressedGameOver(sfRenderWindow* const _renderWindow, sfMouseButtonEvent _mouseButton);
void MouseMovedGameOver(sfRenderWindow* const _renderWindow, sfMouseMoveEvent _mouseMove);
void UpdateGameOver(float _dt);
void DrawGameOver(sfRenderWindow* _renderWindow);
void CleanupGameOver(void);

#endif // !GAME_OVER_H