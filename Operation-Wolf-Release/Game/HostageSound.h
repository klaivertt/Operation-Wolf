#pragma once
#ifndef HOSTAGESOUND_H
#define HOSTAGESOUND_H

#define DIE_VOLUME_HOSTAGE 100

#include "Common.h"

typedef struct HostageSound
{
	Buffer die;
}HostageSound;

//* @brief Loads the sound resources for the hostage.
//*
//* This function initializes and prepares the hostage-related sound files (e.g.,
//* hostage dying) to be used in the game, loading them into memory for playback.
void LoadHostageSound(void);

//* @brief Frees the memory and resources associated with hostage sounds.
//*
//* This function ensures proper cleanup by deallocating any sound resources
//* (e.g., sound buffers, sound instances) related to the hostage to prevent memory leaks.
void CleanupHostageSound(void);

//* @brief Plays the sound effect for the hostage dying.
//*
//* This function triggers the sound associated with the hostage's death event.
void PlaySound_HostageDie(void);


//* @brief Retrieves the current status of the hostage's death sound.
//*
//* @return sfSoundStatus Returns the current status of the hostage death sound.
//*         Possible values: `sfSoundPlaying`, `sfSoundPaused`, `sfSoundStopped`.
sfSoundStatus GetSoundStatue_HostageDie(void);
#endif