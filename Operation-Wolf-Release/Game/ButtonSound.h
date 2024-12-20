#pragma once
#ifndef BUTTONSOUND_H
#define BUTTONSOUND_H

#define MOUSEONBUTTON_VOLUME 100
#define CLICKONBUTTON_VOLUME 100

#include "Common.h"

typedef struct ButtonSound
{

	Buffer mouseOnButton;
	Buffer clickOnButton;
	Buffer reload;

}ButtonSound;


//* @brief Loads the sound resources for the button.
//*
//* This function initializes and prepares the button-related sound files (e.g.,
//* button shooting, reloading) to be used in the game, loading them into memory for playback.
void LoadButtonSounds(void);


//* @brief Frees the memory and resources associated with button sounds.
//*
//* This function ensures proper cleanup by deallocating any sound resources
//* (e.g., sound buffers, sound instances) related to the button to prevent memory leaks.
void CleanupButtonSounds(void);

//* @brief Plays the sound effect for the button shooting.
//*
//* This function triggers the sound associated with the button firing their weapon.
void PlaySound_MouseOnButton(void);

//* @brief Plays the sound effect for the button attempting to shoot without ammunition.
//*
//* This function triggers the sound associated with the button trying to shoot when no bullets are available.
void PlaySound_ClickOnButton(void);

#endif
