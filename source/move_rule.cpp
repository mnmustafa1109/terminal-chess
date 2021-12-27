/*  Noman Mustafa Mehar
    PF   PROJECT   2021
    Section : SE-Q 2021
    ROll No : 21I -1235 */
    
#include <ncurses.h>
#include <cmath>
#include "../headers/calc.h"
#include "../headers/init_colours.h"
#include "../headers/main.h"
#include "../headers/obs_rec.h"
#include "../headers/piece_man.h"
#include "../headers/write.h"

bool check_empty(char color, char name);
bool check_same_col(char color1, char color2);
bool check_pawn(char from[], char to[]);
bool check_knight(char from[], char to[]);
bool check_queen(char from[], char to[]);
bool check_king(char from[], char to[]);
bool check_bishop(char from[], char to[]);
bool check_rook(char from[], char to[]);
bool check_legal(char from[], char to[]);

// check wehter the colour or the name is empty
bool check_empty(char color, char name) {
    if (color == '-' || name == '-') {
        write(input, WOR_PAIR, 7, 1, "No piece available at this position");
        return false;
    }
    return true;
}

// check wether the color of from position and to postion is the same or not
bool check_same_col(char color1, char color2) {
    if (color1 == color2) {
        write(input, WOR_PAIR, 7, 1, "Can't attack on the same color");
        return false;
    }
    return true;
}

// check wether the move is legal for a pawn
bool check_pawn(char from[], char to[]) {
    // for storing if it is the first move or not
    // to check wether the last move was en passont or not
    static bool first_move;
    // for storing the axis of the last en passont move
    static char en_passant[2];
    bool promo;
    int forward;
    // if last move was enable us for en passont
    if (first_move == true) {
        first_move == false;
        // check wether the current move is a valid
        // en passont move or not
        if (abs(y_cord(en_passant) - y_cord(to)) == 1 &&
            x_cord(en_passant) == x_cord(to)) {
            if (abs(x_cord(en_passant) - x_cord(from)) == 1 &&
                y_cord(en_passant) == y_cord(from)) {
                write(input, WOGN_PAIR, 7, 1, "EN PASSANT move ");
                // capturing or aka removing the side piece of the opposite col
                if (map[y_cord(to) - 2][x_cord(to) - 1][1] == 'p') {
                    remove_piece(y_cord(to) - 1, x_cord(to),'w',1);
                } else if (map[y_cord(to)][x_cord(to) - 1][1] == 'p') {
                    remove_piece(y_cord(to) + 1, x_cord(to),'w',1);
                }
                return true;
            }
        }
    }
    // pawn check rules for white colours piece
    if (get_col(from) == 'w') {
        // check wehter the its the first move or not
        if (y_cord(from) == 7) {
            // make en passont true for next move
            first_move = true;
            en_passant[0] = to[0];
            en_passant[1] = to[1];
            forward = 2;
        } else {
            first_move = false;
            forward = 1;
        }
        // check if it is moving more than the allowed blocks forward
        if (y_cord(from) - y_cord(to) > forward) {
            write(input, WOR_PAIR, 7, 1, "Can not move more than one piece");
            return false;
        }
        // check if it have reac the end of the board
        if (y_cord(to) == 1) {
            write(input, WOGN_PAIR, 6, 1, "You can promote your pawn");
            promo = true;
        }
    } else {
        // check wehter the its the first move or not
        if (y_cord(from) == 2) {
            // make en passont true for next move
            first_move = true;
            en_passant[0] = to[0];
            en_passant[1] = to[1];
            forward = 2;
        } else {
            first_move = false;
            forward = 1;
        }
        // check if it is moving more than the allowed blocks forward
        if (y_cord(to) - y_cord(from) > forward) {
            write(input, WOR_PAIR, 7, 1, "Can not move more than one piece");
            return false;
        }
        // check if it have reac the end of the board
        if (y_cord(to) == 8) {
            write(input, WOGN_PAIR, 6, 1, "You can promote your pawn");
            promo = true;
        }
    }
    // check if it going straight or not
    if (x_cord(from) == x_cord(to)) {
        // check if there is a piece or not
        if (get_col(to) != '-') {
            write(input, WOR_PAIR, 7, 1, "Can not attack from the front");
            return false;
        }
        // checking if there is opposite colour piece
    } else if (abs(x_cord(from) - x_cord(to)) > 1 || (get_col(to) == '-')) {
        write(input, WOR_PAIR, 7, 1, "Can not move here");
        return false;
    }
    // checking if you can promote your pawn or not
    if (promo == true) {
        // asking ofr promotion piece
        write(input, BOTW_PAIR, 7, 1, "Enter q r n or b");
        char choice[1];
        wattron(input, COLOR_PAIR(WOG_PAIR));
        mvwgetnstr(input, 9, 1, choice, 1);
        // error handling ofr pormotion
        while (choice[0] != 'q' && choice[0] != 'r' && choice[0] != 'n' &&
               choice[0] != 'b') {
            write(input, WOG_PAIR, 9, 1, "   ");
            write(input, WOR_PAIR, 8, 1, "Please enter correct piece");
            wattron(input, COLOR_PAIR(WOG_PAIR));
            mvwgetnstr(input, 9, 1, choice, 1);
        }
        wattroff(input, COLOR_PAIR(WOG_PAIR));
        // updating piece for promotion in the map array
        map[y_cord(from) - 1][x_cord(from) - 1][1] = choice[0];
    }
    return true;
}

