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
        wattron(input, COLOR_PAIR(WOR_PAIR));
        write_input(7, 1, "No piece available at this position");
        wattroff(input, COLOR_PAIR(WOR_PAIR));
        return true;
    }
    return false;
}

bool check_same_col(char color1, char color2) {
    if (color1 == color2) {
        wattron(input, COLOR_PAIR(WOR_PAIR));
        write_input(7, 1, "Can't attack on the same color");
        wattroff(input, COLOR_PAIR(WOR_PAIR));
        return true;
    }
    return false;
}

bool check_pawn(char from[], char to[]) {
    wattron(input, COLOR_PAIR(WOR_PAIR));
    write_input(7, 1, "Your piece is a pawn");
    wattroff(input, COLOR_PAIR(WOR_PAIR));
    return true;
}

bool check_king(char from[], char to[]) {
    wattron(input, COLOR_PAIR(WOR_PAIR));
    write_input(7, 1, "Your piece is a king");
    wattroff(input, COLOR_PAIR(WOR_PAIR));
    return false;
}

bool check_queen(char from[], char to[]) {
    wattron(input, COLOR_PAIR(WOR_PAIR));
    write_input(7, 1, "Your piece is a queen");
    wattroff(input, COLOR_PAIR(WOR_PAIR));
    return false;
}

bool check_knight(char from[], char to[]) {
    wattron(input, COLOR_PAIR(WOR_PAIR));
    write_input(7, 1, "Your piece is a knight");
    wattroff(input, COLOR_PAIR(WOR_PAIR));
    return false;
}

bool check_bishop(char from[], char to[]) {
    wattron(input, COLOR_PAIR(WOR_PAIR));
    write_input(7, 1, "Your piece is a bishop");
    wattroff(input, COLOR_PAIR(WOR_PAIR));
    return false;
}

bool check_rook(char from[], char to[]) {
    wattron(input, COLOR_PAIR(WOR_PAIR));
    write_input(7, 1, "Your piece is a rook");
    wattroff(input, COLOR_PAIR(WOR_PAIR));
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