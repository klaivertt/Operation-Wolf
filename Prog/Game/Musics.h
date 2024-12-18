#pragma once
#ifndef MUSIC_H
#define MUSIC_H

#include "Common.h"
#include "State.h"

#define MAX_VOLUME 100;
#define VOLUME_SPEED 10;

typedef enum MusicToPlay
{
	WAVES,
	BOSS,
}MusicToPlay;

typedef struct Buffer
{
	sfSoundBuffer* waves;
	sfSoundBuffer* boss;
}Buffer;

typedef struct GameMusic
{
	
	Buffer soundBuffer;
	sfSound* sound;

	float volume;

}GameMusic;

void LoadGameMusic(void);
void UpdateGameMusic(float _dt);
void CleanupGameMusic(void);

// restart music if it's the same then before
void ChangeGameMusic(MusicToPlay _mtp);
sfBool ChangeGameMusicVolume(float _volume, sfBool  _instantaneous);

#endif