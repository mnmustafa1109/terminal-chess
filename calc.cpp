#include "main.h"
#include "init_colours.h"

int x_axis(int x);
int y_axis(int y);
int y_cord(char y[]);
int x_cord(char x[]);
char get_col(char pos[]);
char get_name(char pos[]);

int x_axis(int x) {
    return (--x * 10) + 2;
}

int y_axis(int y) {
    return (--y * 5) + 1;
}

int y_cord(char y[]) {
    return 9 - (y[1] - 48);
}

int x_cord(char x[]) {
    return x[0] - '0' - 48;
}

char get_col(char pos[]){
    return map[y_cord(pos) - 1][x_cord(pos) - 1][0];
}

char get_name(char pos[]){
    return map[y_cord(pos) - 1][x_cord(pos) - 1][1];
}

bool col_bool(char col) {
    if (col == 'w') {
        return true;
    } 
    return false;
}

int get_turn_col(bool col){
    if (col == true) {
        return BOTW_PAIR;
    }
   return WOB_PAIR;  
}
