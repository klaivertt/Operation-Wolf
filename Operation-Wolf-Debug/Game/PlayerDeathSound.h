#pragma once
#ifndef PLAYERSOUNDS_H
#define PLAYERSOUNDS_H

#define DEATH_VOLUME 100

#include "Common.h"



typedef struct PlayerDeathSound
{
	Buffer Death;

}PlayerDeathSound;


//* @brief Loads the sound resources for the button.
//*
//* This function initializes and prepares the button-related sound files (e.g.,
//* button shooting, reloading) to be used in the game, loading them into memory for playback.
void LoadPlayerDeathSounds(void);


//* @brief Frees the memory and resources associated with button sounds.
//*
//* This function ensures proper cleanup by deallocating any sound resources
//* (e.g., sound buffers, sound instances) related to the button to prevent memory leaks.
void CleanupPlayerDeathSound(void);

//* @brief Plays the sound effect for the button shooting.
//*
//* This function triggers the sound associated with the button firing their weapon.
void PlaySound_PlayerDeath(void);


#endif
