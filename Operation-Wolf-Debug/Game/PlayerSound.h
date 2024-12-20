#ifndef PLAYERSOUNDS_H
#define PLAYERSOUNDS_H

#define SHOOT_VOLUME_PLAYER 50
#define DIE_VOLUME_PLAYER 50

#include "Common.h"

typedef struct PlayerSound
{

	Buffer shoot;
	Buffer ShootWithoutBullet;
	Buffer reload;

}PlayerSound;


//* @brief Loads the sound resources for the player.
//*
//* This function initializes and prepares the player-related sound files (e.g.,
//* player shooting, reloading) to be used in the game, loading them into memory for playback.
void LoadPlayerSounds(void);


//* @brief Frees the memory and resources associated with player sounds.
//*
//* This function ensures proper cleanup by deallocating any sound resources
//* (e.g., sound buffers, sound instances) related to the player to prevent memory leaks.
void CleanupPlayerSound(void);

//* @brief Plays the sound effect for the player shooting.
//*
//* This function triggers the sound associated with the player firing their weapon.
void PlaySound_PlayerShoot(void);

//* @brief Plays the sound effect for the player attempting to shoot without ammunition.
//*
//* This function triggers the sound associated with the player trying to shoot when no bullets are available.
void PlaySound_PlayerShootWithoutBullet(void);

//* @brief Plays the sound effect for the player reloading.
//*
//* This function triggers the sound associated with the player reloading their weapon.
void PlaySound_PlayerReload(void);

#endif
