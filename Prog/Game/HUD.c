#include "HUD.h"

HUDData data;

void LoadHUD()
{
	LoadBullet();
	LoadMagazine();
}

void UpdateHUD(float _dt)
{

}

void DrawHUD(sfRenderWindow* _renderWindow)
{
	DrawBullet(_renderWindow);
	DrawMagazine(_renderWindow);
}

void CleanupHUD()
{
	CleanupBullet();
	CleanupMagazine();
}