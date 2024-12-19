#pragma once
#ifndef PLAYERSOUNDS_H
#define PLAYERSOUNDS_H

#define SHOOT_VOLUME 50
#define DIE_VOLUME 50

#include "Common.h"

typedef struct PlayerSound
{

	Buffer shoot;
	Buffer ShootWithoutBullet;

}PlayerSound;

void LoadPlayerSounds(void);
void CleanupPlayerSound(void);

void PlaySound_PlayerShoot(void);
void PlaySound_PlayerShootWithoutBullet(void);
#endif
