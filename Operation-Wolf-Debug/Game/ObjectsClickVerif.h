#ifndef OBJECTS_CLICK_VERIF_H
#define OBJECTS_CLICK_VERIF_H

#include "Common.h"
#include "Sprite.h"

#include "Hostage.h"
#include "Enemy.h"
#include "Map.h"
#include "Collision.h"


//* @brief Verifies if a mouse click occurred on an enemy.
//*
//* @param _mouseButton The mouse button event containing the click position.
//* @return sfBool Returns `sfTrue` if the click position is on an enemy, otherwise `sfFalse`.
sfBool VerifClickOnEnemy(sfMouseButtonEvent _mouseButton);

//* @brief Verifies if a mouse click occurred on a hostage.
//*
//* @param _mouseButton The mouse button event containing the click position.
//* @return sfBool Returns `sfTrue` if the click position is on a hostage, otherwise `sfFalse`.
sfBool VerifClickOnHostage(sfMouseButtonEvent _mouseButton);

//* @brief Verifies if a mouse click occurred on a prop.
//*
//* @param _mouseButton The mouse button event containing the click position.
//* @param _enemyGround An integer representing a specific ground value or identifier related to the prop.
//* @return sfBool Returns `sfTrue` if the click position is on a prop, otherwise `sfFalse`.

sfBool VerifClickOnProps(sfMouseButtonEvent _mouseButton, int _enemyGround);


//* @brief Verifies if a mouse click occurred on a drop item.
//*
//* @param _mouseButton The mouse button event containing the click position.
//* @return int Returns a non-negative integer identifying the drop item clicked or `-1` if no drop item was clicked.
int VerifClickOnDrop(sfMouseButtonEvent _mouseButton);

#endif