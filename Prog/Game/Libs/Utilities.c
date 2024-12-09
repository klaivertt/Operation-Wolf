#include "Utilities.h"

void CreateSprite(sfSprite** const _sprite, sfVector2f position, const char* _filepath)
{
	*_sprite = sfSprite_create();
	sfSprite_setPosition(*_sprite, position);

	sfTexture* texture = sfTexture_createFromFile(_filepath, NULL);
	sfSprite_setTexture(*_sprite, texture, sfTrue);
}


void SetSpriteOrigin(sfSprite** _sprite, sfVector2f divide)
{
    sfVector2u size = sfTexture_getSize(sfSprite_getTexture(*_sprite));
    sfSprite_setOrigin(*_sprite, (sfVector2f) { size.x / divide.x, size.y / divide.y });
}



void CreateRect(sfRectangleShape** const _rectangle, sfVector2f _size, sfVector2f _position, sfColor _color, sfBool _fill)
{
    *_rectangle = sfRectangleShape_create(); 
    if (*_rectangle == NULL)
    {
        return; 
    }
    sfRectangleShape_setSize(*_rectangle, _size);
    sfRectangleShape_setPosition(*_rectangle, _position);

    if (!_fill)
    {
        sfRectangleShape_setFillColor(*_rectangle, _color);
        sfRectangleShape_setOutlineThickness(*_rectangle, 0); 
    }
    else 
    {
        sfRectangleShape_setFillColor(*_rectangle, sfTransparent); 
        sfRectangleShape_setOutlineColor(*_rectangle, _color);
        sfRectangleShape_setOutlineThickness(*_rectangle, 3);
    }
}


void SetRectOrigin(sfRectangleShape** _rectangle, sfVector2f divide)
{
    sfVector2f size = sfRectangleShape_getSize(*_rectangle);
	sfSprite_setOrigin(*_rectangle, (sfVector2f) { size.x / divide.x, size.y / divide.y});
}