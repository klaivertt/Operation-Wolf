#include "EnemySound.h"

EnemySound playerSound;

void LoadEnemySounds(void)
{
	//Shoot
	playerSound.enemyShoot.soundBuffer = sfSoundBuffer_createFromFile("Assets/Sounds/Enemy/EnemyShoot.ogg");
	playerSound.enemyShoot.sound = sfSound_create();

	sfSound_setBuffer(playerSound.enemyShoot.sound, playerSound.enemyShoot.soundBuffer);
	sfSound_setLoop(playerSound.enemyShoot.sound, sfFalse);

	sfSound_setVolume(playerSound.enemyShoot.sound, SHOOT_VOLUME);
	playerSound.enemyShoot.volume = SHOOT_VOLUME;

	//Die
	playerSound.enemyDie.soundBuffer = sfSoundBuffer_createFromFile("Assets/Sounds/Enemy/EnemyDie.ogg");
	playerSound.enemyDie.sound = sfSound_create();

	sfSound_setBuffer(playerSound.enemyDie.sound, playerSound.enemyDie.soundBuffer);
	sfSound_setLoop(playerSound.enemyDie.sound, sfFalse);

	sfSound_setVolume(playerSound.enemyDie.sound, DIE_VOLUME);
	playerSound.enemyDie.volume = DIE_VOLUME;
}

void CleanupEnemySound(void)
{
	//Shoot
	sfSoundBuffer_destroy(playerSound.enemyShoot.soundBuffer);
	playerSound.enemyShoot.soundBuffer = NULL;

	sfSound_destroy(playerSound.enemyShoot.sound);
	playerSound.enemyShoot.sound = NULL;

	//Die
	sfSoundBuffer_destroy(playerSound.enemyDie.soundBuffer);
	playerSound.enemyDie.soundBuffer = NULL;

	sfSound_destroy(playerSound.enemyDie.sound);
	playerSound.enemyDie.sound = NULL;
}


void PlaySound_EnemyShoot(void)
{
	sfSound_play(playerSound.enemyShoot.sound);
}

void PlaySound_EnemyDie(void)
{
	sfSound_play(playerSound.enemyDie.sound);
}

