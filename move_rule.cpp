#include <ncurses.h>
#include <cmath>
#include "calc.h"
#include "general.h"
#include "init_colours.h"
#include "main.h"

bool check_empty(char color, char name);
bool check_same_col(char color1, char color2);
bool check_pawn(char from[], char to[]);
bool check_knight(char from[], char to[]);
bool check_queen(char from[], char to[]);
bool check_king(char from[], char to[]);
bool check_bishop(char from[], char to[]);
bool check_rook(char from[], char to[]);
bool check_legal(char from[], char to[]);

bool check_empty(char color, char name) {
    if (color == '-' || name == '-') {
        write_input(WOR_PAIR, 7, 1, "No piece available at this position");
        return false;
    }
    return true;
}

bool check_same_col(char color1, char color2) {
    if (color1 == color2) {
        write_input(WOR_PAIR, 7, 1, "Can't attack on the same color");
        return false;
    }
    return true;
}

bool check_pawn(char from[], char to[]) {
    static bool first_move;
    static char en_passant[2];
    bool promo;
    int forward;
    if (first_move == true){
        first_move == false;
        if (abs(y_cord(en_passant)-y_cord(to))==1 && x_cord(en_passant) == x_cord(to)){
            if (abs(x_cord(en_passant)-x_cord(from))==1 && y_cord(en_passant) == y_cord(from)){
            write_input(WOGN_PAIR, 7, 1, "EN PASSANT move ");
            return true;
            }
        }
    }
    if (get_col(from) == 'w') {
        if (y_cord(from) == 7) {
            first_move = true;
            en_passant[0] = to[0];
            en_passant[1] = to[1];
            forward = 2;
        } else {
            first_move = false;
            forward = 1;
        }
        if (y_cord(from) - y_cord(to) > forward) {
            write_input(WOR_PAIR, 7, 1, "Can not move more than one piece");
            return false;
        }
        if (y_cord(to) == 1) {
            write_input(WOGN_PAIR, 6, 1, "You can promote your pawn");
            promo = true;
        }
    } else {
        if (y_cord(from) == 2) {
            first_move = true;
            en_passant[0] = to[0];
            en_passant[1] = to[1];
            forward = 2;
        } else {
            first_move = false;
            forward = 1;
        }
        if (y_cord(to) - y_cord(from) > forward) {
            write_input(WOR_PAIR, 7, 1, "Can not move more than one piece");
            return false;
        }
        if (y_cord(to) == 8) {
            write_input(WOGN_PAIR, 6, 1, "You can promote your pawn");
            promo = true;
        }
    }
    if (x_cord(from) == x_cord(to)) {
        if (get_col(to) != '-') {
            write_input(WOR_PAIR, 7, 1, "Can not attack from the front");
            return false;
        }
    } else if (abs(x_cord(from) - x_cord(to)) > 1 || (get_col(to) == '-')) {
        write_input(WOR_PAIR, 7, 1, "Can not move here");
        return false;
    }
    if (promo == true) {
        write_input(BOTW_PAIR, 7, 1, "Enter q r n or b");
        char choice[1];
        wattron(input, COLOR_PAIR(WOG_PAIR));
        mvwgetnstr(input, 9, 1, choice, 1);
        while (choice[0] != 'q' && choice[0] != 'r' && choice[0] != 'n' &&
               choice[0] != 'b') {
            write_input(WOG_PAIR, 9, 1, "   ");
            write_input(WOR_PAIR, 8, 1, "Please enter correct piece");
            wattron(input, COLOR_PAIR(WOG_PAIR));
            mvwgetnstr(input, 9, 1, choice, 1);
        }
        wattroff(input, COLOR_PAIR(WOG_PAIR));
        map[y_cord(from) - 1][x_cord(from) - 1][1] = choice[0];
    }
    return true;
}

bool check_king(char from[], char to[]) {
    if (abs(y_cord(from) - y_cord(to)) > 1 ||
        abs(x_cord(from) - x_cord(to)) > 1) {
        write_input(WOR_PAIR, 7, 1, "Knight can not move in this way");
        return false;
    }
    return true;
}

bool check_queen(char from[], char to[]) {
    if (!(check_rook(from, to) || check_bishop(from, to))) {
        write_input(WOR_PAIR, 7, 1, "QUEEN can not move in this way");
        return false;
    }
    write_input(WOGN_PAIR, 7, 1, "QUEEN can move in this way   ");
    return true;
}

bool check_knight(char from[], char to[]) {
    if (abs(y_cord(from) - y_cord(to)) < 1 ||
        abs(x_cord(from) - x_cord(to)) < 1 ||
        abs(y_cord(from) - y_cord(to)) > 2 ||
        abs(x_cord(from) - x_cord(to)) > 2 ||
        abs(y_cord(from) - y_cord(to)) == abs(x_cord(from) - x_cord(to))) {
        write_input(WOR_PAIR, 7, 1, "Knight can not move in this way");
        return false;
    }
    return true;
}

bool check_bishop(char from[], char to[]) {
    if (abs(x_cord(from) - x_cord(to)) != abs(y_cord(from) - y_cord(to))) {
        write_input(WOR_PAIR, 7, 1, "Bishop can not move in this way");
        return false;
    }
    return true;
}

bool check_rook(char from[], char to[]) {
    if (x_cord(from) != x_cord(to) && y_cord(from) != y_cord(to)) {
        write_input(WOR_PAIR, 7, 1, "Rook can not move in this way");
        return false;
    }
    if (x_cord(from) == x_cord(to) && y_cord(from) == y_cord(to)) {
        write_input(WOR_PAIR, 7, 1, "Rook can not move in this way");
        return false;
    }
    return true;
}

bool check_legal(char from[], char to[]) {
    switch (get_name(from)) {
        case 'p':
            return check_pawn(from, to);
            break;
        case 'k':
            return check_king(from, to);
            break;
        case 'q':
            return check_queen(from, to);
            break;
        case 'b':
            return check_bishop(from, to);
            break;
        case 'n':
            return check_knight(from, to);
            break;
        case 'r':
            return check_rook(from, to);
            break;
    }

    return true;
}