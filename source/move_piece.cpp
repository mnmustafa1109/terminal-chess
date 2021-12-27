/*  Noman Mustafa Mehar
    PF   PROJECT   2021
    Section : SE-Q 2021
    ROll No : 21I -1235 */

#include "../headers/calc.h"
#include "../headers/move_rule.h"
#include "../headers/piece_man.h"

bool move_piece(char from[], char to[]) {
    static char lfrm[2], lt[2];
    static char lcol, lname;
    static bool first = true;
    if (check_legal(from, to) && check_same_col(get_col(from), get_col(to))) {
        if (!first) {
            print_piece(y_cord(lt), x_cord(lt), lcol, lname, 'w', 0);
            remove_piece(y_cord(lfrm), x_cord(lfrm), 'w', 0);
        }
        first = false;
        lfrm[0] = from[0];
        lfrm[1] = from[1];
        lt[0] = to[0];
        lt[1] = to[1];
        lcol = get_col(from);
        lname = get_name(from);
        print_piece(y_cord(to), x_cord(to), get_col(from), get_name(from), 'h',
                    1);
        remove_piece(y_cord(from), x_cord(from), 'h', 1);
        return true;
    }
    return false;
}
