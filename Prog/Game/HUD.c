#include "HUD.h"

HUDData data;

void LoadHUD()
{
	LoadBullet();
	LoadMagazine();
	LoadScore();
}

void UpdateHUD(float _dt)
{
	
}

void DrawHUD(sfRenderWindow* _renderWindow)
{
	DrawBullet(_renderWindow);
	DrawMagazine(_renderWindow);
	DrawScore(_renderWindow);
}

void CleanupHUD()
{
	CleanupBullet();
	CleanupMagazine();
	CleanupScore();
}