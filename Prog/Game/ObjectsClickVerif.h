#pragma once

#include "Common.h"
#include "Sprite.h"

#include "Hostage.h"
#include "Enemy.h"
#include "Map.h"
#include "Collision.h"


sfBool VerifClickOnEnemy(sfMouseButtonEvent _mouseButton);
sfBool VerifClickOnHostage(sfMouseButtonEvent _mouseButton);
sfBool VerifClickOnProps(sfMouseButtonEvent _mouseButton, int _enemyGround);
int VerifClickOnDrop(sfMouseButtonEvent _mouseButton);