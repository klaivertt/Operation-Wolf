#ifndef MAP_H
#define MAP_H

#include "Common.h"
#include "Sprite.h"
#include "Props.h"

#define BACKGROUND_SPEED 200.f

typedef struct Map
{
	sfSprite* background;
}Map;

/**
 * @brief Loads the map resources.
 *
 * This function initializes the map, including loading textures, setting up layers,
 * and preparing other required assets for rendering the map in the game.
 */
void LoadMap(void);

/**
 * @brief Updates the map state.
 *
 * This function handles any dynamic behavior of the map, such as animations or interactions,
 * and should be called every frame.
 *
 * @param _dt Delta time (time elapsed since the last update).
 */
void UpdateMap(float _dt);

/**
 * @brief Draws the map on the given render window.
 *
 * Renders the entire map on the screen, including all its layers and details.
 *
 * @param _renderWindow Pointer to the sfRenderWindow where the map will be drawn.
 */
void DrawMap(sfRenderWindow* _renderWindow);

/**
 * @brief Cleans up the resources used by the map.
 *
 * Releases all the memory and resources allocated for the map,
 * such as textures, sprites, and any dynamic data.
 */
void CleanupMap(void);


 //* @brief Draws the third plan of the map.
 //*
 //* This function renders the farthest background layer, typically used for distant elements
 //* like mountains, skies, or other decorative objects.
 //*
 //* @param _renderWindow Pointer to the sfRenderWindow where the third plan will be drawn.
void DrawThirdPlan(sfRenderWindow* _renderWindow);


 //* @brief Draws the second plan of the map.
 //*
 //* Renders the middle layer of the map, which might include objects like trees or buildings
 //* that are closer than the third plan but farther than the first plan.
 //*
 //* @param _renderWindow Pointer to the sfRenderWindow where the second plan will be drawn.
void DrawSecondPlan(sfRenderWindow* _renderWindow);


 //* @brief Draws the first plan of the map.
 //*
 //* Renders the foreground layer of the map, typically the closest objects to the camera,
 //* such as interactive elements or characters.
 //*
 //* @param _renderWindow Pointer to the sfRenderWindow where the first plan will be drawn.
void DrawFistPlan(sfRenderWindow* _renderWindow);

#endif