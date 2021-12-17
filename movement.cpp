#include <ncurses.h>
#include "calc.h"
#include "move_rule.h"
#include "piece_man.h"
#include "general.h"
#include "main.h"
#include "init_colours.h"

void movement();
void ask_cordinates(int y, int x, char* cord);
void move_piece(char from[], char to[]);

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

        write_input(8, 1, "The piece at this position is %c %c ",
                    map[y_cord(from) - 1][x_cord(from) - 1][0],
                    map[y_cord(from) - 1][x_cord(from) - 1][1]);

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

void move_piece(char from[], char to[]) {
    if (check_empty(get_name(from), get_col(from)) ||
        check_same_col(get_col(from), get_col(to))) {
        return;
    }
    if (check_legal(from, to) == true) {
        print_piece(y_cord(to), x_cord(to), get_col(from), get_name(from));
        remove_piece(y_cord(from), x_cord(from));
    }
}
