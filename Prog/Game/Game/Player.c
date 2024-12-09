#include "Player.h"

Player player = { 0 };

void LoadPlayer(void)
{
	sfTexture* texture = sfTexture_createFromFile("Assets/Sprites/Cursor.png", NULL);
	CreateSprite(&player.aim, (sfVector2f){0,0}, &texture);
}


void UpdatePlayer(float _dt, sfRenderWindow* _render)
{
	sfVector2i mouse = sfMouse_getPositionRenderWindow(_render);

	sfSprite_setPosition(player.aim, (sfVector2f) { mouse.x, mouse.y });
}

void DrawPlayer(sfRenderWindow* _render)
{
	sfRenderWindow_drawSprite(_render, player.aim, NULL);
}

void OnKeyPressedPlayer(sfKeyEvent _key)
{
	switch (_key.code)
	{
	default:
		break;
	}
}
