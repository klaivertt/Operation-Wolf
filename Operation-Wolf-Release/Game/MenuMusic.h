#pragma once
#ifndef MENUMUSIC_H
#define MENUMUSIC_H

#include "Common.h"
#include "State.h"

#define MAX_VOLUME 50
#define VOLUME_SPEED 20

typedef struct MenuMusic
{

	sfSoundBuffer* soundBuffer;
	sfSound* sound;

	float volume;

}MenuMusic;

//* @brief Loads the music resources for the menu.
//*
//* This function initializes and prepares the background music or other audio tracks
//* associated with the menu, loading them into memory for playback.

void LoadMenuMusic(void);


//* @brief Updates the menu music based on the delta time.
//*
//* @param _dt The time elapsed (delta time) since the last frame. This can be used to
//*            control the music's playback or manage transitions (e.g., fading).

void UpdateMenuMusic(float _dt);


//* @brief Frees the memory and resources associated with menu music.
//*
//* This function ensures proper cleanup by deallocating any music resources (e.g.,
//* sound buffers or music instances) used in the menu to prevent memory leaks.

void CleanupMenuMusic(void);

//* @brief Changes the volume of the menu music.
//*
//* @param _volume The desired volume level (a float value, typically between 0.0 and 1.0).
//* @param _instantaneous Boolean indicating whether the volume change should be immediate
//*                       (`sfTrue`) or gradually adjusted over time (`sfFalse`).
//* @return sfBool Returns `sfTrue` if the volume change was successfully applied, otherwise `sfFalse`.

sfBool ChangeMenuMusicVolume(float _volume, sfBool _instantaneous);

#endif