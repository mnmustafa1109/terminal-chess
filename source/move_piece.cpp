/*  Noman Mustafa Mehar
    PF   PROJECT   2021
    Section : SE-Q 2021
    ROll No : 21I -1235 */
    
#include "../headers/calc.h"
#include "../headers/move_rule.h"
#include "../headers/piece_man.h"

bool move_piece(char from[], char to[]) {
    if (check_legal(from, to) && check_empty(get_name(from), get_col(from)) &&
        check_same_col(get_col(from), get_col(to))) {
        print_piece(y_cord(to), x_cord(to), get_col(from), get_name(from));
        remove_piece(y_cord(from), x_cord(from));
        
        return true;
    }
    return false;
}