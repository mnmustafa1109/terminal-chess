#include <ncurses.h>
#include "main.h"
#include "calc.h"
#include "general.h"
#include "init_colours.h"

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
        write_input(WOR_PAIR,7, 1, "No piece available at this position");
        return true;
    }
    return false;
}

bool check_same_col(char color1, char color2) {
    if (color1 == color2) {
        write_input(WOR_PAIR,7, 1, "Can't attack on the same color");
        return true;
    }
    return false;
}

bool check_pawn(char from[], char to[]) {
    
    write_input(WOR_PAIR,7, 1, "Your piece is a pawn");
    return true;
}

bool check_king(char from[], char to[]) {
    write_input(WOR_PAIR,7, 1, "Your piece is a king");
    return false;
}

bool check_queen(char from[], char to[]) {
    write_input(WOR_PAIR,7, 1, "Your piece is a queen");
    return false;
}

bool check_knight(char from[], char to[]) {
    write_input(WOR_PAIR,7, 1, "Your piece is a knight");
    return false;
}

bool check_bishop(char from[], char to[]) {
    write_input(WOR_PAIR,7, 1, "Your piece is a bishop");
    return false;
}

bool check_rook(char from[], char to[]) {
    write_input(WOR_PAIR,7, 1, "Your piece is a rook");
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