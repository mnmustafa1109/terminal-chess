#include <ncurses.h>
#include "init_colours.h"
#include "main.h"
#include "piece_man.h"
#include "general.h"

void init_piece();
void init_board();
void init_input();
void init_win();

void init_piece() {
    print_piece(1, 1, 'b', 'r');
    print_piece(1, 8, 'b', 'r');
    print_piece(1, 3, 'b', 'b');
    print_piece(1, 6, 'b', 'b');
    print_piece(1, 2, 'b', 'n');
    print_piece(1, 7, 'b', 'n');
    print_piece(1, 4, 'b', 'q');
    print_piece(1, 5, 'b', 'k');
    print_piece(8, 1, 'w', 'r');
    print_piece(8, 8, 'w', 'r');
    print_piece(8, 3, 'w', 'b');
    print_piece(8, 6, 'w', 'b');
    print_piece(8, 2, 'w', 'n');
    print_piece(8, 7, 'w', 'n');
    print_piece(8, 4, 'w', 'q');
    print_piece(8, 5, 'w', 'k');
    for (size_t i = 1; i < 9; i++) {
        print_piece(2, i, 'b', 'p');
        print_piece(7, i, 'w', 'p');
    }
}

void init_board() {
    refresh();
    wbkgd(board, COLOR_PAIR(DGREYBG_PAIR));
    wattron(board, COLOR_PAIR(WOG_PAIR));
    box(board, 0, 0);
    for (size_t i = 0; i < 8; i++) {
        mvwprintw(board, (i * 5) + 3, 83, "%d", 8 - i);
        mvwprintw(board, (i * 5) + 3, 0, "%d", 8 - i);
        mvwprintw(board, 0, (i * 10) + 6, "%c", 65 + i);
        mvwprintw(board, 41, (i * 10) + 6, "%c", 65 + i);
    }
    wrefresh(board);
    wattroff(board, COLOR_PAIR(WOG_PAIR));
    for (size_t i = 0; i < 8; i++) {
        const int temp = (i % 2 ? 1 : 0);
        for (size_t j = 0; j < 4; j++) {
            for (size_t k = 1; k < 6; k++) {
                write_board(LGREYBG_PAIR,(i * 5) + k,(j * 20) + (temp * 10) + 2,"██████████");
            }
        }
    }
}

void init_input() {
    wbkgd(input, COLOR_PAIR(DGREYBG_PAIR));
    wattron(input, COLOR_PAIR(WOG_PAIR));
    box(input, 0, 0);
    wrefresh(input);
    wattroff(input, COLOR_PAIR(WOG_PAIR));
}

void init_win() {
    init_colours();
    refresh();
    init_board();
    init_piece();
    init_input();
    for (size_t i = 2; i < 6; i++) {
        for (size_t j = 0; j < 8; j++) {
            map[i][j][0] = '-';
            map[i][j][1] = '-';
        }
    }
}