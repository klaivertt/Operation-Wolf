#include "EnemySound.h"

EnemySound enemySound;

sfSoundStatus GetSoundStatue_EnemyShoot(short _i);
sfSoundStatus GetSoundStatue_EnemyDie(short _i);

void LoadEnemySounds(void)
{
	//Shoot
	enemySound.bufferShoot = sfSoundBuffer_createFromFile("Assets/Sounds/Enemy/EnemyShoot.ogg");
	enemySound.bufferDie = sfSoundBuffer_createFromFile("Assets/Sounds/Enemy/EnemyDie.ogg");

	for (short i = 0; i < MOVING_ENEMY_MAX; i++)
	{
		enemySound.sound[i].mouseOnButton = sfSound_create();
		sfSound_setBuffer(enemySound.sound[i].mouseOnButton, enemySound.bufferShoot);
		sfSound_setLoop(enemySound.sound[i].mouseOnButton, sfFalse);
		sfSound_setVolume(enemySound.sound[i].mouseOnButton, SHOOT_VOLUME_ENEMY);

	
		enemySound.sound[i].die = sfSound_create();
		sfSound_setBuffer(enemySound.sound[i].die, enemySound.bufferDie);
		sfSound_setLoop(enemySound.sound[i].die, sfFalse);
		sfSound_setVolume(enemySound.sound[i].die, SHOOT_VOLUME_ENEMY);
	}
	

}

void CleanupEnemySound(void)
{
	for (short i = 0; i < MOVING_ENEMY_MAX; i++)
	{
		//Shoot
		sfSound_destroy(enemySound.sound[i].mouseOnButton);
		enemySound.sound[i].mouseOnButton = NULL;

		//Die
		sfSound_destroy(enemySound.sound[i].die);
		enemySound.sound[i].die = NULL;
	}
	//Shoot
	sfSoundBuffer_destroy(enemySound.bufferShoot);
	enemySound.bufferShoot = NULL;
	//Die
	sfSoundBuffer_destroy(enemySound.bufferDie);
	enemySound.bufferDie = NULL;
}


void PlaySound_EnemyShoot(void)
{
	short i = 0;
	while (i < MOVING_ENEMY_MAX)
	{
		if (GetSoundStatue_EnemyShoot(i) != sfPlaying)
		{
			sfSound_play(enemySound.sound[i].mouseOnButton);
			i = MOVING_ENEMY_MAX;
		}
		else
		{

			i++;
		}
	}
}

void PlaySound_EnemyDie(void)
{
	short i = 0;
	while (i < MOVING_ENEMY_MAX)
	{
		if (GetSoundStatue_EnemyDie(i) != sfPlaying)
		{
			sfSound_play(enemySound.sound[i].die);
			i = MOVING_ENEMY_MAX;
		}
		else
		{
			
			i++;
		}
	}
}

sfSoundStatus GetSoundStatue_EnemyShoot(short _i)
{
	return sfSound_getStatus(enemySound.sound[_i].mouseOnButton);
}

sfSoundStatus GetSoundStatue_EnemyDie(short _i)
{
	return sfSound_getStatus(enemySound.sound[_i].die);
}