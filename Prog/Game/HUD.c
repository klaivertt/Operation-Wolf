#include "HUD.h"

void LoadHUD(void)
{
	LoadBullet();
	LoadMagazine();
	LoadScore();
	LoadIcon();
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
	DrawIcon(_renderWindow);
	DrawHealthBar(_renderWindow);
	DrawDamageWindow(_renderWindow);
}

void CleanupHUD(void)
{
	CleanupBullet();
	CleanupMagazine();
	CleanupIcon();
	CleanupDamageWindow();
	CleanupHealthBar();
	CleanupScore();
}