#ifndef GAMEOVERSOUND_H
#define GAMEOVERSOUND_H

#include "Common.h"
#include "State.h"

#include "PlayerDeathSound.h"


//* @brief Loads the sound resources for the game.
//*
//* This function initializes and prepares the sound files (e.g., background music,
//* sound effects) to be used in the game, loading them into memory for playback. 
void LoadGameOverSounds(void);


//* @brief Frees the memory and resources associated with game sounds.
//*
//* This function ensures proper cleanup by deallocating any sound resources
//* (e.g., sound buffers, sound instances) used in the game to prevent memory leaks.
void CleanupGameOverSound(void);

#endif