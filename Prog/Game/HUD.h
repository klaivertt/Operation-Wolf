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

/**
 * @brief Met à jour les données du HUD en fonction du temps et de l'état du jeu.
 *
 * @param _dt Temps écoulé depuis la dernière mise à jour (delta time).
 */
void UpdateHUD(float _dt);


 //* @brief Dessine le HUD dans la fenêtre de rendu spécifiée.
 //*
 //* Cette fonction affiche tous les éléments du HUD, tels que le score, le chargeur,
 //* et toute autre information pertinente, sur la fenêtre de jeu.
 //*
 //* @param _renderWindow Pointeur vers la fenêtre SFML où le HUD sera affiché.
void DrawHUD(sfRenderWindow* _renderWindow);


 * @brief Libère les ressources associées au HUD.
 *
 * Cette fonction nettoie les ressources allouées pour le HUD afin d'éviter les fuites de mémoire.
 * Cela inclut la destruction des textures, des polices ou des autres données chargées.
void CleanupHUD();


#endif // !HUD_H

