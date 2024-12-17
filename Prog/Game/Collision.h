#ifndef COLLISION_H
#define COLLISION_H

#include "Common.h"

sfBool CollisionRectRect(sfFloatRect* const, sfIntRect* const);

sfBool CollisionPointRect(sfFloatRect* const _rect1, sfVector2i const _point);

#endif // !COLLISION_H

