#ifndef PROPS_H
#define PROPS_H

#include "Common.h"
#include "Sprite.h"

#define MAX_PROPS 6

#define MAX_PROPS_TEXTURE 3

#define PROP_MIN_DISTANCE 120

#define PLACEMENT_CORRECTION 10
typedef struct Props
{
	sfSprite* sprite;
	int layerY;
}Props;


//* @brief Loads the resources for props.
//*
//* Initializes the props, including loading textures, setting up positions,
//* and preparing other necessary data for rendering in the game.

void LoadProps(void);


//* @brief Updates the state of props.
//*
//* This function updates the positions or animations of props based on
//* the elapsed time and the background speed.
//*
//* @param _dt Delta time(time elapsed since the last update).
//* @param _backgroundSpeed Speed of the background, which may influence the props' movement.
void UpdateProps(float _dt, float _backgroundSpeed);


//* @brief Cleans up the resources used by the props.
//*
//* Frees all memory and resources allocated for the props, such as textures and dynamic data.
void CleanupProps(void);

//* @brief Draws the props in the plan.
//*
//* Renders the props in the middle background layer, typically used for elements like trees or buildings.
//*
//* @param _renderWindow Pointer to the sfRenderWindow where the props will be drawn.
//* @param _layer Defines the layer to be drawn.
void DrawProps(sfRenderWindow* _renderWindow, int _layer);

//* @brief Gets all the props.
//*
//* Returns a pointer to the array or collection containing all the props.
//*
//* @return Pointer to the collection of Props.
Props* GetAllProps(void);


//* @brief Gets a specific prop by index.
//*
//* Returns a pointer to a single prop identified by its index in the collection.
//*
//* @param _index Index of the prop to retrieve.
//* @return Pointer to the specific Prop, or NULL if the index is out of bounds.
Props* GetProps(size_t _index);


#endif