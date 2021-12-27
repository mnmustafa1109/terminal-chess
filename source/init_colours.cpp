/*  Noman Mustafa Mehar
    PF   PROJECT   2021
    Section : SE-Q 2021
    ROll No : 21I -1235 */
    
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
int TWBG_PAIR=11;
int WOLY_PAIR=12;
int WODY_PAIR=13;
int BODY_PAIR=14;
int BOLY_PAIR=15;
int DYBG_PAIR=16;
int LYBG_PAIR=17;
void init_colours() {

    // variable names for my own custom colours
    int DGREY = 1;
    int LGREY = 2;
    int RED = 3;
    int GREEN = 4;
    int DYELLOW = 5;
    int LYELLOW = 6;
    
    // initializing my custom colours
    init_extended_color(DGREY, 150, 150, 150);
    init_extended_color(LGREY, 350, 350, 350);
    init_extended_color(RED, 800, 0, 0);
    init_extended_color(GREEN, 0, 800, 0);
    init_extended_color(LYELLOW, 255,255,102);
    init_extended_color(DYELLOW, 239,204,0);
    

    // making pair of colours for different purposes for priniting
    init_pair(WOG_PAIR, COLOR_WHITE, DGREY);
    init_pair(WOW_PAIR, COLOR_WHITE, LGREY);
    init_pair(BOG_PAIR, COLOR_BLACK, DGREY);
    init_pair(BOW_PAIR, COLOR_BLACK, LGREY);
    init_pair(WOLY_PAIR, COLOR_WHITE, LYELLOW);
    init_pair(WODY_PAIR, COLOR_WHITE, DYELLOW);
    init_pair(BODY_PAIR, COLOR_BLACK, DYELLOW);
    init_pair(BOLY_PAIR, COLOR_BLACK, LYELLOW);
    init_pair(BOTW_PAIR, COLOR_BLACK, COLOR_WHITE);
    init_pair(WOB_PAIR, COLOR_WHITE, COLOR_BLACK);
    init_pair(WOR_PAIR, COLOR_WHITE, RED);
    init_pair(WOGN_PAIR, COLOR_WHITE, GREEN);
    init_pair(LGREYBG_PAIR, LGREY, LGREY);
    init_pair(TWBG_PAIR, COLOR_WHITE, COLOR_WHITE);
    init_pair(DGREYBG_PAIR, DGREY, DGREY);
    init_pair(DYBG_PAIR, DYELLOW, DYELLOW);
    init_pair(LYBG_PAIR, LYELLOW, LYELLOW);
    
}