#pragma once
#ifndef ENEMYSOUNDS_H
#define ENEMYSOUNDS_H

#define SHOOT_VOLUME_ENEMY 50
#define DIE_VOLUME_ENEMY 80

#include "Common.h"

typedef struct Sound
{
	sfSound* shoot;
	sfSound* die;
}Sound;

typedef struct EnemySound
{
	sfSoundBuffer* bufferShoot;
	sfSoundBuffer* bufferDie;

	Sound sound[ENEMY_MAX];
}EnemySound;


//* @brief Loads the sound resources for the enemy.
//*
//* This function initializes and prepares the enemy-related sound files (e.g.,
//* enemy shooting, enemy dying) to be used in the game, loading them into memory for playback.

void LoadEnemySounds(void);

//* @brief Frees the memory and resources associated with enemy sounds.
//*
//* This function ensures proper cleanup by deallocating any sound resources
//* (e.g., sound buffers, sound instances) related to the enemy to prevent memory leaks.
void CleanupEnemySound(void);

//* @brief Plays the sound effect for the enemy shooting.
//*
//* This function triggers the sound associated with the enemy firing their weapon.
void PlaySound_EnemyShoot(void);

//* @brief Plays the sound effect for the enemy dying.
//*
//* This function triggers the sound associated with the enemy's death event.
void PlaySound_EnemyDie(void);


#endif