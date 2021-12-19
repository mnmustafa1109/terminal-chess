#include <ncurses.h>
#include "main.h"

void write_input(int col, int y, int x, const char* fmt, ...) {
    wmove(input, y, x);
    va_list args;
    va_start(args, fmt);
    wattron(input, COLOR_PAIR(col));
    vw_printw(input, fmt, args);
    va_end(args);
    wrefresh(input);
    wattroff(input, COLOR_PAIR(col));
}

void write_board(int col, int y, int x, const char* fmt, ...) {
    wmove(board, y, x);
    va_list args;
    va_start(args, fmt);
    wattron(board, COLOR_PAIR(col));
    vw_printw(board, fmt, args);
    va_end(args);
    wrefresh(board);
    wattroff(board, COLOR_PAIR(col));
}

void write_info(int col, int y, int x, const char* fmt, ...) {
    wmove(info, y, x);
    va_list args;
    va_start(args, fmt);
    wattron(info, COLOR_PAIR(col));
    vw_printw(info, fmt, args);
    va_end(args);
    wrefresh(info);
    wattroff(info, COLOR_PAIR(col));
}