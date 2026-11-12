#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>

#define MAX_LINE_LENGTH 200
#define MAX_LABEL_LENGTH (MAX_LINE_LENGTH - 2)

typedef int16_t hack_addr;
typedef int16_t opcode;

typedef enum instr_type {
    INVALID_INSTRUCTION = -1,
    A_TYPE_INSTRUCTION,
    C_TYPE_INSTRUCTION,
} instr_type;

typedef struct c_instruction {
    opcode a:1;
    opcode comp:6;
    opcode dest:3;
    opcode jump:3;
} c_instruction;

typedef struct a_instruction {
    union {
        hack_addr address;
        char *label;
    } operand;
    bool is_addr;
} a_instruction;

typedef struct instruction {
    union {
        a_instruction a_instr;
        c_instruction c_instr;
    } instr;
    instr_type itype;
} instruction;

char *strip(char *s);
bool is_label(const char *line);
bool is_Atype(const char *line);
bool is_Ctype(const char *line);
char *extract_label(const char *line, char *label);
void parse(FILE * file);
