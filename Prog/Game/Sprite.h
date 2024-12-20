#pragma once
#ifndef BUTTON_H
#define BUTTON_H

#include "Common.h"


//* @brief Creates a sprite with specified properties.
//*
//* @param _sprite Double pointer to the sprite to be created.
//*                The function allocates and initializes the sprite.
//* @param _texture Pointer to the texture to be used for the sprite.
//* @param _position Position of the sprite in the 2D world (x, y).
//* @param _rect IntRect defining the section of the texture to use.
//*              If the value is 0, the entire texture is used (not a sprite sheet).
//* @param _origin Origin of the sprite, specified as a multiplier of its size.
//*                For example, `{0, 0}` means the default size origin.
void CreateSprite(sfSprite** _sprite, sfTexture* _texture, sfVector2f _position, sfIntRect _rect, sfVector2f _origin);

//* @brief Moves a sprite toward a targeted position at a specified speed.
//*
//* @param _sprite Double pointer to the sprite to be moved.
//* @param _targetedPosition Target position the sprite should reach (x, y).
//* @param _speed Movement speed of the sprite.
//* @param _TargetToSameTime Boolean indicating if the sprite should move
//*                          to the target in the same amount of time regardless of distance.
//* @return sfBool Returns `sfTrue` if the sprite has reached the targeted position, otherwise `sfFalse`.
sfBool MoveSpriteToTarget(sfSprite** _sprite, sfVector2f _targetedPosition, float _speed, sfBool _TargetToSameTime);


//* @brief Checks if a mouse click occurred on a sprite.
//*
//* @param _mouseButton Mouse button event containing click position.
//* @param _sprite Pointer to the sprite to check.
//* @return sfBool Returns `sfTrue` if the click position is within the bounds of the sprite, otherwise `sfFalse`.
sfBool MouseClickOnSprite(sfMouseButtonEvent _mouseButton, sfSprite* _sprite);


//* @brief Checks if the mouse is hovering over a sprite.
//*
//* @param _mouseMove Mouse move event containing the current mouse position.
//* @param _sprite Pointer to the sprite to check.
//* @return sfBool Returns `sfTrue` if the mouse is over the sprite, otherwise `sfFalse`.
sfBool MouseMoveOnSprite(sfMouseMoveEvent _mouseMove, sfSprite* _sprite);


//* @brief Checks if a mouse click occurred on a specific pixel of a sprite.
//*
//* @param _mouseButton Mouse position as a vector.
//* @param _sprite Pointer to the sprite to check.
//* @return sfBool Returns `sfTrue` if the click is on a pixel of the sprite, otherwise `sfFalse`.
sfBool MouseClickOnSpritePixel(sfVector2f _mouseButton, sfSprite* _sprite);


//* @brief Checks if the mouse is hovering over a specific pixel of a sprite.
//*
//* @param _mouseMove Mouse move event containing the current mouse position.
//* @param _sprite Pointer to the sprite to check.
//* @return sfBool Returns `sfTrue` if the mouse is over a specific pixel of the sprite, otherwise `sfFalse`.
sfBool MouseMoveOnSpritePixel(sfMouseMoveEvent _mouseMove, sfSprite* _sprite);

//* @brief Checks if a mouse click occurred on a specific pixel of an image.
//*
//* @param _mouseButton Mouse button event containing click position.
//* @param _sprite Pointer to the sprite associated with the image.
//* @param _image Pointer to the image for precise pixel checking.
//* @param _pixelColor Pointer to a color value that will store the clicked pixel's color (if applicable).
//* @return sfBool Returns `sfTrue` if the click is on a specific pixel of the image, otherwise `sfFalse`.
sfBool MouseClickOnImagePixel(sfMouseButtonEvent _mouseButton, sfSprite* _sprite, sfImage* _image, sfColor* _pixelColor);

//@brief Sets the origin of a sprite based on its texture size divided by a factor.
//@param _sprite Pointer to the sprite (must have a valid texture).
//@param divide  Division factors for the texture's width (x) and height (y).
void SetSpriteOrigin(sfSprite** _sprite, sfVector2f divide);
#endif