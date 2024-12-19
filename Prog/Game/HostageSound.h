#pragma once
#ifndef HOSTAGESOUND_H
#define HOSTAGESOUND_H

#define DIE_VOLUME 100

#include "Common.h"

typedef struct HostageSound
{
	Buffer die;
}HostageSound;

void LoadHostageSound(void);
void CleanupHostageSound(void);

void PlaySound_HostageDie(void);
sfSoundStatus GetSoundStatue_HostageDie(void);
#endif