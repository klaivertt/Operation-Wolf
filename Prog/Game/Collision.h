#ifndef COLLISION_H
#define COLLISION_H

#include "Common.h"

/**
 * @brief Checks for a collision between two rectangles.
 *
 * @param _rect1 Pointer to the first rectangle (sfFloatRect).
 * @param _rect2 Pointer to the second rectangle (sfFloatRect).
 * @return sfBool Returns `sfTrue` if the two rectangles intersect, otherwise `sfFalse`.
 */
sfBool CollisionRectRect(sfFloatRect* const _rect1, sfFloatRect* const _rect2);

/**
 * @brief Checks if a point is inside a rectangle.
 *
 * @param _rect Pointer to the rectangle (sfFloatRect) to check.
 * @param _point The point (sfVector2i) to check for containment.
 * @return sfBool Returns `sfTrue` if the point is inside the rectangle, otherwise `sfFalse`.
 */
sfBool CollisionPointRect(sfFloatRect* const _rect, sfVector2i const _point);


#endif // !COLLISION_H

