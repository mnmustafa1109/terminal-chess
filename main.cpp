/*  Noman Mustafa Mehar
    PF   PROJECT   2021
    Section : SE-Q 2021
    ROll No : 21I -1235 */
    
#include <locale.h>
#include <ncurses.h>
#include "main.h"
#include "init_win.h"
#include "movement.h"

// declaring board info and input windows
WINDOW* board;
WINDOW* input;
WINDOW* info;
WINDOW* title;
WINDOW* info_title;

// map for storing the board pieces position info
char map[8][8][2];

int main() {
    
    // enabling utf-8 support
    setlocale(LC_ALL, "");
    /* Start curses mode 		  */
    initscr(); 
    // enabling colours colours
    start_color();
    
    // declaring heights and width of windows 
    const int board_width = 84, board_height = 42;
    const int input_width = 45, input_height = 16;
    const int info_width = 45, info_height = 16;
    const int title_width = 45, title_height = 7;
    const int inft_width = 45, inft_height = 3;
    // setting height and width of windows
    board = newwin(board_height, board_width, 0, 0);
    title = newwin(title_height, title_width, 0, 86);
    input = newwin(input_height, input_width, 7, 86);
    info = newwin(info_height, info_width, 26, 86);
    info_title = newwin(inft_height, inft_width, 23, 86);

    // initialzing all windows
    init_win();

    // starting movement function that will ask for movements
    // and move them accordingly
    movement();

    /* End curses mode		  */
    endwin(); 
    return 0;
}