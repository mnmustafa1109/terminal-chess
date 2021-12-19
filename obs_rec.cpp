#include <ncurses.h>
#include "calc.h"
#include "cmath"
#include "general.h"
#include "init_colours.h"
#include "main.h"

bool check_straight(char from[], char to[]) {
    int init, end;
    char cord;
    if (y_cord(from) == y_cord(to)) {
        if (x_cord(from) > x_cord(to)) {
            init = x_cord(to);
            end = x_cord(from);
        } else {
            init = x_cord(from);
            end = x_cord(to);
        }
        cord = 'x';
    } else if (x_cord(from) == x_cord(to)) {
        if (y_cord(from) > y_cord(to)) {
            init = y_cord(to);
            end = y_cord(from);
        } else {
            init = y_cord(from);
            end = y_cord(to);
        }
        cord = 'y';
    }
    for (size_t i = init + 1; i < end; i++) {
        if (cord == 'x') {
            if (map[y_cord(from) - 1][i - 1][0] != '-') {
                write_input(WOR_PAIR, 7, 1, "Someting on the way");
                return false;
            }
        } else if (cord == 'y') {
            if (map[i - 1][x_cord(from) - 1][0] != '-') {
                write_input(WOR_PAIR, 7, 1, "SOmething on the way");
                return false;
            }
        }
    }
    return true;
}

bool check_diagnol(char from[], char to[]) {
    int x_init, x_end, y_init, y_end;
    if (abs(y_cord(from) - y_cord(to)) == abs(x_cord(from) - x_cord(to))) {
        if (y_cord(from) > y_cord(to)) {
            y_init = y_cord(to);
            y_end = y_cord(from);
        } else {
            y_init = y_cord(from);
            y_end = y_cord(to);
        }
        if (x_cord(from) > x_cord(to)) {
            x_init = x_cord(to);
            x_end = x_cord(from);
        } else {
            x_init = x_cord(from);
            x_end = x_cord(to);
        }
        size_t x, y;
        for (x = x_init + 1, y = y_init + 1; x < x_end, y < y_end; x++, y++) {
            if (map[y-1][x - 1][0] != '-') {
                write_input(WOR_PAIR, 7, 1, "Someting on the way");
                return false;
            }
        }
    }
    return true;
}

bool check_path(char from[], char to[]) {
    return check_straight(from, to) &&  check_diagnol(from,to);
}
