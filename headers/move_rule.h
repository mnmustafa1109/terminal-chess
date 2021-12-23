/*  Noman Mustafa Mehar
    PF   PROJECT   2021
    Section : SE-Q 2021
    ROll No : 21I -1235 */
    
#ifndef MOVE_RULE_H  // To make sure you don't declare the function more than
                       // once by including the header multiple times.
#define MOVE_RULE_H

bool check_empty(char color, char name);
bool check_same_col(char color1, char color2);
bool check_legal(char from[],char to[]);
#endif
