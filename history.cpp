#include "calc.h"
#include "init_colours.h"
#include "main.h"
#include "piece.h"
#include "write.h"
#define LOGNAME_FORMAT "%Y%m%d_%H%M%S.txt"
#define LOGNAME_SIZE 20

FILE* logfile(tm* start_time) {
    static char name[LOGNAME_SIZE];
    strftime(name, sizeof(name), LOGNAME_FORMAT, start_time);
    return fopen(name, "a");
}

void write_hstr(tm* start_time,
                int turn_ln,
                int turn_no,
                char* to,
                bool current_turn,
                char* from) {
    FILE* file = logfile(start_time);
    fprintf(file, "%d. %s %s → %s \n", turn_no,
            return_char(get_name(to), current_turn).c_str(), from, to);
    fclose(file);
    write(info, WOG_PAIR, turn_ln, 2, "%d. %s %s → %s ", turn_no,
          return_char(get_name(to), current_turn).c_str(), from, to);
}
