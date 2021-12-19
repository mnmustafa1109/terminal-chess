#include <ncurses.h>
#include "calc.h"
#include "init_colours.h"
#include "main.h"
#include "move_piece.h"
#include "move_rule.h"
#include "piece.h"
#include "score.h"
#include "write.h"

void movement();
void ask_cordinates(int y, int x, char* cord);

// ask user if he wants to conitue or not
// and refresh the info board
char refresh_turn() {
    write(input, WOG_PAIR, 10, 1, "Press enter to continue or q to quite");
    char choice[1];
    wattron(input, COLOR_PAIR(WOG_PAIR));
    mvwgetnstr(input, 11, 1, choice, 1);
    werase(input);
    box(input, 0, 0);
    wrefresh(input);
    wattroff(input, COLOR_PAIR(WOG_PAIR));
    return choice[0];
}

// movement function that amange moving , asking pieces etc and updating info
// table
void movement() {
    char to[3];
    char from[3];
    to[2] = from[2] = '\0';
    // boolean use for storing current player turn
    // white for true and black for false
    bool current_turn = true;
    curs_set(1);
    int turn_ln = 1;
    int turn_no = 1;
    while (1) {
        if (refresh_turn() == 'q') {
            break;
        }
        // displaying current player turn on the info board
        write(info, get_turn_col(current_turn), 1, 33, "          ");
        write(info, get_turn_col(current_turn), 2, 33, "   TURN   ");
        write(info, get_turn_col(current_turn), 3, 33, "          ");
        // asking which puiece he wanna move
        write(input, WOG_PAIR, 1, 1, "Which piece do you wanna move");
        ask_cordinates(3, 1, from);
        // checking if the piece is empty or not
        if (!check_empty(get_name(from), get_col(from))) {
            continue;
        }
        // check if its the turn of the piece choose or not
        if (col_bool(get_col(from)) != current_turn) {
            write(input, WOR_PAIR, 7, 1, "Its not your turn");
            continue;
        }

        // asking whhere he wanna move the piece
        write(input, WOG_PAIR, 4, 1, "Where do you want to move it");
        ask_cordinates(6, 1, to);

        // if for wether the move was legal and sucessful or not
        if (move_piece(from, to)) {
            // if for reprinting from line 1 if info board become full
            if (turn_ln > 23) {
                turn_ln = 1;
            }
            // writing the currwent move in the info board
            write(info, WOG_PAIR, turn_ln, 2, to_string(turn_no).c_str());
            write(info, WOG_PAIR, turn_ln, 3, ".");
            write(info, WOG_PAIR, turn_ln, 5,
                  return_char(get_name(to), current_turn).c_str());
            write(info, WOG_PAIR, turn_ln, 7, from);
            write(info, WOG_PAIR, turn_ln, 10, "→");
            write(info, WOG_PAIR, turn_ln, 12, to);
            // updating the score
            write(info, WOB_PAIR, 12, 41, "  ");
            write(info, BOTW_PAIR, 8, 41, "  ");
            write(info, BOTW_PAIR, 8, 41, to_string(score('w')).c_str());
            write(info, WOB_PAIR, 12, 41, to_string(score('b')).c_str());
            // changing the turn colour
            current_turn = !current_turn;
            // making current line increase
            turn_ln++;
            turn_no++;
        }
    }
}

// function to ask cordinate from the user to move
void ask_cordinates(int y, int x, char* cord) {
    wattron(input, COLOR_PAIR(WOG_PAIR));
    // getting the cordinates
    mvwgetnstr(input, y, x, cord, 2);
    // error handling for the user to enter the right cordinate
    while (cord[1] < 49 || cord[1] > 57 || cord[0] < 97 || cord[0] > 104) {
        write(input, WOG_PAIR, y, x, "   ");
        write(input, WOR_PAIR, y - 1, 1, "Please enter correct cordinates");
        wattron(input, COLOR_PAIR(WOG_PAIR));
        mvwgetnstr(input, y, x, cord, 2);
    }
    wattroff(input, COLOR_PAIR(WOG_PAIR));
}
