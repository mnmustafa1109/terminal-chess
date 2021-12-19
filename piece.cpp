/*  Noman Mustafa Mehar
    PF   PROJECT   2021
    Section : SE-Q 2021
    ROll No : 21I -1235 */
    
#include <iostream>
using namespace std;

string* queen();
string* king();
string* bishop();
string* knight();
string* rook();
string* pawn();
string* return_piece(char p);
string return_char(char p, bool col);

// return queen string array to print
string* queen() {
    static string queen[5] = {"  █ ██ █  ", "   ████   ", " █  ██  █ ",
                              "  ██████  ", " ████████ "};
    return queen;
}

// return king string array to print
string* king() {
    static string king[5] = {" █  ██  █ ", " █ █  █ █ ", " ██ ██ ██ ",
                             "   █  █   ", " ████████ "};
    return king;
}

// return bishop string array to print
string* bishop() {
    static string bishop[5] = {"   █ ██   ", "  ███ ██  ", " █████ ██ ",
                               "   ████   ", " ████████ "};
    return bishop;
}

// return knight string array to print
string* knight() {
    static string knight[5] = {"    ███   ", "   ██ ██  ", "  █████ █ ",
                               "   ███    ", " ████████ "};
    return knight;
}

// return rook string array to print
string* rook() {
    static string rook[5] = {" ████████ ", " █ █  █ █ ", "   ████   ",
                             "  █ ██ █  ", " ████████ "};
    return rook;
}

// return pawn string array to print
string* pawn() {
    static string pawn[5] = {"          ", "    ██    ", "  ██████  ",
                             "    ██    ", " ████████ "};
    return pawn;
}

// return the piece string array depending on the char it given
string* return_piece(char p) {
    switch (p) {
        case 'q':
            return queen();
            break;
        case 'k':
            return king();
            break;
        case 'b':
            return bishop();
            break;
        case 'n':
            return knight();
            break;
        case 'r':
            return rook();
            break;
        case 'p':
            return pawn();
            break;
        default:
            break;
    }
    return queen();
}

// return the utf-8 char of the chess piece
// depending on the piece name and the color
// given wether it is black or white 
string return_char(char p, bool col) {
    switch (p) {
        case 'q':
            if (col == true) {
                return "♛";
            } else {
                return "♕";
            }
            break;
        case 'k':
            if (col == true) {
                return "♚";
            } else {
                return "♔";
            }
            break;
        case 'b':
            if (col == true) {
                return "♝";
            } else {
                return "♗";
            }
            break;
        case 'n':
            if (col == true) {
                return "♞";
            } else {
                return "♘";
            }
            break;
        case 'r':
            if (col == true) {
                return "♜";
            } else {
                return "♖";
            }
            break;
        case 'p':
            if (col == true) {
                return "♝";
            } else {
                return "♗";
            }
            break;
        // return - if no valid piece char is provided    
        default:
            return "-";
            break;
    }
    return "-";
}