#include "Player.h"

PlayerData player;

void LoadPlayer()
{
	LoadCursor();
	LoadAmmo();
}

void DrawPlayer(sfRenderWindow* _renderWindow)
{
	sfRenderWindow_drawSprite(_renderWindow, player.cursor.sprite, NULL);
}

void UpdatePlayer()
{
	sfFloatRect hitbox = sfSprite_getGlobalBounds(player.cursor.sprite);

	if (player.mousePosition.x > hitbox.width * 0.9 || player.mousePosition.x < SCREEN_WIDTH * 0.9)
	{
		sfSprite_setPosition(player.cursor.sprite, (sfVector2f) { player.mousePosition.x, player.mousePosition.y });
	}
}

void GetMousePositionPlayer(sfMouseMoveEvent _mouseMoved)
{
	player.mousePosition.x = _mouseMoved.x;
	player.mousePosition.y = _mouseMoved.y;
}

void CleanupPlayer()
{
	sfSprite_destroy(player.cursor.sprite);
	player.cursor.sprite = NULL;

	sfTexture_destroy(player.cursor.texture);
	player.cursor.texture = NULL;
}

void LoadCursor()
{
	sfIntRect rect = { 407, 648, 17 , 17 };
	sfVector2f position = { SCREEN_WIDTH / 2 , SCREEN_HEIGHT / 2 };
	sfVector2f origin = { 0.5 , 0.5 };
	player.cursor.texture = sfTexture_createFromFile("Assets/Sprites/OperationWolf - SpriteSheet.png", NULL);

	CreateSprite(&player.cursor.sprite, player.cursor.texture, position, rect, origin);
	sfSprite_setScale(player.cursor.sprite, (sfVector2f) { 3, 3 });
}

void LoadAmmo()
{
	sfIntRect rect = { 40, 728, 8 , 16 };
	sfVector2f position = { SCREEN_WIDTH / 2 , SCREEN_HEIGHT / 2 };
	sfVector2f origin = { 0.5 , 0.5 };
	player.bullet.texture = sfTexture_createFromFile("Assets/Sprites/OperationWolf - SpriteSheet.png", NULL);

	CreateSprite(&player.bullet.sprite, player.bullet.texture, position, rect, origin);
	sfSprite_setScale(player.cursor.sprite, (sfVector2f) { 3, 3 });
}

void CleanupCursor()
{
	sfSprite_destroy(player.cursor.sprite);
	player.cursor.sprite = NULL;

	sfTexture_destroy(player.cursor.texture);
	player.cursor.texture = NULL;
}

void CleanupAmmo()
{
	sfSprite_destroy(player.cursor.sprite);
	player.cursor.sprite = NULL;

	sfTexture_destroy(player.cursor.texture);
	player.cursor.texture = NULL;
}