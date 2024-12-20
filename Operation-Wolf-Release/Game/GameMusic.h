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


//* @brief Loads the music resources for the game.
//*
//* This function initializes and prepares the background music or other audio tracks
//* associated with the game, loading them into memory for playback
void LoadGameMusic(void);


//* @brief Updates the game music based on the delta time.
//*
//* @param _dt The time elapsed (delta time) since the last frame. This can be used to
//*            control the music's playback or manage transitions (e.g., fading).
void UpdateGameMusic(float _dt);

//* @brief Frees the memory and resources associated with game music.
//*
//* This function ensures proper cleanup by deallocating any music resources (e.g.,
//* sound buffers or music instances) used in the game to prevent memory leaks.
void CleanupGameMusic(void);


//* @brief Changes the current game music track.
//*
//* This function restarts the music if the requested track is the same as the previous one.
//* It selects a new music track to be played based on the provided identifier.
//*
//* @param _mtp Enum or identifier representing the music track to be played.
void ChangeGameMusic(MusicToPlay _mtp);


//* @brief Changes the volume of the game music.
//*
//* @param _volume The desired volume level (a float value, typically between 0.0 and 1.0).
//* @param _instantaneous Boolean indicating whether the volume change should be immediate
//*                       (`sfTrue`) or gradually adjusted over time (`sfFalse`).
//* @return sfBool Returns `sfTrue` if the volume change was successfully applied, otherwise `sfFalse`.
sfBool ChangeGameMusicVolume(float _volume, sfBool _instantaneous);


#endif