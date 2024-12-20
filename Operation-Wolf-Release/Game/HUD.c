#include "HUD.h"

void LoadHUD(void)
{
	LoadBullet();
	LoadMagazine();
	LoadScore();
	LoadHealthBar();
	LoadDamageWindow();
}

void UpdateHUD(float _dt)
{
	UpdateDamageWindow(_dt);
}

void DrawHUD(sfRenderWindow* _renderWindow)
{
	DrawBullet(_renderWindow);
	DrawMagazine(_renderWindow);
	DrawScore(_renderWindow);
	DrawHealthBar(_renderWindow);
	DrawDamageWindow(_renderWindow);
}

void CleanupHUD(void)
{
	CleanupBullet();
	CleanupMagazine();
	CleanupDamageWindow();
	CleanupHealthBar();
	CleanupScore();
}