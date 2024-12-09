#ifndef DEBUG_H
#define DEBUG_H

#include "../Game/Libs/Common.h"
#include "../Game/Libs/Text.h"

typedef struct Debug
{
	sfText* fps;
}Debug;
void LoadDebug(void);
void UpdateDebug(float _dt, sfRenderWindow* _render);
void DrawDebug(sfRenderWindow* _render);
#endif
