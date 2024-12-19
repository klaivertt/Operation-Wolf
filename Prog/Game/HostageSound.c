#include "HostageSound.h"

HostageSound hostageSound;

sfSoundStatus GetSoundStatue_HostageDie(void);

void LoadHostageSound(void)
{
	//Die
	hostageSound.die.soundBuffer = sfSoundBuffer_createFromFile("Assets/Sounds/Hostage/HostageDie.ogg");

	hostageSound.die.sound = sfSound_create();
	sfSound_setBuffer(hostageSound.die.sound, hostageSound.die.soundBuffer);
	sfSound_setLoop(hostageSound.die.sound, sfFalse);
	sfSound_setVolume(hostageSound.die.sound, DIE_VOLUME);
}

void CleanupHostageSound(void)
{
	//Shoot
	sfSound_destroy(hostageSound.die.sound);
	hostageSound.die.sound = NULL;
}


void PlaySound_HostageDie(void)
{

	if (GetSoundStatue_HostageDie() != sfPlaying)
	{
		sfSound_play(hostageSound.die.sound);
	}

}

sfSoundStatus GetSoundStatue_HostageDie(void)
{
	return sfSound_getStatus(hostageSound.die.sound);
}
