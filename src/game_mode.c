#include <game_mode.h>
#include <window.h>
#include <stdio.h>
#include <stdlib.h>

void random_game(grid_t game_grid) {
    for (int i = 0; i < GAME_H; i++) {
        for (int j = 0; j < GAME_W; j++) {
            game_grid[i][j] = (rand() % 4) == 0;
        }
    }
}

const char default_pattern[6][6] = {
    {' ', ' ', 'O', ' ', ' ', ' '},
    {'O', ' ', 'O', ' ', ' ', ' '},
    {' ', 'O', 'O', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' '}
};

// Fonction pour charger le motif dans la fenêtre de jeu
int file_game(grid_t game_grid) {
    FILE *file = fopen(PATTERN_FILE, "r");

    if (!file) {
        // Si le fichier n'existe pas, le créer avec le motif par défaut
        file = fopen(PATTERN_FILE, "w+");
        if (!file) return PATTERN_FILE_ERROR;
        

        // Écrire le motif par défaut dans le fichier
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {
                fputc(default_pattern[i][j], file);
            }
            if(i != 5) fputc('\n', file);
        }   
        fseek(file, 0, SEEK_SET);
    }

    // Lire le fichier et charger le motif dans la fenêtre de jeu
    char line[8]; // 6 characters + \n + \0
	for(int i = 0; i < 6; ++i) {
		if(!fgets(line, sizeof(line), file)) continue;

		for(int j = 0; j < 6; ++j) game_grid[i][j] = line[j] == 'O';
	}

    fclose(file);
    return 1;
}

void glider_gun(grid_t game_grid) {
    // Glider gun pattern using array containing coordinates of living cells

    int glider_gun_pattern[36][2] = {
        {1, 25}, {2, 23}, {2, 25},
        {3, 13}, {3, 14}, {3, 21}, {3, 22}, {3, 35}, {3, 36},
        {4, 12}, {4, 16}, {4, 21}, {4, 22}, {4, 35}, {4, 36},
        {5, 1}, {5, 2}, {5, 11}, {5, 17}, {5, 21}, {5, 22},
        {6, 1}, {6, 2}, {6, 11}, {6, 15}, {6, 17}, {6, 18}, {6, 23}, {6, 25},
        {7, 11}, {7, 17}, {7, 25},
        {8, 12}, {8, 16},
        {9, 13}, {9, 14}
    };

    for (int i = 0; i < 36; i++) {
        game_grid[glider_gun_pattern[i][0]][glider_gun_pattern[i][1]] = 1;
    }
}
