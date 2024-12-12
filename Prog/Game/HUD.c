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

void MouseButtonPressedHUD(sfRenderWindow* const _renderWindow, sfMouseButtonEvent _mouseButton)
{
	switch (_mouseButton.button)
	{
	case sfMouseLeft:
		ShootBullet();
		AddScore(1500);
		UpdateScore();
		break;
	case sfMouseRight:
		ReloadMagazine();
		break;
	default:
		break;
	}
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