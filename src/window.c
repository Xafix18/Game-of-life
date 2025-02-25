#include <ncurses.h>


// Ncurses init function. this must init colors, remove echo, ecc..
void init_ncurses(void) {
    initscr();
    
    // Disable line buffering
    cbreak();
    // Disable echo of characters inputted by the user
    noecho();
    // remove delay from getch
    nodelay(stdscr, TRUE);

    keypad(stdscr, TRUE);
    curs_set(FALSE);
 
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);
    init_pair(4, COLOR_YELLOW, COLOR_BLACK);
    init_pair(5, COLOR_BLUE, COLOR_BLACK);
    init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(7, COLOR_CYAN, COLOR_BLACK);
}