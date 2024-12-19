#pragma once
#ifndef ENEMYSOUNDS_H
#define ENEMYSOUNDS_H

#define SHOOT_VOLUME 100
#define DIE_VOLUME 100

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

void LoadEnemySounds(void);
void CleanupEnemySound(void);

void PlaySound_EnemyShoot(void);	
void PlaySound_EnemyDie(void);

#endif