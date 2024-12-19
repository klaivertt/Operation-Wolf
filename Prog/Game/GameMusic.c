#include "GameMusic.h"

GameMusic music;

void LoadGameMusic(void)
{

	music.soundBuffer.waves = sfSoundBuffer_createFromFile("Assets/Musics/WaveFight.ogg");
	music.soundBuffer.boss = sfSoundBuffer_createFromFile("Assets/Musics/BossFight.ogg");


	music.sound = sfSound_create();
	

	sfSound_setBuffer(music.sound, music.soundBuffer.waves);
	sfSound_setLoop(music.sound, sfTrue);
	sfSound_play(music.sound);

	sfSound_setVolume(music.sound, 0);
	music.volume = MAX_VOLUME;
}

void UpdateGameMusic(float _dt)
{
	float actualVolume = sfSound_getVolume(music.sound);

	if (actualVolume > music.volume - _dt * VOLUME_SPEED && actualVolume < music.volume + _dt * VOLUME_SPEED)
	{
		actualVolume = music.volume;
	}
	else if (actualVolume < music.volume)
	{
		actualVolume += _dt * VOLUME_SPEED ;
	}
	else if (actualVolume > music.volume)
	{
		actualVolume -= _dt * VOLUME_SPEED ;
	}


	sfSound_setVolume(music.sound, actualVolume);

}

void CleanupGameMusic()
{
	sfSound_destroy(music.sound);
	sfSoundBuffer_destroy(music.soundBuffer.waves);
	music.sound = NULL;
}



void ChangeGameMusic(MusicToPlay _mtp)
{
	switch (_mtp)
	{
	case WAVES:
		sfSound_setBuffer(music.sound, music.soundBuffer.waves);
		break;
	case BOSS:
		sfSound_setBuffer(music.sound, music.soundBuffer.boss);
		break;
	}
	sfSound_play(music.sound);
}

sfBool ChangeGameMusicVolume(float _volume, sfBool  _instantaneous)
{
	music.volume = _volume;

	if (_instantaneous)
	{
		sfSound_setVolume(music.sound, _volume);
	}

	float actualVolume = sfSound_getVolume(music.sound);
	if (actualVolume = music.volume)
	{
		return sfTrue;
	}
	return sfFalse;
}