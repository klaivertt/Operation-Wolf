#include "Button.h"

ButtonSound buttonSound;

void LoadButtonSounds(void)
{
	//MouseOnButton
	buttonSound.mouseOnButton.soundBuffer = sfSoundBuffer_createFromFile("Assets/Sounds/Menu/MouseOnButton.ogg");
	buttonSound.mouseOnButton.sound = sfSound_create();

	sfSound_setBuffer(buttonSound.mouseOnButton.sound, buttonSound.mouseOnButton.soundBuffer);
	sfSound_setLoop(buttonSound.mouseOnButton.sound, sfFalse);

	sfSound_setVolume(buttonSound.mouseOnButton.sound, MOUSEONBUTTON_VOLUME);
	buttonSound.mouseOnButton.volume = MOUSEONBUTTON_VOLUME;


	//ClickOnButton
	buttonSound.clickOnButton.soundBuffer = sfSoundBuffer_createFromFile("Assets/Sounds/Menu/ClickOnButton.ogg");
	buttonSound.clickOnButton.sound = sfSound_create();

	sfSound_setBuffer(buttonSound.clickOnButton.sound, buttonSound.clickOnButton.soundBuffer);
	sfSound_setLoop(buttonSound.clickOnButton.sound, sfFalse);

	sfSound_setVolume(buttonSound.clickOnButton.sound, CLICKONBUTTON_VOLUME);
	buttonSound.clickOnButton.volume = CLICKONBUTTON_VOLUME;

}

void CleanupButtonSounds(void)
{
	//Mouse On Button
	sfSoundBuffer_destroy(buttonSound.mouseOnButton.soundBuffer);
	buttonSound.mouseOnButton.soundBuffer = NULL;

	sfSound_destroy(buttonSound.mouseOnButton.sound);
	buttonSound.mouseOnButton.sound = NULL;

	//Click On Button
	sfSoundBuffer_destroy(buttonSound.clickOnButton.soundBuffer);
	buttonSound.clickOnButton.soundBuffer = NULL;

	sfSound_destroy(buttonSound.clickOnButton.sound);
	buttonSound.clickOnButton.sound = NULL;
}


void PlaySound_MouseOnButton(void)
{
	sfSound_play(buttonSound.mouseOnButton.sound);
}

void PlaySound_ClickOnButton(void)
{
	sfSound_play(buttonSound.clickOnButton.sound);
}
