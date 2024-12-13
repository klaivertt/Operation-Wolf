#include "HUD.h"

HUDData data;

void LoadHUD()
{
	LoadBullet();
	LoadMagazine();
	LoadScore();
	LoadGrenade();
}

void UpdateHUD(float _dt)
{
	
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