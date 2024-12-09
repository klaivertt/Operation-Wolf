#ifndef UTILITIES_H
#define UTILITIES_H

#include "Common.h"

void CreateSprite(sfSprite** const _sprite, sfVector2f position, const char* _filepath);
void SetSpriteOrigin(sfSprite** _sprite, sfVector2f divide);
void CreateRect(sfRectangleShape** const _rectangle, sfVector2f _size, sfVector2f _position, sfColor _color, sfBool _fill);
void SetRectOrigin(sfRectangleShape** _rectangle, sfVector2f divide);
#endif
