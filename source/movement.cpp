/*  Noman Mustafa Mehar
    PF   PROJECT   2021
    Section : SE-Q 2021
    ROll No : 21I -1235 */

#include <ncurses.h>
#include "../headers/calc.h"
#include "../headers/init_colours.h"
#include "../headers/main.h"
#include "../headers/move_piece.h"
#include "../headers/move_rule.h"
#include "../headers/score.h"
#include "../headers/write.h"
#include "../headers/history.h"

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
    time_t now = time(0);
    tm* start_time = localtime(&now) ;
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
            if (turn_ln > 22) {
                turn_ln = 1;
            }
            
            // writing the currwent move in the info board
            write_hstr(start_time, turn_ln,turn_no,to,current_turn,from);
            
            // updating the score
            if (score('w') > 0) {
                write(info, BOTW_PAIR, 12, 23, "                    ");
                write(info, BOTW_PAIR, 13, 23, " WHITE WINNING : +%d ",
                      score('w'));
                write(info, BOTW_PAIR, 14, 23, "                    ");
            } else if (score('b') > 0) {
                write(info, WOB_PAIR, 12, 23, "                    ");
                write(info, WOB_PAIR, 13, 23, " BLACK WINNING : +%d ",
                      score('b'));
                write(info, WOB_PAIR, 14, 23, "                    ");
            } else {
                write(info, WOW_PAIR, 12, 23, "                    ");
                write(info, WOW_PAIR, 13, 23, "        DRAW        ");
                write(info, WOW_PAIR, 14, 23, "                    ");
            }
            
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
