/*  Noman Mustafa Mehar
    Section : SE-Q 2021
    PF   PROJECT   2021
    ROll No : 21I -1235 */
    
#include <cmath>
#include "../headers/main.h"
int get_score(char col) {
    int score = 0;
    for (size_t i = 0; i < 8; i++) {
        for (size_t j = 0; j < 8; j++) {
            if (map[i][j][0] == col) {
                if (map[i][j][1] == 'q') {
                    score += 9;
                } else if (map[i][j][1] == 'p') {
                    score += 1;
                } else if (map[i][j][1] == 'n' || map[i][j][1] == 'b' ||
                           map[i][j][1] == 'r') {
                    score += 3;
                }
            }
        }
    }

    return score;
}

int score(char col) {
    if (col == 'w') {
        if (get_score('w') - get_score('b') > 0) {
            return get_score('w') - get_score('b');
        } else {
            return 0;
        }
    } else if (col == 'b') {
        if (get_score('b') - get_score('w') > 0) {
            return get_score('b') - get_score('w');
        } else {
            return 0;
        }
    }
    return 0;
}
