#include "Player.h"

Player player = { 0 };

void LoadPlayer(void)
{

}


void UpdatePlayer(float _dt, sfRenderWindow* _render)
{
	sfVector2i mouse = sfMouse_getPositionRenderWindow(_render);

	//sfSprite_setPosition(player.mouse, (sfVector2f) { mouse.x, mouse.y });
}

void DrawPlayer(sfRenderWindow* _render)
{

}

void OnKeyPressedPlayer(sfKeyEvent _key)
{
	switch (_key.code)
	{
	default:
		break;
	}
}
