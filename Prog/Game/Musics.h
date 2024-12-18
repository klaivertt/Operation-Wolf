#pragma once
#ifndef MUSICS_H
#define MUSICS_H

#include "Common.h"
#include "State.h"

#define SPEED_VOLUME 10;

typedef struct Music
{
	sfSoundBuffer* soundBuffer;
	sfSound* sound;

	float volume;

}Music;

void LoadMusic(void);
void UpdateVolume(float _dt);
void CleanupMusic(void);

#endif