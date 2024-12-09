#ifndef MAIN_H
#define MAIN_H

// D�pendance de base
#include <stdlib.h>
#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

// D�pendance de la CSFML
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>

// Define de base
#define SCREEN_W 1024
#define SCREEN_H 768

#define GAME_NAME "Operation Wolf "
#define GAME_VERSION "0.0.1"

#define MAX_FPS 120
#define VSYNC sfFalse


typedef struct Images
{
	sfTexture* texture;
	sfSprite* sprite;
}Images;

#endif
