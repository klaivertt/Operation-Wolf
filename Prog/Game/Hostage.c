#include "Hostage.h"

HostageData hostage = { 0 };


void LoadHostage(void)
{
}

void KeyPressedHostage(sfRenderWindow* _renderWindow, sfKeyEvent _key)
{
}

void MouseButtonPressedHostage(sfRenderWindow* const _renderWindow, sfMouseButtonEvent _mouseButton)
{
}

void MouseMovedHostage(sfRenderWindow* const _renderWindow, sfMouseMoveEvent _mouseMove)
{
}

void UpdateHostage(float _dt)
{
}

void DrawHostage(sfRenderWindow* _renderWindow)
{
}

void CleanupHostage(void)
{
}

HostageState GetHostageState(Hostage* _enemy)
{
	return _enemy->state;
}

void SetHostageState(Hostage* _enemy, HostageState _state)
{
	_enemy->state = _state;
}

sfBool VerifPlayerKillHostage(sfVector2f _mousePos)
{
	sfBool click = MouseClickOnSpritePixel(_mousePos, hostage.hostageSprite[0]);
	if (click)
	{
		printf("DEAD\n");
		SetHostageState(&hostage.hostage, DEAD);
		return sfTrue;
	}
	return sfFalse;
}
