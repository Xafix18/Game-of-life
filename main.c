#include <menu.h>
#include <window.h>
#include <game_mode.h>
#include <stdlib.h>
#include <time.h>
#include <game.h>

// On use pas malloc , donc on a pas besoin de return -2. 

int main() {
    srand(time(NULL));

    grid_t game_grid = {0};

    init_ncurses();

    if(COLS < 80 || LINES < 30) {
        endwin();
        printf("Terminal trop petit\n");
        return TERMINAL_SIZE_ERROR;
    }

    int menu_res = menu(game_grid);
    if(menu_res == PATTERN_FILE_ERROR) {
        endwin();
        printf("Error opening file\n");
        return menu_res;
    }

    game(game_grid);

    endwin();
    return 0;   
}
