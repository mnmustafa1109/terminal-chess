#include <ncurses.h>
#include "main.h"

void write(WINDOW* win,int col, int y, int x, const char* fmt, ...) {
    wmove(win, y, x);
    va_list args;
    va_start(args, fmt);
    wattron(win, COLOR_PAIR(col));
    vw_printw(win, fmt, args);
    va_end(args);
    wrefresh(win);
    wattroff(win, COLOR_PAIR(col));
}