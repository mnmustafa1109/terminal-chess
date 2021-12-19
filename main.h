#ifndef MAIN_H
#define MAIN_H
#include <ncurses.h>

// making them avaialble externally to the file
extern  WINDOW* board;
extern  WINDOW* input;
extern  WINDOW* info;
extern char map[8][8][2];
#endif