#ifndef ANIMATIONS_H
#define ANIMATIONS_H

#include "Common.h"

typedef struct Animation
{
	sfTexture* texture;
	sfSprite* sprite;
	sfIntRect size;
	int frameCount;
	int frameRate;
	int currentFrame;
	float timer;
	sfVector2f start;
	sfBool isLooping;
	sfBool isFinished;
}Animation;

//* @brief Creates and initializes an animation.
//*
//* This function sets up the animation by loading the texture from the specified file,
//* configuring the frame count, frame rate, and other properties such as whether
//* the animation should loop or not. It also sets the starting position of the animation.
//*
//* @param _anim Pointer to the Animation structure to initialize.
//* @param _texture Pointer to the texture used for the animation frames.
//* @param _maxFrame Maximum number of frames in the animation.
//* @param _frameCount Total number of frames to use for the animation.
//* @param _frameRate The rate at which frames should be updated (frames per second).
//* @param _isLooping A boolean indicating if the animation should loop once it finishes.
//* @param _start The starting position (sfVector2f) for the animation on the screen.
void CreateAnimation(Animation* _anim, sfSprite** _sprite, sfTexture** _texture, int _maxFrame, int _frameCount, int _frameRate, sfBool _isLooping, sfVector2f _start);


//* @brief Updates the current animation frame.
//*
//* This function progresses the animation based on the delta time (elapsed time) and
//* updates the current frame of the animation. It also handles looping or stopping
//* the animation when it reaches the end.
//*
//* @param _anim Pointer to the Animation structure to update.
//* @param _dt Delta time (time elapsed since the last update) to control the animation speed.
void UpdateAnimation(Animation* _anim, sfSprite** _sprite, float _dt);


//* @brief Resets the animation to its initial state.
//*
//* This function resets the animation to the first frame and starts it over.
//* It is useful for restarting an animation from the beginning.
//*
//* @param _anim Pointer to the Animation structure to reset.
void ResetAnimation(Animation* _anim, sfSprite** _sprite);


 * @brief V�rifie si une animation est termin�e.
 *
 * @param _anim Pointeur constant vers une structure Animation.
 *              Repr�sente l'animation � v�rifier.
 * @return sfBool Retourne `sfTrue` si l'animation est termin�e, sinon `sfFalse`.
 *
sfBool AnimIsFinished(Animation* const _anim);


 * @brief R�cup�re l'index de la frame actuelle d'une animation.
 *
 * @param _anim Pointeur vers une structure Animation.
 *              Repr�sente l'animation en cours.
 * @return int Index de la frame actuelle dans l'animation.

int GetAnimCurrentFrame(Animation* _anim);


 * @brief Lib�re les ressources li�es � une animation, notamment le sprite et la texture.
 *
 * @param anim Pointeur vers une structure Animation � nettoyer.
 * @param sprite Double pointeur vers le sprite associ� � l'animation.
 *               La m�moire sera lib�r�e et le pointeur mis � NULL.
 * @param texture Double pointeur vers la texture associ�e � l'animation.
 *                La m�moire sera lib�r�e et le pointeur mis � NULL.
 
void CleanUpAnimation(Animation* anim, sfSprite** sprite, sfTexture** texture);


#endif // !ANIMATIONS_H
