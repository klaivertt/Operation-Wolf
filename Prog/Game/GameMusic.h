#pragma once
#ifndef GAMEMUSIC_H
#define GAMEMUSIC_H

#include "Common.h"
#include "State.h"
#include"EnemySound.h"

#define MAX_VOLUME 50
#define VOLUME_SPEED 20

typedef enum MusicToPlay
{
	WAVES,
	BOSS,
}MusicToPlay;

typedef struct BufferMusic
{
	sfSoundBuffer* waves;
	sfSoundBuffer* boss;
}BufferMusic;

typedef struct GameMusic
{
	
	BufferMusic soundBuffer;
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