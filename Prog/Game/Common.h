#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <process.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>

#pragma region Define
#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080
#define BPP 32

#define BACKGROUND 500
#define MIDDLEGROUND 850
#define FORGROUND 1000
#pragma endregion
typedef struct Image
{
	sfTexture* texture;
	sfSprite* sprite;

}Image;

#endif // !COMMON_H
