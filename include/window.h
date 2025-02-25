#ifndef WINDOW_HDR
#define WINDOW_HDR

#define TERMINAL_SIZE_ERROR -1

#define GAME_H 28
#define GAME_W 58
#define WINDOW_H 30
#define WINDOW_W 80

typedef int grid_t[GAME_H][GAME_W];

/**
 * Initialise l'environnement ncurses, y compris les paramètres d'entrée et les paires de couleurs.
 */
void init_ncurses(void);

#endif // WINDOW_HDR
