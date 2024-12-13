#pragma once
#ifndef HUD_H
#define HUD_H

#include "Common.h"
#include "Sprite.h"
#include "Bullet.h"
#include "Magazine.h"
#include "Score.h"

/**
 * @brief Structure contenant les données de l'interface utilisateur (HUD).
 *
 * Cette structure regroupe les éléments nécessaires à l'affichage et à la gestion
 * du HUD, incluant les informations sur le chargeur, les balles restantes, et le score.
 */
typedef struct HUDData
{
    Magazine magazine; ///< Données concernant le chargeur (nombre de balles restantes).
    Bullet bullet;     ///< Informations sur une balle individuelle (par exemple, statut ou type).
    Score score;       ///< Score actuel du joueur.
} HUDData;

/**
 * @brief Charge les ressources nécessaires pour le HUD.
 *
 * Cette fonction initialise les données et ressources associées au HUD, telles que
 * les textures, polices, ou autres éléments graphiques nécessaires.
 */
void LoadHUD();



void UpdateHUD(float _dt);


//* @brief Draws the HUD in the specified rendering window.
//*
//* This function displays all HUD elements, such as score, loader,
//* and any other relevant information, on the game window.
//*
//* @param _renderWindow Pointer to the SFML window where the HUD will be displayed.
void DrawHUD(sfRenderWindow* _renderWindow);


//*@brief Releases resources associated with the HUD.
//*
//* This function cleans up the resources allocated to the HUD to prevent memory leaks.
//* This includes the destruction of textures, fonts or other loaded data
void CleanupHUD();


#endif // !HUD_H

