#pragma once
#ifndef BUTTON_H
#define BUTTON_H

#include "Common.h"

//Rect = 0 if its not a sprite sheet
//Origin : multiply by size : (exemple : {0,0} = original size)
void CreateSprite(sfSprite** _sprite, sfTexture* _texture, sfVector2f _position, sfIntRect _rect, sfVector2f _origin);


//Return [True] if sprite is on targeted position
sfBool MoveSpriteToTarget(sfSprite** _sprite, sfVector2f _targetedPosition, float _speed, sfBool _TargetToSameTime);

//Return [True] if mouse click position is on sprite
sfBool MouseClickOnSprite(sfMouseButtonEvent _mouseButton, sfSprite* _sprite);
//Return [True] if mouse move on sprite
sfBool MouseMoveOnSprite(sfMouseMoveEvent _mouseMove, sfSprite* _sprite);

//Return [True] if mouse click position is on one pixel on sprite
sfBool MouseClickOnSpritePixel(sfMouseButtonEvent _mouseButton, sfSprite* _sprite);
//Return [True] if mouse move on one pixel on sprite
sfBool MouseMoveOnSpritePixel(sfMouseMoveEvent _mouseMove, sfSprite* _sprite);

//Return [True] if mouse click position is on one pixel on Image
sfBool MouseClickOnImagePixel(sfMouseButtonEvent _mouseButton, sfSprite* _sprite, sfImage* _image, sfColor* _pixelColor);


//@brief Sets the origin of a sprite based on its texture size divided by a factor.
//@param _sprite Pointer to the sprite (must have a valid texture).
//@param divide  Division factors for the texture's width (x) and height (y).
void SetSpriteOrigin(sfSprite** _sprite, sfVector2f divide);
#endif