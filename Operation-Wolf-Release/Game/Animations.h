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


//* @brief Checks if an animation is complete.
//*
//* @param _anim Constant pointer to an Animation structure.
//* Represents the animation to be checked.
//* @return sfBool Returns `sfTrue` if the animation is complete, otherwise `sfFalse`.
sfBool AnimIsFinished(Animation* const _anim);


//* @brief Retrieves the index of the current frame of an animation.
//*
//* @param _anim Pointer to an Animation structure.
//* Represents the current animation.
//* @return int Index of the current frame in the animation.
int GetAnimCurrentFrame(Animation* _anim);


//*@brief Frees resources linked to an animation, such as sprites and textures.
//*
//* @param anim Pointer to an animation structure to be cleaned up.
//* @param sprite Double pointer to the sprite associated with the animation.
//* Memory will be freed and pointer set to NULL.
//* @param texture Double pointer to the texture associated with the animation.
//* Memory will be freed and pointer set to NULL.
void CleanUpAnimation(Animation* anim, sfSprite** sprite, sfTexture** texture);


#endif // !ANIMATIONS_H
