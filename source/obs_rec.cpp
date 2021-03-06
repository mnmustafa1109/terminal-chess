/*  Noman Mustafa Mehar
    PF   PROJECT   2021
    Section : SE-Q 2021
    ROll No : 21I -1235 */
    
#include <ncurses.h>
#include <cmath>
#include "../headers/calc.h"
#include "../headers/init_colours.h"
#include "../headers/main.h"
#include "../headers/write.h"

// check wether there is something in the path
// if the piece is moving straight or not
bool check_straight(char from[], char to[]) {
    int init, end;
    char cord;
    // check weter it is moving straight in the y axis
    if (y_cord(from) == y_cord(to)) {
        // check wether it is moving left or right
        if (x_cord(from) > x_cord(to)) {
            init = x_cord(to);
            end = x_cord(from);
        } else {
            init = x_cord(from);
            end = x_cord(to);
        }
        cord = 'x';
        // check weter it is moving straight in the x axis
    } else if (x_cord(from) == x_cord(to)) {
        // check wether it is moving upward or downward
        if (y_cord(from) > y_cord(to)) {
            init = y_cord(to);
            end = y_cord(from);
        } else {
            init = y_cord(from);
            end = y_cord(to);
        }
        cord = 'y';
    }
    // checking every block on the way from intiial
    // postion to the end piostion for blank pieces or not
    for (size_t i = init + 1; i < end; i++) {
        // check through y axis if its moving through y axis
        if (cord == 'x') {
            if (map[y_cord(from) - 1][i - 1][0] != '-') {
                write(input, WOR_PAIR, 7, 1, "Someting on the way");
                return false;
            }
            // ceck thorugh x axis if its moveing through xx axis
        } else if (cord == 'y') {
            if (map[i - 1][x_cord(from) - 1][0] != '-') {
                write(input, WOR_PAIR, 7, 1, "SOmething on the way");
                return false;
            }
        }
    }
    return true;
}

// check wehter there is something along the path
//  depending if there is any piece in the path or not
bool check_diagnol(char from[], char to[]) {
    int x_init, x_end, y_init, y_end;
    size_t x, y;

    // check if its moving diagnoally or not
    if (abs(y_cord(from) - y_cord(to)) == abs(x_cord(from) - x_cord(to))) {
        // check if its moving upward or downward
        if (y_cord(from) > y_cord(to) && x_cord(from) > x_cord(to)) {
            for (x = x_cord(to) + 1, y = y_cord(to) + 1;
                 x < x_cord(from), y < y_cord(from); x++, y++) {
                if (map[y - 1][x - 1][0] != '-') {
                    write(input, WOR_PAIR, 7, 1, "Someting on the way");
                    return false;
                }
            }
        } else if (y_cord(from) < y_cord(to) && x_cord(from) < x_cord(to)) {
            for (x = x_cord(from) + 1, y = y_cord(from) + 1;
                 x < x_cord(to), y < y_cord(to); x++, y++) {
                if (map[y - 1][x - 1][0] != '-') {
                    write(input, WOR_PAIR, 7, 1, "Someting on the way");
                    return false;
                }
            }
        } else if (y_cord(from) < y_cord(to) && x_cord(from) > x_cord(to)) {
            for (x = x_cord(from) + 1, y = y_cord(from) + 1;
                 x < x_cord(to), y < y_cord(to); x--, y++) {
                if (map[y - 1][x - 1][0] != '-') {
                    write(input, WOR_PAIR, 7, 1, "Someting on the way");
                    return false;
                }
            }
        } else if (y_cord(from) > y_cord(to) && x_cord(from) < x_cord(to)) {
            for (x = x_cord(from) + 1, y = y_cord(from) + 1;
                 x < x_cord(to), y < y_cord(to); x++, y--) {
                if (map[y - 1][x - 1][0] != '-') {
                    write(input, WOR_PAIR, 7, 1, "Someting on the way");
                    return false;
                }
            }
        }

        // looping trhought the path and check every block for some piece
        // making x and y as their inital position and looping until the end
        // position
    }
    return true;
}

bool check_path(char from[], char to[]) {
    return check_straight(from, to) && check_diagnol(from, to);
}
