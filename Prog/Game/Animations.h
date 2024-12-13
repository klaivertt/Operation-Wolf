#ifndef ANIMATIONS_H
#define ANIMATIONS_H

#include <SFML/Graphics.h>

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
void CreateAnimation(Animation* _anim, sfTexture** _texture, int _maxFrame, int _frameCount, int _frameRate, sfBool _isLooping, sfVector2f _start);


//* @brief Updates the current animation frame.
//*
//* This function progresses the animation based on the delta time (elapsed time) and
//* updates the current frame of the animation. It also handles looping or stopping
//* the animation when it reaches the end.
//*
//* @param _anim Pointer to the Animation structure to update.
//* @param _dt Delta time (time elapsed since the last update) to control the animation speed.
void UpdateAnimation(Animation* _anim, float _dt);


//* @brief Resets the animation to its initial state.
//*
//* This function resets the animation to the first frame and starts it over.
//* It is useful for restarting an animation from the beginning.
//*
//* @param _anim Pointer to the Animation structure to reset.
void ResetAnimation(Animation* _anim);


#endif // !ANIMATIONS_H