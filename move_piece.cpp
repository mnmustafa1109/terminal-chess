#include "calc.h"
#include "piece_man.h"
#include "move_rule.h"

void move_piece(char from[], char to[]) {
    if (check_empty(get_name(from), get_col(from)) ||
        check_same_col(get_col(from), get_col(to))) {
        return;
    }
    if (check_legal(from, to) == true) {
        print_piece(y_cord(to), x_cord(to), get_col(from), get_name(from));
        remove_piece(y_cord(from), x_cord(from));
    }
}
