#include "Animations.h"


void CreateAnimation(Animation* _anim, sfSprite** _sprite, sfTexture** _texture, int _maxFrame, int _frameCount, int _frameRate, sfBool _isLooping, sfVector2f _start)
{
	// Fonction qui permet de charger et stocker une animation

	sfSprite_setTexture(*_sprite, *_texture, sfTrue);
	sfIntRect rect = sfSprite_getTextureRect(*_sprite);

	rect.width = rect.width / _maxFrame;
	rect.left = (int) _start.x * rect.width;
	rect.top = (int) _start.y * rect.height;

	sfSprite_setTextureRect(*_sprite, rect);

	_anim->size = rect;
	_anim->timer = 0.0f;
	_anim->currentFrame = 1;
	_anim->frameCount = _frameCount;
	_anim->frameRate = _frameRate;
	_start.x = _start.x * rect.width;
	_start.y = _start.y * rect.height;
	_anim->start = _start;
	_anim->isLooping = _isLooping;
	_anim->isFinished = sfFalse;
}

void UpdateAnimation(Animation* _anim, sfSprite** _sprite, float _dt)
{
	// Fonction appel� toutes les frames pour mettre � jour l'animation actuelle
	_anim->timer += _dt;
	if (_anim->timer >= 1.0f / _anim->frameRate)
	{
		if (_anim->currentFrame == _anim->frameCount)
		{
			if (_anim->isLooping == sfTrue)
			{
				_anim->currentFrame = 1;
				_anim->timer = _anim->timer - (1.0f / _anim->frameRate);

				sfIntRect rect = sfSprite_getTextureRect(*_sprite);

				rect.left = (int)_anim->start.x + rect.width * (_anim->currentFrame - 1);

				sfSprite_setTextureRect(*_sprite, rect);
			}
			else
			{
				_anim->isFinished = sfTrue;
			}
		}
		else
		{
			_anim->currentFrame += 1;
			_anim->timer = _anim->timer - (1.0f / _anim->frameRate);

			sfIntRect rect = sfSprite_getTextureRect(*_sprite);

			rect.left = (int)_anim->start.x + rect.width * (_anim->currentFrame - 1);

			sfSprite_setTextureRect(*_sprite, rect);
		}
	}
}

void ResetAnimation(Animation* _anim, sfSprite** _sprite)
{
	// Fonction appel� pour r�initialiser une animation � son �tat de base
	_anim->currentFrame = 1;
	_anim->timer = 0;
	_anim->isFinished = sfFalse;

	sfIntRect rect = sfSprite_getTextureRect(*_sprite);

	rect.left = (int)_anim->start.x + rect.width * (_anim->currentFrame - 1);

	sfSprite_setTextureRect(*_sprite, rect);
}

sfBool AnimIsFinished(Animation* const _anim)
{
	return _anim->isFinished;
}

int GetAnimCurrentFrame(Animation* _anim)
{
	return _anim->currentFrame;
}

void CleanUpAnimation(Animation* anim, sfSprite** _sprite, sfTexture** _texture)
{
	if (!anim) return;

	// R�initialisation des donn�es de l'animation
	anim->size = (sfIntRect){ 0, 0, 0, 0 };
	anim->timer = 0.0f;
	anim->currentFrame = 0;
	anim->frameCount = 0;
	anim->frameRate = 0;
	anim->start = (sfVector2f){ 0.0f, 0.0f };
	anim->isLooping = sfFalse;
	anim->isFinished = sfFalse;

	// R�initialisation des pointeurs
	if (_sprite && *_sprite)
	{
		sfSprite_destroy(*_sprite);
		*_sprite = NULL;
	}

	if (_texture && *_texture)
	{
		sfTexture_destroy(*_texture);
		*_texture = NULL;
	}
}
