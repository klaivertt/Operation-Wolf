#include "PlayerSound.h"

PlayerSound playerSound;

void LoadPlayerSounds(void)
{
	//Shoot
	playerSound.shoot.soundBuffer = sfSoundBuffer_createFromFile("Assets/Sounds/Player/PlayerShoot.ogg");
	playerSound.shoot.sound = sfSound_create();

	sfSound_setBuffer(playerSound.shoot.sound, playerSound.shoot.soundBuffer);
	sfSound_setLoop(playerSound.shoot.sound, sfFalse);

	sfSound_setVolume(playerSound.shoot.sound, SHOOT_VOLUME);
	playerSound.shoot.volume = SHOOT_VOLUME;

	//Die
	playerSound.ShootWithoutBullet.soundBuffer = sfSoundBuffer_createFromFile("Assets/Sounds/Player/PlayerShootWithoutBullet.ogg");
	playerSound.ShootWithoutBullet.sound = sfSound_create();

	sfSound_setBuffer(playerSound.ShootWithoutBullet.sound, playerSound.ShootWithoutBullet.soundBuffer);
	sfSound_setLoop(playerSound.ShootWithoutBullet.sound, sfFalse);

	sfSound_setVolume(playerSound.ShootWithoutBullet.sound, SHOOT_VOLUME);
	playerSound.ShootWithoutBullet.volume = SHOOT_VOLUME;
}

void CleanupPlayerSound(void)
{
	//Shoot
	sfSoundBuffer_destroy(playerSound.shoot.soundBuffer);
	playerSound.shoot.soundBuffer = NULL;

	sfSound_destroy(playerSound.shoot.sound);
	playerSound.shoot.sound = NULL;

	//Die
	sfSoundBuffer_destroy(playerSound.ShootWithoutBullet.soundBuffer);
	playerSound.ShootWithoutBullet.soundBuffer = NULL;

	sfSound_destroy(playerSound.ShootWithoutBullet.sound);
	playerSound.ShootWithoutBullet.sound = NULL;

}


void PlaySound_PlayerShoot(void)
{
	sfSound_play(playerSound.shoot.sound);
}

void PlaySound_PlayerShootWithoutBullet(void)
{
	sfSound_play(playerSound.ShootWithoutBullet.sound);
}

