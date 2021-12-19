#include <ncurses.h>
int WOG_PAIR=1;
int WOW_PAIR=2;
int BOG_PAIR=3;
int BOW_PAIR=4;
int DGREYBG_PAIR=5;
int LGREYBG_PAIR=6;
int WOB_PAIR=7;
int WOR_PAIR=8;
int BOTW_PAIR=9;
int WOGN_PAIR=10;
void init_colours() {

    // variable names for my own custom colours
    int DGREY = 1;
    int LGREY = 2;
    int RED = 3;
    int GREEN = 4;

    // initializing my custom colours
    init_extended_color(DGREY, 150, 150, 150);
    init_extended_color(LGREY, 350, 350, 350);
    init_extended_color(RED, 800, 0, 0);
    init_extended_color(GREEN, 0, 800, 0);

    // making pair of colours for different purposes for priniting
    init_pair(WOG_PAIR, COLOR_WHITE, DGREY);
    init_pair(WOW_PAIR, COLOR_WHITE, LGREY);
    init_pair(BOG_PAIR, COLOR_BLACK, DGREY);
    init_pair(BOW_PAIR, COLOR_BLACK, LGREY);
    init_pair(BOTW_PAIR, COLOR_BLACK, COLOR_WHITE);
    init_pair(WOB_PAIR, COLOR_WHITE, COLOR_BLACK);
    init_pair(WOR_PAIR, COLOR_WHITE, RED);
    init_pair(WOGN_PAIR, COLOR_WHITE, GREEN);
    init_pair(LGREYBG_PAIR, LGREY, LGREY);
    init_pair(DGREYBG_PAIR, DGREY, DGREY);
    
}