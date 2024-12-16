#include "HUD.h"

void LoadHUD()
{
	LoadBullet();
	LoadMagazine();
	LoadScore();
	LoadGrenade();
}

void DrawHUD(sfRenderWindow* _renderWindow)
{
	DrawBullet(_renderWindow);
	DrawMagazine(_renderWindow);
	DrawScore(_renderWindow);
	DrawGrenade(_renderWindow);
}

void CleanupHUD()
{
	CleanupBullet();
	CleanupMagazine();
	CleanupScore();
	CleanupGrenade();
}