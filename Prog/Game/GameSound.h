#pragma once
#ifndef GAMESOUND_H
#define GAMESOUND_H

#include "Common.h"
#include "State.h"
#include "EnemySound.h"
#include "PlayerSound.h"
#include "HostageSound.h"

#define MAX_VOLUME 100


void LoadGameSounds(void);

void CleanupGameSound(void);

#endif