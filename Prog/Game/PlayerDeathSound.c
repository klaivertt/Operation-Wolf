#include "PlayerDeathSound.h"

PlayerDeathSound playerDeathSound;

void LoadPlayerDeathSounds(void)
{
	//Death
	playerDeathSound.Death.soundBuffer = sfSoundBuffer_createFromFile("Assets/Sounds/Player/PlayerDeath.ogg");
	playerDeathSound.Death.sound = sfSound_create();

	sfSound_setBuffer(playerDeathSound.Death.sound, playerDeathSound.Death.soundBuffer);
	sfSound_setLoop(playerDeathSound.Death.sound, sfFalse);

	sfSound_setVolume(playerDeathSound.Death.sound, DEATH_VOLUME);
	playerDeathSound.Death.volume = DEATH_VOLUME;


}

void CleanupPlayerDeathSound(void)
{
	//Mouse On Button
	sfSoundBuffer_destroy(playerDeathSound.Death.soundBuffer);
	playerDeathSound.Death.soundBuffer = NULL;

	sfSound_destroy(playerDeathSound.Death.sound);
	playerDeathSound.Death.sound = NULL;
}


void PlaySound_PlayerDeath(void)
{
	sfSound_play(playerDeathSound.Death.sound);
}

