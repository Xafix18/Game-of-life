#ifndef MENU_H
#define MENU_H

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <window.h>

/**
 * Affiche la bannière du jeu dans le terminal.
 */
void print_banniere(void);

/**
 * Affiche les options du menu principal dans le terminal.
 */
void print_menu(void);

/**
 * Exécute le choix de l'utilisateur en initialisant la grille avec le motif correspondant.
 * 
 * @param choice Le choix de l'utilisateur dans le menu.
 * @param game_grid La grille à initialiser en fonction du choix.
 */
void choix_user(int choice, grid_t game_grid);

/**
 * Affiche le menu, traite l'entrée utilisateur et initialise la grille en fonction de l'option sélectionnée.
 * 
 * @param game_grid La grille à initialiser.
 * @return Retourne 1 en cas de succès ou un code d'erreur pour les problèmes liés aux fichiers.
 */
int menu(grid_t game_grid);


#endif // MENU_H
