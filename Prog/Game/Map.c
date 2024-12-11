#include "Map.h"

Map map = { 0 };

#pragma region Define Function
void LoadBackground(void);
void MoveBackground(sfSprite* _sprite, float _y);

void LoadProps(void);
void UpdateProps(float _dt);
void DrawProps(sfRenderWindow* _renderWindow);
void CleanupProps(void);
#pragma endregion

#pragma region Game Loop
void LoadMap(void)
{
	LoadBackground();
    LoadProps();
}

void UpdateMap(float _dt)
{
	//float moveX = BACKGROUND_SPEED * _dt;
	MoveBackground(map.background, -BACKGROUND_SPEED * _dt);
    UpdateProps(_dt);
}

void DrawMap(sfRenderWindow* _renderWindow)
{
	sfRenderWindow_drawSprite(_renderWindow, map.background, NULL);
    DrawProps(_renderWindow);
}

void CleanupMap(void)
{
}

#pragma endregion

void LoadBackground(void)
{
	sfTexture* textBackground = sfTexture_createFromFile("Assets/Sprites/Map/Bakcground.png", NULL);
	map.background = sfSprite_create();

	sfSprite_setPosition(map.background, (sfVector2f) { 0, 0 });
	sfTexture_setRepeated(textBackground, sfTrue);
	sfSprite_setTexture(map.background, textBackground, sfTrue);

	sfIntRect textRect = sfSprite_getTextureRect(map.background);
	textRect.width *= 2;
	sfSprite_setTextureRect(map.background, textRect);
}

void MoveBackground(sfSprite* _sprite, float _x)
{
	sfSprite_move(_sprite, (sfVector2f) { _x, 0 });

	sfFloatRect rect = sfSprite_getGlobalBounds(_sprite);

	if (sfSprite_getPosition(_sprite).x < -rect.width / 2)
	{
		sfSprite_move(_sprite, (sfVector2f) { rect.width / 2 , 0});
	}
}

void LoadProps(void)
{
    sfTexture* propsText = sfTexture_createFromFile("Assets/Sprites/Map/props.png", NULL);

    for (size_t i = 0; i < MAX_PROPS; i++)
    {
        map.props[i] = sfSprite_create();
        sfSprite_setTexture(map.props[i], propsText, sfTrue);

        // Randomize x position and choose one of 3 fixed y positions
        float randomX = rand() % 800;
        float randomY = PROP_HEIGHT_STEP * (rand() % 3);

        sfVector2f position ={ randomX, randomY };
        sfSprite_setPosition(map.props[i], position);
    }
}

void UpdateProps(float _dt)
{
    for (size_t i = 0; i < MAX_PROPS; i++)
    {
       float move = -BACKGROUND_SPEED * _dt;

       sfSprite_move(map.props[i], (sfVector2f) { move, 0 });
    }
}

void DrawProps(sfRenderWindow* _renderWindow)
{
    for (size_t i = 0; i < MAX_PROPS; i++)
    {
        sfRenderWindow_drawSprite(_renderWindow, map.props[i], NULL);
    }
}

void CleanupProps(void)
{
    for (size_t i = 0; i < MAX_PROPS; i++)
    {
        sfSprite_destroy(map.props[i]);
    }
}
