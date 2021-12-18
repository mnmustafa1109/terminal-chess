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
        return true;
    }
    return false;
}

bool check_same_col(char color1, char color2) {
    if (color1 == color2) {
        write_input(WOR_PAIR, 7, 1, "Can't attack on the same color");
        return true;
    }
    return false;
}

bool check_pawn(char from[], char to[]) {
    bool first_move;
    bool promo;
    int forward;
    if (get_col(from) == 'w') {
        if (y_cord(from) == 7) {
            first_move = true;
            forward = 2;
        } else {
            first_move = false;
            forward = 1;
        }
    } else {
        if (y_cord(from) == 2) {
            first_move = true;
            forward = 2;
        } else {
            first_move = false;
            forward = 1;
        }
    }
    if (get_col(from) == 'w') {
        if (y_cord(from) - y_cord(to) > forward) {
            write_input(WOR_PAIR, 7, 1, "Can not move more than one piece");
            return false;
        }
    } else {
        if (y_cord(to) - y_cord(from) > forward) {
            write_input(WOR_PAIR, 7, 1, "Can not move more than one piece");
            return false;
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
    if (get_col(from) == 'w') {
        if (y_cord(to) == 1) {
            write_input(WOGN_PAIR, 6, 1, "You can promote your pawn");
            promo = true;
        }
    } else {
        if (y_cord(to) == 8) {
            write_input(WOGN_PAIR, 6, 1, "You can promote your pawn");
            promo = true;
        }
    }
    if (promo == true) {
        write_input(BOTW_PAIR, 7, 1, "Enter q r n or b");
        char choice[1];
        wattron(input, COLOR_PAIR(WOG_PAIR));
        mvwgetnstr(input, 9, 1,choice, 1);
        while (choice[0] != 'q' && choice[0] != 'r' && choice[0] != 'n' && choice[0] != 'b' ) {
            write_input(WOG_PAIR, 9, 1, "   ");
            write_input(WOR_PAIR, 8, 1, "Please enter correct piece");
            wattron(input, COLOR_PAIR(WOG_PAIR));
            mvwgetnstr(input, 9, 1, choice, 1);
        }
        wattroff(input, COLOR_PAIR(WOG_PAIR));
        map[y_cord(from) - 1][x_cord(from) - 1][1] = choice[0];
    }
    write_input(WOR_PAIR, 9, 1, "Your piece is a pawn");
    return true;
}

bool check_king(char from[], char to[]) {
    write_input(WOR_PAIR, 7, 1, "Your piece is a king");
    return false;
}

bool check_queen(char from[], char to[]) {
    write_input(WOR_PAIR, 7, 1, "Your piece is a queen");
    return false;
}

bool check_knight(char from[], char to[]) {
    write_input(WOR_PAIR, 7, 1, "Your piece is a knight");
    return false;
}

bool check_bishop(char from[], char to[]) {
    write_input(WOR_PAIR, 7, 1, "Your piece is a bishop");
    return false;
}

bool check_rook(char from[], char to[]) {
    write_input(WOR_PAIR, 7, 1, "Your piece is a rook");
    return false;
}

bool check_legal(char from[], char to[]) {
    switch (get_name(from)) {
        case 'p':
            return check_pawn(from, to);
            break;
        case 'k':
            check_king(from, to);
            break;
        case 'q':
            check_queen(from, to);
            break;
        case 'b':
            check_bishop(from, to);
            break;
        case 'n':
            check_knight(from, to);
            break;
        case 'r':
            check_rook(from, to);
            break;
    }

    return true;
}