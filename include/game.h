#ifndef GAME_HDR
#define GAME_HDR

#include <window.h>
#include <ncurses.h>

/**
 * Lance la boucle principale du jeu, gère les entrées, le rendu et les mises à jour.
 * 
 * @param game_grid La grille représentant l'état du jeu.
 */
void game(grid_t game_grid);

/**
 * Affiche l'état actuel de la grille du jeu dans la fenêtre de jeu spécifiée.
 * 
 * @param game_grid La grille représentant l'état du jeu.
 * @param game_win Pointeur vers la fenêtre de jeu.
 */
void print_game(grid_t game_grid, WINDOW *game_win);

/**
 * Affiche les informations du jeu, y compris le numéro de génération et les paramètres de délai.
 * 
 * @param info_win Pointeur vers la fenêtre d'informations.
 * @param generation Le numéro de la génération actuelle.
 * @param delay Le délai actuel entre les mises à jour, en microsecondes.
 * @param manual Indique si le mode manuel est activé (1) ou automatique (0).
 */
void print_info(WINDOW *info_win, int generation, unsigned long int delay, int manual);

/**
 * Compte le nombre de voisins vivants pour une cellule donnée dans la grille.
 * 
 * @param game_grid La grille représentant l'état du jeu.
 * @param x La coordonnée X de la cellule.
 * @param y La coordonnée Y de la cellule.
 * @return Le nombre de voisins vivants.
 */
int count_live_neighbors(grid_t game_grid, int x, int y);

/**
 * Met à jour la grille du jeu selon les règles du Jeu de la Vie de Conway.
 * 
 * @param game_grid La grille représentant l'état du jeu.
 */
void game_update(grid_t game_grid);



#endif // GAME_HDR
