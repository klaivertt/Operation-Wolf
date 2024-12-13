#pragma once
#ifndef HUD_H
#define HUD_H

#include "Common.h"
#include "Sprite.h"
#include "Bullet.h"
#include "Magazine.h"
#include "Score.h"

/**
 * @brief Structure contenant les donn�es de l'interface utilisateur (HUD).
 *
 * Cette structure regroupe les �l�ments n�cessaires � l'affichage et � la gestion
 * du HUD, incluant les informations sur le chargeur, les balles restantes, et le score.
 */
typedef struct HUDData
{
    Magazine magazine; ///< Donn�es concernant le chargeur (nombre de balles restantes).
    Bullet bullet;     ///< Informations sur une balle individuelle (par exemple, statut ou type).
    Score score;       ///< Score actuel du joueur.
} HUDData;

/**
 * @brief Charge les ressources n�cessaires pour le HUD.
 *
 * Cette fonction initialise les donn�es et ressources associ�es au HUD, telles que
 * les textures, polices, ou autres �l�ments graphiques n�cessaires.
 */
void LoadHUD();

/**
 * @brief Met � jour les donn�es du HUD en fonction du temps et de l'�tat du jeu.
 *
 * @param _dt Temps �coul� depuis la derni�re mise � jour (delta time).
 */
void UpdateHUD(float _dt);


 //* @brief Dessine le HUD dans la fen�tre de rendu sp�cifi�e.
 //*
 //* Cette fonction affiche tous les �l�ments du HUD, tels que le score, le chargeur,
 //* et toute autre information pertinente, sur la fen�tre de jeu.
 //*
 //* @param _renderWindow Pointeur vers la fen�tre SFML o� le HUD sera affich�.
void DrawHUD(sfRenderWindow* _renderWindow);


 * @brief Lib�re les ressources associ�es au HUD.
 *
 * Cette fonction nettoie les ressources allou�es pour le HUD afin d'�viter les fuites de m�moire.
 * Cela inclut la destruction des textures, des polices ou des autres donn�es charg�es.
void CleanupHUD();


#endif // !HUD_H

