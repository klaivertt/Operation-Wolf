#include "Musics.h"

Music music;

void LoadMusic(void)
{
	GameState state = GetGameState();
	switch (state)
	{
	case GAME:
		//music.soundBuffer = sfSoundBuffer_createFromFile("Assets/Musics/");
		break;
	case MENU:
		//music.soundBuffer = sfSoundBuffer_createFromFile("Assets/Musics/");
		break;
	case GAME_OVER:

		break;
	}

	if (music.sound != NULL)
	{
		sfSound_setBuffer(music.sound, music.soundBuffer);
		sfSound_play(music.sound);
	}
	sfSound_setVolume(music.sound, 0.f);
	music.volume = 0;
}

void UpdateVolume(float _dt)
{
	float actualVolume = sfSound_getVolume(music.sound);

	if (actualVolume < music.volume)
	{
		//actualVolume += SPEED_VOLUME * _dt;
	}
	else if (actualVolume > music.volume)
	{
		//actualVolume -= SPEED_VOLUME * _dt;
	}

	sfSound_setVolume(music.sound, actualVolume);

}

void CleanupMusic()
{
	sfSound_destroy(music.sound);
	sfSoundBuffer_destroy(music.soundBuffer);
	music.sound = NULL;
}



