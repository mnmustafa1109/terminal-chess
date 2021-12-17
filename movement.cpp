#include <ncurses.h>
#include "main.h"
#include "init_colours.h"
#include "move_piece.h"
#include "general.h"

void movement();
void ask_cordinates(int y, int x, char* cord);

void movement() {
    char to[3];
    char from[3];
    to[2] = from[2] = '\0';
    curs_set(1);
    while (1) {
        write_input(1, 1, "Which piece do you wanna move");

        ask_cordinates(3, 1, from);

        write_input(4, 1, "Where do you want to move it");

        ask_cordinates(6, 1, to);

        move_piece(from, to);

        write_input(9, 1, "Press enter to continue or q to quite");
        char choice[1];
        mvwgetnstr(input, 11, 1, choice, 1);
        if (choice[0] == 'q') {
            break;
        }
        wclear(input);
        box(input, 0, 0);
        wrefresh(input);
    }
}

void ask_cordinates(int y, int x, char* cord) {
    mvwgetnstr(input, y, x, cord, 2);
    while (cord[1] < 49 || cord[1] > 57 || cord[0] < 97 || cord[0] > 104) {
        write_input(y, x, "   ");
        wattron(input, COLOR_PAIR(WOR_PAIR));
        write_input(y - 1, 1, "Please enter correct cordinates");
        wattroff(input, COLOR_PAIR(WOR_PAIR));
        mvwgetnstr(input, y, x, cord, 2);
    }
}

