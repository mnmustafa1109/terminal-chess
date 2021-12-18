#include <ncurses.h>
#include "main.h"
void write_input(int col , int y, int x, const char* fmt, ...) {
    wmove(input, y, x);
    va_list args;
    va_start(args, fmt);
    wattron(input, COLOR_PAIR(col));
    vw_printw(input, fmt, args);
    va_end(args);
    wrefresh(input);
    wattroff(input, COLOR_PAIR(col));
}