// checking if queen move is legal or not
bool check_queen(char from[], char to[]) {
    // as queen can go straight and diagnal
    if (!(check_rook(from, to) || check_bishop(from, to))) {
        write(input, WOR_PAIR, 7, 1, "QUEEN can not move in this way");
        return false;
    }
    write(input, WOG_PAIR, 7, 1, "                                  ");
    return true;
}

// check wether knight move is legal or not
bool check_knight(char from[], char to[]) {
    if (abs(y_cord(from) - y_cord(to)) < 1 ||
        abs(x_cord(from) - x_cord(to)) < 1 ||
        abs(y_cord(from) - y_cord(to)) > 2 ||
        abs(x_cord(from) - x_cord(to)) > 2 ||
        abs(y_cord(from) - y_cord(to)) == abs(x_cord(from) - x_cord(to))) {
        write(input, WOR_PAIR, 7, 1, "Knight can not move in this way");
        return false;
    }
    return true;
}

// check wether bishop move is legal or not
bool check_bishop(char from[], char to[]) {
    if (abs(x_cord(from) - x_cord(to)) != abs(y_cord(from) - y_cord(to))) {
        write(input, WOR_PAIR, 7, 1, "Bishop can not move in this way");
        return false;
    }
    return true;
}

// check wether rook move is legal or not
bool check_rook(char from[], char to[]) {
    if (x_cord(from) != x_cord(to) && y_cord(from) != y_cord(to)) {
        write(input, WOR_PAIR, 7, 1, "Rook can not move in this way");
        return false;
    }
    if (x_cord(from) == x_cord(to) && y_cord(from) == y_cord(to)) {
        write(input, WOR_PAIR, 7, 1, "Rook can not move in this way");
        return false;
    }
    return true;
}

// check wether king move is legal or not
bool check_king(char from[], char to[]) {
    if (abs(y_cord(from) - y_cord(to)) > 1 ||
        abs(x_cord(from) - x_cord(to)) > 1) {
        write(input, WOR_PAIR, 7, 1, "Knight can not move in this way");
        return false;
    }
    return true;
}


// taking the movement and checking legal moves depending on the piece
bool check_legal(char from[], char to[]) {
    switch (get_name(from)) {
        case 'p':
            return check_pawn(from, to) && check_path(from, to);
            break;
        case 'k':
            return check_king(from, to);
            break;
        case 'q':
            return check_queen(from, to) && check_path(from, to);
            break;
        case 'b':
            return check_bishop(from, to) && check_path(from, to);
            break;
        case 'n':
            return check_knight(from, to);
            break;
        case 'r':
            return check_rook(from, to) && check_path(from, to);
            break;
    }

    return true;
}