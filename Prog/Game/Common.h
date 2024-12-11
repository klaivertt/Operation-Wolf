#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <process.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>

#pragma region Define
#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768
#define BPP 32
#pragma endregion

typedef struct Image
{
	sfTexture* texture;
	sfSprite* sprite;

}Image;

typedef enum Character
{
	PLAYER,
	DEALER,
}Character;

#endif // !COMMON_H
