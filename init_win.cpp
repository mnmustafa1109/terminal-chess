#include <ncurses.h>
#include "init_colours.h"
#include "main.h"
#include "piece_man.h"
#include "write.h"

void init_piece();
void init_board();
void init_input();
void init_win();

// initializing all the pieces with their initial postion
// according to how chess rules are
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

// initializing the chess board
void init_board() {
    // giving the board background
    wbkgd(board, COLOR_PAIR(DGREYBG_PAIR));
    wattron(board, COLOR_PAIR(WOG_PAIR));
    // board border
    box(board, 0, 0);
    // printing the axis on the board
    for (size_t i = 0; i < 8; i++) {
        mvwprintw(board, (i * 5) + 3, 83, "%d", 8 - i);
        mvwprintw(board, (i * 5) + 3, 0, "%d", 8 - i);
        mvwprintw(board, 0, (i * 10) + 6, "%c", 65 + i);
        mvwprintw(board, 41, (i * 10) + 6, "%c", 65 + i);
    }
    wrefresh(board);
    wattroff(board, COLOR_PAIR(WOG_PAIR));
    // printing the checkboard pattern on the board
    for (size_t i = 0; i < 8; i++) {
        const int temp = (i % 2 ? 1 : 0);
        for (size_t j = 0; j < 4; j++) {
            for (size_t k = 1; k < 6; k++) {
                write(board, LGREYBG_PAIR, (i * 5) + k,
                      (j * 20) + (temp * 10) + 2, "██████████");
            }
        }
    }
}

// initializing the input window
void init_input() {
    // setting the background
    wbkgd(input, COLOR_PAIR(DGREYBG_PAIR));
    wattron(input, COLOR_PAIR(WOG_PAIR));
    // setting the boarder
    box(input, 0, 0);
    wrefresh(input);
    wattroff(input, COLOR_PAIR(WOG_PAIR));
}

// initializing the info windows
void init_info() {
    // setting background
    wbkgd(info, COLOR_PAIR(DGREYBG_PAIR));
    wattron(info, COLOR_PAIR(WOG_PAIR));
    // setting borders
    box(info, 0, 0);
    wrefresh(info);
    wattroff(info, COLOR_PAIR(WOG_PAIR));
    write(info, BOTW_PAIR, 7, 23, "                    ");
    write(info, BOTW_PAIR, 8, 23, "  White Score :    ");
    write(info, BOTW_PAIR, 9, 23, "                    ");
    write(info, WOB_PAIR, 11, 23, "                    ");
    write(info, WOB_PAIR, 12, 23, "  Black Score :    ");
    write(info, WOB_PAIR, 13, 23, "                    ");
    write(info, WOB_PAIR, 12, 41, "  ");
    write(info, BOTW_PAIR, 8, 41, "  ");
}

// initializing the info windows
void init_title() {
    // setting background
    wbkgd(title, COLOR_PAIR(TWBG_PAIR));
    wattron(title, COLOR_PAIR(BOTW_PAIR));
    // setting borders
    box(title, 0, 0);
    wrefresh(title);
    write(title, BOTW_PAIR, 1, 3, " CCC    H  H    EEEE     SSS      SSS  ");
    write(title, BOTW_PAIR, 2, 3, "C       H  H    E       S        S     ");
    write(title, BOTW_PAIR, 3, 3, "C       HHHH    EEE      SSS      SSS  ");
    write(title, BOTW_PAIR, 4, 3, "C       H  H    E           S        S ");
    write(title, BOTW_PAIR, 5, 3, " CCC    H  H    EEEE    SSSS     SSSS  ");
    wattroff(title, COLOR_PAIR(BOTW_PAIR));
}

// initializing the info windows
void init_inft() {
    // setting background
    wbkgd(info_title, COLOR_PAIR(TWBG_PAIR));
    wattron(info_title, COLOR_PAIR(BOTW_PAIR));
    // setting borders
    box(info_title, 0, 0);
    wrefresh(info_title);
    write(info_title, BOTW_PAIR, 1, 20, "INFO");
    wattroff(info_title, COLOR_PAIR(BOTW_PAIR));
}

void init_win() {
    // initializing the colours
    init_colours();
    refresh();

    // calling function to initialize all three windows
    init_title();
    init_board();
    init_piece();
    init_input();
    init_info();
    init_inft();

    // giving value null aka '-' to other part of the map
    // where there are no pieces
    for (size_t i = 2; i < 6; i++) {
        for (size_t j = 0; j < 8; j++) {
            map[i][j][0] = '-';
            map[i][j][1] = '-';
        }
    }
}