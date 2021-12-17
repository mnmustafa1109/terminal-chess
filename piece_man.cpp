#include <ncurses.h>
#include "calc.h"
#include "init_colours.h"
#include "main.h"
#include "piece.h"
using namespace std;

void print_piece(int y, int x, char color, char piece );
void remove_piece(int y, int x);

void print_piece(int y, int x, char color, char piece ) {
    const int atr = ((x + y) % 2) ? ((color == 'w' ? WOG_PAIR : BOG_PAIR))
                                  : ((color == 'w' ? WOW_PAIR : BOW_PAIR));

    wattron(board, COLOR_PAIR(atr));

    for (size_t i = 0; i < 5; i++) {
        mvwprintw(board, y_axis(y) + i, x_axis(x),
                  return_piece(piece)[i].c_str());
    }
    wattroff(board, COLOR_PAIR(atr));

    wrefresh(board);
    map[y - 1][x - 1][0] = color;
    map[y - 1][x - 1][1] = piece;
}

void remove_piece(int y, int x) {
    const int atr = ((x + y) % 2) ? DGREYBG_PAIR : LGREYBG_PAIR;
    wattron(board, COLOR_PAIR(atr));
    for (size_t i = 0; i < 5; i++) {
        mvwprintw(board, y_axis(y) + i, x_axis(x), "██████████");
    }
    wattroff(board, COLOR_PAIR(atr));
    wrefresh(board);
    map[y - 1][x - 1][0] = '-';
    map[y - 1][x - 1][1] = '-';
}
