/*  Noman Mustafa Mehar
    Section : SE-Q 2021
    PF   PROJECT   2021
    ROll No : 21I -1235 */
    
#include <ncurses.h>
#include "../headers/main.h"

// for writing multiple strings ... take the window , the colour pair
// for printing , the axis and the list of the strings 
void write(WINDOW* win,int col, int y, int x, const char* fmt, ...) {

    // move to that position in the required window
    wmove(win, y, x);
    // making a list of arguments
    va_list args;
    // telling where the arguument is starting
    va_start(args, fmt);
    wattron(win, COLOR_PAIR(col));
    // printing the argument , v here is used just like vprintf in c
    vw_printw(win, fmt, args);
    // telling that the argument ended
    va_end(args);
    wrefresh(win);
    wattroff(win, COLOR_PAIR(col));
}