#include "GameSound.h"


void LoadGameSounds(void)
{
	LoadEnemySounds();
	LoadPlayerSounds();
	LoadHostageSound();
}

void CleanupGameSound(void)
{
	CleanupEnemySound();
	CleanupPlayerSound();
	CleanupHostageSound();
	
}

