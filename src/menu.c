#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#include <window.h>
#include <game_mode.h>

void print_banniere(void) {
    attron(COLOR_PAIR(2) | A_BLINK); // Vert
    printw("-------------------------------------------------------------------------------- \n");
    attroff(COLOR_PAIR(2) | A_BLINK);

    attron(COLOR_PAIR(1) | A_BLINK); // Blanc
    printw("      __ _____ _____    ____  _____    __    _____    _____ _____ _____  \n");
    attroff(COLOR_PAIR(1) | A_BLINK);

    attron(COLOR_PAIR(2) | A_BLINK); // Vert
    printw("   __|  |   __|  |  |  |    \\|   __|  |  |  |  _  |  |  |  |     |   __| \n");
    attroff(COLOR_PAIR(2) | A_BLINK);

    attron(COLOR_PAIR(1) | A_BLINK); // Blanc
    printw("  |  |  |   __|  |  |  |  |  |   __|  |  |__|     |  |  |  |-   -|   __| \n");
    attroff(COLOR_PAIR(1) | A_BLINK);

    attron(COLOR_PAIR(2) | A_BLINK); // Vert
    printw("  |_____|_____|_____|  |____/|_____|  |_____|__|__|   \\___/|_____|_____| \n");
    attroff(COLOR_PAIR(2) | A_BLINK);

    attron(COLOR_PAIR(1) | A_BLINK); // Blanc
    printw("-------------------------------------------------------------------------------- \n");
    attroff(COLOR_PAIR(1) | A_BLINK);
}


void print_menu(void) {
    printw("\n\nMENU\n");
    printw("-------------------------------------------------------------------------------- \n");
    printw("1. Hasard\n");
    printw("2. Motif par fichier\n");
    printw("3. Canon de planneurs\n");
    printw("-------------------------------------------------------------------------------- \n");
    printw("Entrer votre choix :\n");
}

int choix_user(int choice, grid_t game_grid) {

    switch (choice) {
        case '1':
            random_game(game_grid);
            return 1;
        case '2':
            return file_game(game_grid);
        case '3':
            glider_gun(game_grid);
            return 1;
        default:
            break;
    }

    return 0;
}

int menu(grid_t game_grid) {
    int choice = 0;
    while (1) {
        clear();

        print_banniere();
        print_menu();

        refresh();

        choice = getch();
        int res = choix_user(choice, game_grid);
        if(res) return res;
        usleep(1000000);
    }
}
