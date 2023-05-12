#ifndef SRC_SMART_CALC_DIJKSTRA_H
#define SRC_SMART_CALC_DIJKSTRA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define DELIMITER 1
#define VARIABLE  2
#define NUMBER    3

typedef struct stack {
    char *token;
    struct stack *prev;

} stack;

typedef struct rpn {
    char *token;
    struct rpn *next;
} rpn;

#endif //SRC_SMART_CALC_DIJKSTRA_H