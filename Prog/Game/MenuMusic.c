#include "MenuMusic.h"

MenuMusic music;

void LoadMenuMusic(void)
{

	music.soundBuffer = sfSoundBuffer_createFromFile("Assets/Musics/Menu.ogg");


	music.sound = sfSound_create();
	

	sfSound_setBuffer(music.sound, music.soundBuffer);
	sfSound_setLoop(music.sound, sfTrue);
	sfSound_play(music.sound);

	sfSound_setVolume(music.sound, MAX_VOLUME);
	music.volume = MAX_VOLUME;
}

void UpdateMenuMusic(float _dt)
{
	float actualVolume = sfSound_getVolume(music.sound);

	if (actualVolume > music.volume - _dt * VOLUME_SPEED && actualVolume < music.volume + _dt * VOLUME_SPEED)
	{
		actualVolume = music.volume;
	}
	else if (actualVolume < music.volume)
	{
		actualVolume += _dt * VOLUME_SPEED;
	}
	else if (actualVolume > music.volume)
	{
		actualVolume -= _dt * VOLUME_SPEED;
	}


	sfSound_setVolume(music.sound, actualVolume);

}

void CleanupMenuMusic(void)
{
	sfSound_destroy(music.sound);
	sfSoundBuffer_destroy(music.soundBuffer);
	music.sound = NULL;
}



sfBool ChangeMenuMusicVolume(float _volume, sfBool  _instantaneous)
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