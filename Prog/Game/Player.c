#include "Player.h"

PlayerData player;

void ReloadMagazine();
void ShootBullet();
void ReloadBullet();

void LoadPlayer()
{
	sfIntRect rect = { 1223, 1946, 47 , 47 };
	sfVector2f position = { SCREEN_WIDTH / 2 , SCREEN_HEIGHT / 2 };
	sfVector2f origin = { 0.5 , 0.5 };
	player.cursor.texture = sfTexture_createFromFile("Assets/Sprites/SpriteSheet.png", NULL);
	player.HP = 20;
	player.magazineNumber = 3;
	player.bulletNumber = BULLET_NUMBER_MAX;

	CreateSprite(&player.cursor.sprite, player.cursor.texture, position, rect, origin);
}

void DrawPlayer(sfRenderWindow* _renderWindow)
{
	sfRenderWindow_drawSprite(_renderWindow, player.cursor.sprite, NULL);
}

void UpdatePlayer(float _dt)
{
	sfFloatRect hitbox = sfSprite_getGlobalBounds(player.cursor.sprite);

	if (player.mousePosition.x > hitbox.width * 0.9 || player.mousePosition.x < SCREEN_WIDTH * 0.9)
	{
		sfSprite_setPosition(player.cursor.sprite, (sfVector2f) { player.mousePosition.x, player.mousePosition.y });
	}
}

void GetDamage(int _damage)
{
	player.HP -= _damage;
}

void GetMousePositionPlayer(sfMouseMoveEvent _mouseMoved)
{
	player.mousePosition.x = (float) _mouseMoved.x;
	player.mousePosition.y = (float) _mouseMoved.y;
}

void CleanupPlayer()
{
	sfSprite_destroy(player.cursor.sprite);
	player.cursor.sprite = NULL;

	sfTexture_destroy(player.cursor.texture);
	player.cursor.texture = NULL;
}

void MouseButtonPressedPlayer(sfRenderWindow* const _renderWindow, sfMouseButtonEvent _mouseButton)
{
	switch (_mouseButton.button)
	{
	case sfMouseLeft:
		ShootBullet();
		AddScore(5);
		UpdateScore();
		break;
	case sfMouseRight:
		ReloadMagazine();
		break;
	default:
		break;
	}
}

void ReloadMagazine()
{
	if (player.magazineNumber > 0)
	{
		player.magazineNumber--;
		ReloadBullet();
	}
	else
	{
		printf("plus de chargeurs");
	}
}

int GetMagazine()
{
	return player.magazineNumber;
}

void ShootBullet()
{
	if (player.bulletNumber > 0)
	{
		player.bulletNumber--;
	}
	else
	{
		printf("plus de balles");
	}
}

void ReloadBullet()
{
	player.bulletNumber = BULLET_NUMBER_MAX;
}

int GetBullet()
{
	return player.bulletNumber;
}