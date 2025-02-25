#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#include <window.h>
#include <game.h>


void game(grid_t game_grid) {
    int ch = -1;
    unsigned long int delay = 1000000;
    int generation = 0;
    int manual = 0;

	WINDOW *game_win = newwin(30, 60, 0, 0);
	nodelay(game_win, TRUE);
    box(game_win, 0, 0);
	wrefresh(game_win);

    WINDOW *info_win = newwin(30, 20, 0, 60);
	nodelay(info_win, TRUE);
	wrefresh(info_win);

    while(ch != 'q') {
        switch(ch) {
            case 'q':
                continue;
            case 'e':
                delay *= 2;
                break;
            case 'z':
                delay /= 2;
                break;
            case 's':
                game_update(game_grid);
                generation++;
                break;
            case 'a':
                manual = !manual;
                break;
            default:
                break;
        }

        wclear(game_win);
        print_game(game_grid, game_win);
        box(game_win, 0, 0);
        wrefresh(game_win);

        wclear(info_win);
        print_info(info_win, generation, delay, manual);
        wrefresh(info_win);

        usleep(delay);
        ch = getch();
        if (!manual) {
            game_update(game_grid);
            generation++;
        }
    }

    usleep(3000000);
}

void print_game(grid_t game_grid, WINDOW *game_win) {
    for (int i = 0; i < GAME_H; i++) {
        for (int j = 0; j < GAME_W; j++) {
            if (game_grid[i][j] == 1) {
                mvwaddch(game_win, i + 1, j + 1, 'O');
            } else {
                mvwaddch(game_win, i + 1, j + 1, ' ');
            }
        }
    }
}

void print_info(WINDOW *info_win, int generation, unsigned long int delay, int manual) {
    start_color();
init_pair(1, COLOR_WHITE, COLOR_BLACK); 
init_pair(2, COLOR_GREEN, COLOR_BLACK); 
init_pair(3, COLOR_YELLOW, COLOR_BLACK); 
init_pair(4, COLOR_RED, COLOR_BLACK); 
init_pair(5, COLOR_CYAN, COLOR_BLACK); 
init_pair(6, COLOR_MAGENTA, COLOR_BLACK); 


    // Jaune
    wattron(info_win, COLOR_PAIR(3));
    mvwprintw(info_win, 1, 0, "Le jeu de la vie");
    wattroff(info_win, COLOR_PAIR(3));


    mvwprintw(info_win, 3, 0, "C'est un automate \ncellulaire developpepar  \nJohn Horton Conway\nen 1970");

    // Vert
    wattron(info_win, COLOR_PAIR(2));
     mvwprintw(info_win, 8, 0, "Commandes:");
         wattroff(info_win, COLOR_PAIR(2));



    mvwprintw(info_win, 8 + 1, 0, "%c: auto", 'a');
    mvwprintw(info_win, 8 + 2, 0, "%c: vite", 'z');
    mvwprintw(info_win, 8 + 3, 0, "%c: lent", 'e');
    mvwprintw(info_win, 8 + 4, 0, "%c: step", 's');
    mvwprintw(info_win, 8 + 5, 0, "%c: sortir", 'q');

    // Jaune
    wattron(info_win, COLOR_PAIR(3));
    mvwprintw(info_win, 16, 0, "Generation:");
    wattroff(info_win, COLOR_PAIR(3));

    // Vert
    wattron(info_win, COLOR_PAIR(2));
    mvwprintw(info_win, 17, 0, "%d", generation);
    wattroff(info_win, COLOR_PAIR(2));

    // Blanc
    wattron(info_win, COLOR_PAIR(1));
    mvwprintw(info_win, 19, 0, "Delay:");
    if (manual) {
        mvwprintw(info_win, 20, 0, "Manual");
    } else {
        mvwprintw(info_win, 20, 0, "%lu", delay);
    }
    wattroff(info_win, COLOR_PAIR(1));
}


// Helper function to count live neighbors of a cell at (x, y)
int count_live_neighbors(grid_t game_grid, int x, int y) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue; // Skip the cell itself

            int nx = x + i, ny = y + j;
            if (nx >= 0 && nx < GAME_H && ny >= 0 && ny < GAME_W) {
                count += game_grid[nx][ny];
            }
        }
    }
    return count;
}

// Function to update the game state
void game_update(grid_t game_grid) {
    int new_grid[GAME_H][GAME_W] = {0};


    // Copy new state back to the original grid
    for (int x = 0; x < GAME_H; x++) {
        for (int y = 0; y < GAME_W; y++) {
            new_grid[x][y] = game_grid[x][y];
        }
    }

    for (int x = 0; x < GAME_H; x++) {
        for (int y = 0; y < GAME_W; y++) {
            int live_neighbors = count_live_neighbors(game_grid, x, y);

            if (game_grid[x][y] == 1) {
                // Apply rules for live cells
                if (live_neighbors < 2 || live_neighbors > 3) {
                    new_grid[x][y] = 0;  // Cell dies
                } else {
                    new_grid[x][y] = 1;  // Cell survives
                }
            } else {
                // Apply rule for dead cells
                if (live_neighbors == 3) {
                    new_grid[x][y] = 1;  // Cell becomes alive
                } else {
                    new_grid[x][y] = 0;  // Cell stays dead
                }
            }
        }
    }

    // Copy new state back to the original grid
    for (int x = 0; x < GAME_H; x++) {
        for (int y = 0; y < GAME_W; y++) {
            game_grid[x][y] = new_grid[x][y];
        }
    }
}