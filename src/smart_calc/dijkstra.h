#ifndef SRC_SMART_CALC_DIJKSTRA_H_
#define SRC_SMART_CALC_DIJKSTRA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef struct stack {
    char *token;
    struct stack *prev;

} stack;

typedef struct rpn {
    char *token;
    struct rpn *next;
} rpn;

int isfunc(char *str);
int isdelim(char c);
void dijkstra(char *input, rpn **rpn_head);

#endif //SRC_SMART_CALC_DIJKSTRA_H_