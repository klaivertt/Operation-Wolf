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

#define GROUND_RIGHT -100
#define GROUND_LEFT SCREEN_WIDTH + 100

#define ENEMY_MAX 6
#pragma endregion

typedef struct Image
{
	sfTexture* texture;
	sfSprite* sprite;

}Image;

typedef struct Buffer
{
	sfSoundBuffer* soundBuffer;
	sfSound* sound;
	float volume;
}Buffer;

#endif // !COMMON_H
