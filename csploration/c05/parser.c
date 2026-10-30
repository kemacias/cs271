/****************************************
 * C-ploration 4 for CS 271
 *
 * [NAME] $Kate Macias$
 * [TERM] FALL $2026$
 *
 ****************************************/
#include "parser.h"

/* Function: strip
 * -------------
 * remove whitespace and comments from a line
 *
 * s: the char* string to strip
 *
 * returns: the stripped char* string
 */
char *strip(char *s){

	// your code here

    return s;
}

bool is_label(const char *line) {
    return line[0] == '(' && line[strlen(line) - 1] == ')';
}

bool is_Atype(const char *line) {
    return line[0] == '@';
}

bool is_Ctype(const char *line) {
    return !is_Atype(line) && !is_label(line);
}

/* Function: parse
 * -------------
 * iterate each line in the file and strip whitespace and comments.
 *
 * file: pointer to FILE to parse
 *
 * returns: nothing
 */
void parse(FILE * file){
char line[MAX_LINE_LENGTH] = {0};

while (fgets(line, sizeof(line), file)) {
    strip(line);
    if (!*line) {
        continue;
     }
    char inst_type = ' ';
        if (is_Atype(line)) {
            inst_type = 'A';
        } else if (is_Ctype(line)) {
            inst_type = 'C';
        } else if (is_label(line)) {
            inst_type = 'L';
        }
    printf("%c  %s\n", inst_type, line);
}

}
