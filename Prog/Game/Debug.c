#include "Debug.h"
Debug debug = { 0 };

void UpdateFps(float _dt);
void DrawFps(sfRenderWindow* _render);

void LoadDebug(void)
{
	InitText(&debug.fps, "FPS : %f", 15, (sfVector2f){20,20});
}

void UpdateDebug(float _dt, sfRenderWindow* _render)
{
	UpdateFps(_dt);
}

void DrawDebug(sfRenderWindow* _render)
{
	DrawFps(_render);
}

void UpdateFps(float _dt)
{
	printf("_dt %f\n", _dt);
	UpdateTextF(&debug.fps, "FPS : %.2f", 1/_dt);
}

void DrawFps(sfRenderWindow* _render)
{
	sfRenderWindow_drawText(_render, debug.fps, NULL);
}
