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
	player.grenadeNumber = 1;

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

	GetDamage();
}

void GetDamage()
{
	player.HP -= PlayerDamage();
}

void GetMousePositionPlayer(sfMouseMoveEvent _mouseMoved)
{
	player.mousePosition.x = (float)_mouseMoved.x;
	player.mousePosition.y = (float)_mouseMoved.y;
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
		if (player.bulletNumber != 0)
		{
			VerifClickOnEnemy(_mouseButton);
		}
		break;
	case sfMouseRight:
		ReloadMagazine();
		break;
	default:
		break;
	}
}

void ShootBullet()
{
	player.bulletNumber--;
}

//make the player use 1 magazine and reload bullets
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

//reset bullet amount to maximum value
void ReloadBullet()
{
	player.bulletNumber = BULLET_NUMBER_MAX;
}

//return magazine amount
int GetMagazine()
{
	return player.magazineNumber;
}

//return bullet number left in the magazine
int GetBullet()
{
	return player.bulletNumber;
}

int GetGrenade()
{
	return player.grenadeNumber;
}

void VerifClickOnEnemy(sfMouseButtonEvent _mouseButton)
{

	sfVector2f pos = { _mouseButton.x, _mouseButton.y };
	printf("x : %f    y : %f\n", pos.x, pos.y);
	/*for (int i = 0; i < ENEMY_MAX; i++)
	{*/
	sfBool killEnemy = VerifPlayerKillEnemy(pos);
	printf("kill : %d\n", killEnemy);
	//if (killEnemy)
	//{
	//	AddScore(1);
	//	UpdateScore();
	//	ShootBullet();
	//}
//}
}