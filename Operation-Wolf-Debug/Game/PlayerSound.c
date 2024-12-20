#include "PlayerSound.h"

PlayerSound buttonSound;

void LoadPlayerSounds(void)
{
	//Shoot
	buttonSound.shoot.soundBuffer = sfSoundBuffer_createFromFile("Assets/Sounds/Player/PlayerShoot.ogg");
	buttonSound.shoot.sound = sfSound_create();

	sfSound_setBuffer(buttonSound.shoot.sound, buttonSound.shoot.soundBuffer);
	sfSound_setLoop(buttonSound.shoot.sound, sfFalse);

	sfSound_setVolume(buttonSound.shoot.sound, SHOOT_VOLUME_PLAYER);
	buttonSound.shoot.volume = SHOOT_VOLUME_PLAYER;

	//Die
	buttonSound.ShootWithoutBullet.soundBuffer = sfSoundBuffer_createFromFile("Assets/Sounds/Player/PlayerShootWithoutBullet.ogg");
	buttonSound.ShootWithoutBullet.sound = sfSound_create();

	sfSound_setBuffer(buttonSound.ShootWithoutBullet.sound, buttonSound.ShootWithoutBullet.soundBuffer);
	sfSound_setLoop(buttonSound.ShootWithoutBullet.sound, sfFalse);

	sfSound_setVolume(buttonSound.ShootWithoutBullet.sound, SHOOT_VOLUME_PLAYER);
	buttonSound.ShootWithoutBullet.volume = SHOOT_VOLUME_PLAYER;

	//Reload
	buttonSound.reload.soundBuffer = sfSoundBuffer_createFromFile("Assets/Sounds/Player/PlayerReload.ogg");
	buttonSound.reload.sound = sfSound_create();

	sfSound_setBuffer(buttonSound.reload.sound, buttonSound.reload.soundBuffer);
	sfSound_setLoop(buttonSound.reload.sound, sfFalse);

	sfSound_setVolume(buttonSound.reload.sound, SHOOT_VOLUME_PLAYER);
	buttonSound.reload.volume = SHOOT_VOLUME_PLAYER;
}

void CleanupPlayerSound(void)
{
	//Shoot
	sfSoundBuffer_destroy(buttonSound.shoot.soundBuffer);
	buttonSound.shoot.soundBuffer = NULL;

	sfSound_destroy(buttonSound.shoot.sound);
	buttonSound.shoot.sound = NULL;

	//Die
	sfSoundBuffer_destroy(buttonSound.ShootWithoutBullet.soundBuffer);
	buttonSound.ShootWithoutBullet.soundBuffer = NULL;

	sfSound_destroy(buttonSound.ShootWithoutBullet.sound);
	buttonSound.ShootWithoutBullet.sound = NULL;

	//Die
	sfSoundBuffer_destroy(buttonSound.reload.soundBuffer);
	buttonSound.reload.soundBuffer = NULL;

	sfSound_destroy(buttonSound.reload.sound);
	buttonSound.reload.sound = NULL;

}


void PlaySound_PlayerShoot(void)
{
	sfSound_play(buttonSound.shoot.sound);
}

void PlaySound_PlayerShootWithoutBullet(void)
{
	sfSound_play(buttonSound.ShootWithoutBullet.sound);
}

void PlaySound_PlayerReload(void)
{
	sfSound_play(buttonSound.reload.sound);
}