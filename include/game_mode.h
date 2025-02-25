#ifndef GAME_MODE_H
#define GAME_MODE_H

#define PATTERN_FILE "motif.txt"
#define PATTERN_FILE_ERROR -3

#include <window.h>

/**
 * Initialise la grille du jeu avec des cellules vivantes et mortes de manière aléatoire.
 * 
 * @param game_grid La grille à initialiser.
 */
void random_game(grid_t game_grid);

/**
 * Charge un motif de jeu depuis un fichier dans la grille.
 * Si le fichier n'existe pas, il est créé avec un motif par défaut.
 * 
 * @param game_grid La grille où charger le motif.
 * @return Retourne 1 en cas de succès ou un code d'erreur si le fichier ne peut pas être ouvert.
 */
int file_game(grid_t game_grid);

/**
 * Initialise la grille du jeu avec un motif "canon de planeurs".
 * 
 * @param game_grid La grille à initialiser.
 */
void glider_gun(grid_t game_grid);


#endif // GAME_MODE_H
