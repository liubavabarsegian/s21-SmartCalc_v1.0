#include "dijkstra.h"

int isfunc(char *str)
{
    if (strcmp(str, "sin") == 0 || strcmp(str, "cos") == 0 || strcmp(str, "tan") == 0 || strcmp(str, "asin") == 0 || strcmp(str, "acos") == 0 || strcmp(str, "atan") == 0 || strcmp(str, "sqrt") == 0)
        return 1;
    return 0;
}

int isdelim(char c)
{
    if(strchr(" +-/*%^=()", c) || c==9 || c=='\r' || c==0)
        return 1;
    return 0;
}

int get_operator_priority(char *op) {
    if (strcmp(op, "~") == 0)
        return 4;
    else if (strcmp(op, "(") == 0)
        return 3;
    else if (strcmp(op, "^") == 0)
        return 2;
    else if (isfunc(op))
        return 2;
    else if (strcmp(op, "*") == 0 || strcmp(op, "/") == 0 || strcmp(op, "%") == 0)
        return 1;
    else if (strcmp(op, "+") == 0 )
        return 0;
    else
        return -1; // error: unknown operator
}

char *get_token(char *token, char *prog, int *i)
{
    register char *temp;
    temp = token;
    *temp = '\0';

    if(!*prog) return NULL; 
    while(isspace(*prog)) 
    {
        ++prog;
        ++(*i);
    }  
    if(strchr("+-~*/%^=()", *prog)){
        *temp++ = *prog++;
        ++(*i);
    }
    else if(isalpha(*prog)) {
        while(!isdelim(*prog)) {
            *temp++ = *prog++;
            ++(*i);
        }
    }
    else if(isdigit(*prog)) {
        while(!isdelim(*prog)) 
        {
            *temp++ = *prog++;
            ++(*i);
        }
    }
    *temp = '\0';
    return token;
}

void put_in_rpn(rpn **rpn_output, rpn **rpn_head, stack **stack_for_delims, char *token)
{
    if (isdelim(token[0]) || isfunc(token))
    {
        if ((*stack_for_delims) == NULL)
        {
            (*stack_for_delims) = malloc(sizeof(stack));
            (*stack_for_delims)->token = malloc(sizeof(token + 1));
            strcpy((*stack_for_delims)->token, token);
            (*stack_for_delims)->prev = NULL;
        }
        else 
        {
            //close brace
            if (strcmp(token, ")") == 0)
            {
                while ((*stack_for_delims)->token && strcmp((*stack_for_delims)->token, "(") != 0)
                {
                    rpn *new = malloc(sizeof(rpn));
                    new->token = malloc(sizeof(token + 1));
                    new->next = NULL;
                    strcpy(new->token, (*stack_for_delims)->token);
                    new->token[strlen(new->token)] = '\0';
                    (*rpn_output)->next = new;
                    (*rpn_output) = new; 
                    stack *temp = (*stack_for_delims);
                    (*stack_for_delims) = (*stack_for_delims)->prev;
                    free(temp);
                }
                stack *temp = (*stack_for_delims);
                (*stack_for_delims) = (*stack_for_delims)->prev;
                free(temp);
                // if ((*stack_for_delims) && isfunc((*stack_for_delims)->token))
                // {
                //     rpn *new = malloc(sizeof(rpn));
                //     new->token = malloc(sizeof(token + 1));
                //     new->next = NULL;
                //     strcpy(new->token, (*stack_for_delims)->token);
                //     new->token[strlen(new->token)] = '\0';
                //     (*rpn_output)->next = new;
                //     (*rpn_output) = new; 
                //     stack *temp = (*stack_for_delims);
                //     (*stack_for_delims) = (*stack_for_delims)->prev;
                //     free(temp);
                // }
            }
            else {
                //пока приоритет О2 выше О1, перекладываем из стека в опн
                while ((*stack_for_delims) && (strcmp((*stack_for_delims)->token, "(") != 0) && get_operator_priority((*stack_for_delims)->token) >= get_operator_priority(token))
                {
                    rpn *new = malloc(sizeof(rpn));
                    new->token = malloc(sizeof(token + 1));
                    new->next = NULL;
                    strcpy(new->token, (*stack_for_delims)->token);
                    new->token[strlen(new->token)] = '\0';
                    (*rpn_output)->next = new;
                    (*rpn_output) = new; 
                    stack *temp = (*stack_for_delims);
                    (*stack_for_delims) = (*stack_for_delims)->prev;
                    free(temp);
                }
                stack *new = malloc(sizeof(stack));
                new->token = malloc(sizeof(token + 1));
                strcpy(new->token, token);
                new->token[strlen(new->token)] = '\0';
                new->prev = (*stack_for_delims);
                (*stack_for_delims) = new; 
            }
        }
    }
    else 
    {
        if ((*rpn_output) == NULL)
        {
            (*rpn_output) = malloc(sizeof(rpn));
            (*rpn_output)->token = malloc(sizeof(token + 1));
            strcpy((*rpn_output)->token, token);
            (*rpn_output)->next = NULL;
            (*rpn_head) = (*rpn_output);
        }
        else
        {
            rpn *new = malloc(sizeof(rpn));
            new->token = malloc(sizeof(token + 1));
            new->next = NULL;
            strcpy(new->token, token);
            new->token[strlen(new->token)] = '\0';
            (*rpn_output)->next = new;
            (*rpn_output) = new; 
        }
    }
}

void dijkstra(char *input, rpn **rpn_head)
{
    int i = 0;
    char token[50];
    rpn *rpn_output = NULL;
    stack *stack_for_delims = NULL;
    while (input[i])
    {
        get_token(token, input + i, &i);
        put_in_rpn(&rpn_output, rpn_head, &stack_for_delims, token);
        // printf("STACK:\n");
        // rpn *copy = rpn_head;
        // while (copy)
        // {
        //     printf("%s ", copy->token);
        //     copy = copy->next;
        // }
        // printf("\nRNP\n");
        // stack *scopy = stack_for_delims;
        // while (scopy)
        // {
        //     printf("%s ", scopy->token);
        //     scopy = scopy->prev;
        // }
        // printf("\n\n");
    }
    while (stack_for_delims)
    {
        rpn *new = malloc(sizeof(rpn));
        new->token = malloc(sizeof(token + 1));
        new->next = NULL;
        strcpy(new->token, stack_for_delims->token);
        new->token[strlen(new->token)] = '\0';
        rpn_output->next = new;
        rpn_output = new; 
        stack *temp = stack_for_delims;
        stack_for_delims = stack_for_delims->prev;
        free(temp);
    }
}
// int main()
// {
//   dijkstra("2 / ( ~32 + 3 ) * acos(sin(cos(5) + 4^2))");
// }
