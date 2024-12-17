#include "HUD.h"

void LoadHUD()
{
	LoadBullet();
	LoadMagazine();
	LoadScore();
	LoadGrenade();
	LoadIcon();
	LoadHealthBar();
}

void DrawHUD(sfRenderWindow* _renderWindow)
{
	DrawBullet(_renderWindow);
	DrawMagazine(_renderWindow);
	DrawScore(_renderWindow);
	DrawGrenade(_renderWindow);
	DrawIcon(_renderWindow);
	DrawHealthBar(_renderWindow);
}

void CleanupHUD()
{
	CleanupBullet();
	CleanupMagazine();

	CleanupGrenade();
	CleanupIcon();
}