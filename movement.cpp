#include <ncurses.h>
#include "calc.h"
#include "general.h"
#include "init_colours.h"
#include "main.h"
#include "move_piece.h"
#include "move_rule.h"

void movement();
void ask_cordinates(int y, int x, char* cord);

char refresh_turn() {
    write_input(WOG_PAIR, 9, 1, "Press enter to continue or q to quite");
    char choice[1];
    wattron(input, COLOR_PAIR(WOG_PAIR));
    mvwgetnstr(input, 11, 1, choice, 1);
    werase(input);
    box(input, 0, 0);
    wrefresh(input);
    wattroff(input, COLOR_PAIR(WOG_PAIR));
    return choice[0];
}

void movement() {
    char to[3];
    char from[3];
    to[2] = from[2] = '\0';
    bool current_turn = true;
    curs_set(1);

    while (1) {
        if (refresh_turn() == 'q') {
            break;
        }
        write_input(get_turn_col(current_turn), 1, 33, "          ");
        write_input(get_turn_col(current_turn), 2, 33, "   TURN   ");
        write_input(get_turn_col(current_turn), 3, 33, "          ");
        write_input(WOG_PAIR, 1, 1, "Which piece do you wanna move");
        ask_cordinates(3, 1, from);
        if (check_empty(get_name(from), get_col(from))) {
            continue;
        }
        if (col_bool(get_col(from)) == current_turn) {
            current_turn = !current_turn;
        } else {
            write_input(WOR_PAIR, 7, 1, "Its not your turn");
            continue;
        }
        write_input(WOG_PAIR, 4, 1, "Where do you want to move it");

        ask_cordinates(6, 1, to);

        move_piece(from, to);
    }
}

void ask_cordinates(int y, int x, char* cord) {
    wattron(input, COLOR_PAIR(WOG_PAIR));
    mvwgetnstr(input, y, x, cord, 2);
    while (cord[1] < 49 || cord[1] > 57 || cord[0] < 97 || cord[0] > 104) {
        write_input(WOG_PAIR, y, x, "   ");
        write_input(WOR_PAIR, y - 1, 1, "Please enter correct cordinates");
        wattron(input, COLOR_PAIR(WOG_PAIR));
        mvwgetnstr(input, y, x, cord, 2);
    }
    wattroff(input, COLOR_PAIR(WOG_PAIR));
}
