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
    char s_new[strlen(s) + 1];
    int i = 0;

    for (char *s2 = s; *s2; s2++) {
        if (*s2 == '/' && *(s2 + 1) == '/') {
            break;
         }
        else if (!isspace(*s2)) {
            s_new[i++] = *s2;
        }
    }

    s_new[i] = '\0';
    strcpy(s, s_new);

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
    char *clean = strip(line);
    if (!*clean) {
        continue;
    }
    char inst_type = ' ';
    if (is_Atype(clean)) {
        inst_type = 'A';
    } else if (is_Ctype(clean)) {
        inst_type = 'C';
    } else if (is_label(clean)) {
        inst_type = 'L';
    }
    printf("%c  %s\n", inst_type, clean);
}

}
