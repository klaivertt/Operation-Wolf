#include "Sprite.h"


sfBool MouseClickOnSprite(sfMouseButtonEvent _mouseButton, sfSprite* _sprite)
{
	sfFloatRect globalBounds = sfSprite_getGlobalBounds(_sprite);

	if (sfFloatRect_contains(&globalBounds, (float)_mouseButton.x, (float)_mouseButton.y))
	{
		return sfTrue;
	}
	else
	{
		return sfFalse;
	}

}

sfBool MouseMoveOnSprite(sfMouseMoveEvent _mouseMove, sfSprite* _sprite)
{
	sfFloatRect globalBounds = sfSprite_getGlobalBounds(_sprite);

	if (sfFloatRect_contains(&globalBounds, (float)_mouseMove.x, (float)_mouseMove.y))
	{
		return sfTrue;
	}
	else
	{
		return sfFalse;
	}

}


sfBool MouseClickOnSpritePixel(sfVector2f _mouseButton, sfSprite* _sprite)
{
	sfFloatRect globalBounds = sfSprite_getGlobalBounds(_sprite);

	if (sfFloatRect_contains(&globalBounds, (float)_mouseButton.x, (float)_mouseButton.y))
	{

		if (_mouseButton.x - globalBounds.left < 0 || _mouseButton.y - globalBounds.top < 0)
		{
			return sfFalse;
		}
		sfVector2u pixelPos = { (unsigned int)(_mouseButton.x - globalBounds.left),(unsigned int)(_mouseButton.y - globalBounds.top)};

		sfIntRect textureRect = sfSprite_getTextureRect(_sprite);

		sfVector2u texturePixelPos = { textureRect.left + pixelPos.x,textureRect.top + pixelPos.y };

		const sfTexture* spriteTexture = sfSprite_getTexture(_sprite);

		sfImage* spriteSheetImage = sfTexture_copyToImage(spriteTexture);

		sfColor color = sfImage_getPixel(spriteSheetImage, texturePixelPos.x, texturePixelPos.y);

		sfImage_destroy(spriteSheetImage);


		if (color.a != 0) {
			return sfTrue;
		}

	}
	return sfFalse;
}

sfBool MouseMoveOnSpritePixel(sfMouseMoveEvent _mouseMove, sfSprite* _sprite)
{
	sfFloatRect globalBounds = sfSprite_getGlobalBounds(_sprite);

	if (sfFloatRect_contains(&globalBounds, (float)_mouseMove.x, (float)_mouseMove.y))
	{
		sfVector2u pixelPos = { _mouseMove.x - (unsigned int)globalBounds.left, _mouseMove.y - (unsigned int)globalBounds.top };

		sfIntRect textureRect = sfSprite_getTextureRect(_sprite);

		sfVector2u texturePixelPos = { textureRect.left + pixelPos.x,textureRect.top + pixelPos.y };

		const sfTexture* spriteTexture = sfSprite_getTexture(_sprite);

		sfImage* spriteSheetImage = sfTexture_copyToImage(spriteTexture);

		sfColor color = sfImage_getPixel(spriteSheetImage, texturePixelPos.x, texturePixelPos.y);

		sfImage_destroy(spriteSheetImage);

		if (color.a != 0) {
			return sfTrue;
		}

	}
	return sfFalse;
}


void CreateSprite(sfSprite** _sprite, sfTexture* _texture, sfVector2f _position, sfIntRect _rect, sfVector2f _origin)
{

	if (*_sprite == NULL)
	{
		*_sprite = sfSprite_create();
		sfSprite_setTexture(*_sprite, _texture, sfFalse);
	}

	//If its not a Sprite sheet
	if (_rect.width == 0 && _rect.height == 0)
	{
		sfVector2u size = sfTexture_getSize(_texture);
		_rect = (sfIntRect){ 0,0,size.x,size.y };
	}

	sfSprite_setTextureRect(*_sprite, _rect);
	sfSprite_setOrigin(*_sprite, (sfVector2f) { (float)_rect.width* _origin.x, (float)_rect.height* _origin.y });
	sfSprite_setPosition(*_sprite, _position);
}

sfBool MoveSpriteToTarget(sfSprite** _sprite, sfVector2f _targetedPosition, float _speed, sfBool _TargetToSameTime)
{
	sfVector2f actualPosition = sfSprite_getPosition(*_sprite);

	if (_TargetToSameTime)
	{

		float distanceX = _targetedPosition.x - actualPosition.x;
		float distanceY = _targetedPosition.y - actualPosition.y;


		float totalDistance = (float)sqrt(distanceX * distanceX + distanceY * distanceY);

		if (totalDistance < _speed) {
			actualPosition.x = _targetedPosition.x;
			actualPosition.y = _targetedPosition.y;
			return sfTrue;
		}
		else
		{

			float ratioX = distanceX / totalDistance;
			float ratioY = distanceY / totalDistance;

			actualPosition.x += ratioX * _speed;
			actualPosition.y += ratioY * _speed;

		}
	}
	else
	{

		if (actualPosition.x > _targetedPosition.x - _speed && actualPosition.x < _targetedPosition.x + _speed)
		{
			actualPosition.x = _targetedPosition.x;
		}
		else if (actualPosition.x < _targetedPosition.x)
		{
			actualPosition.x += _speed;
		}
		else if (actualPosition.x > _targetedPosition.x)
		{
			actualPosition.x -= _speed;
		}


		if (actualPosition.y > _targetedPosition.y - _speed && actualPosition.y < _targetedPosition.y + _speed)
		{
			actualPosition.y = _targetedPosition.y;
		}
		else if (actualPosition.y < _targetedPosition.y)
		{
			actualPosition.y += _speed;
		}
		else if (actualPosition.y > _targetedPosition.y)
		{
			actualPosition.y -= _speed;
		}
	}

	sfSprite_setPosition(*_sprite, actualPosition);


	if (actualPosition.x == _targetedPosition.x && actualPosition.y == _targetedPosition.y)
	{
		return sfTrue;
	}
	return sfFalse;
}


sfBool MouseClickOnImagePixel(sfMouseButtonEvent _mouseButton, sfSprite* _sprite, sfImage* _image, sfColor* _pixelColor)
{

	sfFloatRect globalBounds = sfSprite_getGlobalBounds(_sprite);

	if (sfFloatRect_contains(&globalBounds, (float)_mouseButton.x, (float)_mouseButton.y))
	{
		sfVector2i PosPixel = { (unsigned int)(_mouseButton.x - globalBounds.left),(unsigned int)(_mouseButton.y - globalBounds.top) };

		sfColor pixelColor = sfImage_getPixel(_image, PosPixel.x, PosPixel.y);


		if (pixelColor.a != 0)
		{
			return sfTrue;
		}


	}
	return sfFalse;

}

//sfBool Verif

//if (pixelColor.r == 255 && pixelColor.g == 0 && pixelColor.b == 0 && pixelColor.a == 255)
//{
//	printf("headshot\n");
//	return sfTrue;
//}

void SetSpriteOrigin(sfSprite** _sprite, sfVector2f divide)
{
	sfVector2u size = sfTexture_getSize(sfSprite_getTexture(*_sprite));
	sfSprite_setOrigin(*_sprite, (sfVector2f) { size.x / divide.x, size.y / divide.y });
}