#include "Collision.h"

sfBool CollisionRectRect(sfFloatRect* const _rect1, sfFloatRect* const _rect2)
{
	if (sfFloatRect_intersects(_rect1, _rect2, NULL))
	{
		return sfTrue;
	}
	else
	{
		return sfFalse;
	}
    
}

sfBool CollisionPointRect(sfFloatRect* const _rect1, sfVector2i const _point)
{
	if (sfFloatRect_contains(_rect1, (float)_point.x, (float)_point.x))
	{
		return sfTrue;
	}
	else
	{
		return sfFalse;
	}
    
}
