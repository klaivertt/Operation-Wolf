#pragma once
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

void LoadPlayerSounds(void);
void CleanupPlayerSound(void);

void PlaySound_PlayerShoot(void);
void PlaySound_PlayerShootWithoutBullet(void);
void PlaySound_PlayerReload(void);
#endif
