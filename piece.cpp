#include <iostream>
using namespace std;

string* queen();
string* king();
string* bishop();
string* knight();
string* rook();
string* pawn();
string* return_piece(char p);

string* queen() {
    static string queen[5] = {"  █ ██ █  ", "   ████   ", " █  ██  █ ",
                              "  ██████  ", " ████████ "};
    return queen;
}

string* king() {
    static string king[5] = {" █  ██  █ ", " █ █  █ █ ", " ██ ██ ██ ",
                             "   █  █   ", " ████████ "};
    return king;
}

string* bishop() {
    static string bishop[5] = {"   █ ██   ", "  ███ ██  ", " █████ ██ ",
                               "   ████   ", " ████████ "};
    return bishop;
}

string* knight() {
    static string knight[5] = {"    ███   ", "   ██ ██  ", "  █████ █ ",
                               "   ███    ", " ████████ "};
    return knight;
}

string* rook() {
    static string rook[5] = {" ████████ ", " █ █  █ █ ", "   ████   ",
                             "  █ ██ █  ", " ████████ "};
    return rook;
}

string* pawn() {
    static string pawn[5] = {"          ", "    ██    ", "  ██████  ",
                             "    ██    ", " ████████ "};
    return pawn;
}

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