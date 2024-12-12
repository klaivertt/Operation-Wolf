#include "HUD.h"

void LoadHUD()
{
	LoadBullet();
	LoadMagazine();
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
}

void CleanupHUD()
{
	CleanupBullet();
	CleanupMagazine();
}