#include "Props.h"
#include <math.h>

Props props[MAX_PROPS] = { 0 };
sfTexture* texture[MAX_PROPS_TEXTURE] = { 0 };

sfBool IsPositionOccupied(sfVector2f position, float minDistance)
{
    for (size_t i = 0; i < MAX_PROPS; i++)
    {
        sfVector2f existingPos = sfSprite_getPosition(props[i].sprite);
        float distance = sqrtf(powf(position.x - existingPos.x, 2) + powf(position.y - existingPos.y, 2));
        if (distance < minDistance)
        {
            return sfTrue;
        }
    }
    return sfFalse;
}

void LoadProps(void)
{
    texture[0] = sfTexture_createFromFile("Assets/Sprites/Map/props.png", NULL);
    texture[1] = sfTexture_createFromFile("Assets/Sprites/Map/props2.png", NULL);
    texture[2] = sfTexture_createFromFile("Assets/Sprites/Map/props3.png", NULL);

    for (size_t i = 0; i < MAX_PROPS; i++)
    {
        props[i].sprite = sfSprite_create();
        sfSprite_setTexture(props[i].sprite, texture[rand() % MAX_PROPS_TEXTURE], sfTrue);

        // Ensure unique position
        sfVector2f position;
        do {
            props[i].layerY = (rand() % 3) + 1;
            int randomX = rand() % SCREEN_WIDTH;
            int randomY = PROP_HEIGHT_STEP * props[i].layerY;
            position = (sfVector2f){ (float)randomX, (float)randomY };
        } while (IsPositionOccupied(position, PROP_MIN_DISTANCE));

        sfSprite_setPosition(props[i].sprite, position);
        SetSpriteOrigin(&props[i].sprite, (sfVector2f) { 2, 1 });
    }
}

void NewProps(Props* _props)
{
    if (_props == NULL) return;

    sfSprite_setTexture(_props->sprite, texture[rand() % MAX_PROPS_TEXTURE], sfTrue);

    // Ensure unique position
    sfVector2f position;
    do {
        _props->layerY = (rand() % 3) + 1;
        int randomX = (rand() % SCREEN_WIDTH) + (SCREEN_WIDTH * 1.5f);
        int randomY = (PROP_HEIGHT_STEP * _props->layerY) + 100;
        position = (sfVector2f){ (float)randomX, (float)randomY };
    } while (IsPositionOccupied(position, PROP_MIN_DISTANCE));

    sfSprite_setPosition(_props->sprite, position);
    SetSpriteOrigin(&_props->sprite, (sfVector2f) { 2, 1 });
}

void UpdateProps(float _dt, float _backgroundSpeed)
{
    for (size_t i = 0; i < MAX_PROPS; i++)
    {
        float move = -_backgroundSpeed * _dt;

        sfSprite_move(props[i].sprite, (sfVector2f) { move, 0 });

        sfFloatRect rect = sfSprite_getGlobalBounds(props[i].sprite);
        if (sfSprite_getPosition(props[i].sprite).x < -rect.width)
        {
            NewProps(&props[i]);
        }
    }
}

void DrawThirdPlanProps(sfRenderWindow* _renderWindow)
{
    for (size_t i = 0; i < MAX_PROPS; i++)
    {
        if (props[i].layerY == 1)
        {
            sfRenderWindow_drawSprite(_renderWindow, props[i].sprite, NULL);
        }
    }
}

void DrawSecondPlanProps(sfRenderWindow* _renderWindow)
{
    for (size_t i = 0; i < MAX_PROPS; i++)
    {
        if (props[i].layerY == 2)
        {
            sfRenderWindow_drawSprite(_renderWindow, props[i].sprite, NULL);
        }
    }
}

void DrawFirstPlanProps(sfRenderWindow* _renderWindow)
{
    for (size_t i = 0; i < MAX_PROPS; i++)
    {
        if (props[i].layerY == 3)
        {
            sfRenderWindow_drawSprite(_renderWindow, props[i].sprite, NULL);
        }
    }
}

void CleanupProps(void)
{
    for (size_t i = 0; i < MAX_PROPS; i++)
    {
        sfSprite_destroy(props[i].sprite);
    }
}
