#include <ncurses.h>
#include "calc.h"
#include "write.h"
#include "init_colours.h"
#include "main.h"
#include "piece.h"
using namespace std;

void print_piece(int y, int x, char color, char piece);
void remove_piece(int y, int x);

// function that print the piece
// it also add the piece info in the main map array
void print_piece(int y, int x, char color, char piece) {
    // check wether depending on the axis  and the colour info 
    // the colour which it will print the piece
    const int atr = ((x + y) % 2) ? ((color == 'w' ? WOG_PAIR : BOG_PAIR))
                                  : ((color == 'w' ? WOW_PAIR : BOW_PAIR));

    // it will write the piece string array which consist of five lines
    for (size_t i = 0; i < 5; i++) {
        write(board,atr, y_axis(y) + i, x_axis(x),
                    return_piece(piece)[i].c_str());
    }

    wrefresh(board);

    // updating info the the main map
    map[y - 1][x - 1][0] = color;
    map[y - 1][x - 1][1] = piece;
}

// function to remove the piece it will also update value
// in the main array map of pieces
void remove_piece(int y, int x) {

    // checking which colour to print in the background
    // to maintain the checkerboard pattern
    const int atr = ((x + y) % 2) ? DGREYBG_PAIR : LGREYBG_PAIR;

    // print the background consisting of five lines
    for (size_t i = 0; i < 5; i++) {
        write(board,atr, y_axis(y) + i, x_axis(x), "██████████");
    }
    wrefresh(board);

    // update the current info in the main map array
    map[y - 1][x - 1][0] = '-';
    map[y - 1][x - 1][1] = '-';
}
