#pragma once
#ifndef MENUMUSIC_H
#define MENUMUSIC_H

#include "Common.h"
#include "State.h"

#define MAX_VOLUME 100
#define VOLUME_SPEED 20

typedef struct MenuMusic
{

	sfSoundBuffer* soundBuffer;
	sfSound* sound;

	float volume;

}MenuMusic;

void LoadMenuMusic(void);
void UpdateMenuMusic(float _dt);
void CleanupMenuMusic(void);

sfBool ChangeMenuMusicVolume(float _volume, sfBool  _instantaneous);

#endif