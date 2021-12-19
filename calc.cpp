#include "main.h"
#include "init_colours.h"

int x_axis(int x);
int y_axis(int y);
int y_cord(char y[]);
int x_cord(char x[]);
char get_col(char pos[]);
char get_name(char pos[]);

// convert the irl board axis to the window axis
int x_axis(int x) {
    return (--x * 10) + 2;
}

// convert the irl board axis to the window axis
int y_axis(int y) {
    return (--y * 5) + 1;
}

// extract irl board axis from input char axis
int y_cord(char y[]) {
    return 9 - (y[1] - 48);
}

// extract irl board axis from input char axis
int x_cord(char x[]) {
    return x[0] - '0' - 48;
}

// extract colour from the input char axis provided
char get_col(char pos[]){
    return map[y_cord(pos) - 1][x_cord(pos) - 1][0];
}

// extract name from the input char axis provided
char get_name(char pos[]){
    return map[y_cord(pos) - 1][x_cord(pos) - 1][1];
}

// return true if white and false or white
// used for converting turn colour into programmable
// binary turn
bool col_bool(char col) {
    if (col == 'w') {
        return true;
    } 
    return false;
}

//  return the priniting colour use to 
//  print the turn banner depending on the
// colour bool it is provided
int get_turn_col(bool col){
    if (col == true) {
        return BOTW_PAIR;
    }
   return WOB_PAIR;  
}
