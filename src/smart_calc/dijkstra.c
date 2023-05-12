#include "dijkstra.h"

int isdelim(char c)
{
    if(strchr(" +-/*%^=()", c) || c==9 || c=='\r' || c==0)
        return 1;
    return 0;
}

char *get_token(char *token, char *prog, int *i)
{
    register char *temp;
    char tok_type = 0;
    temp = token;
    *temp = '\0';

    if(!*prog) return NULL; 
    while(isspace(*prog)) 
    {
        ++prog;
        ++(*i);
    }  
    if(strchr("+-*/%^=()", *prog)){
        tok_type = DELIMITER;
        printf("delimiter: ");
        *temp++ = *prog++;
        ++(*i);
    }
    else if(isalpha(*prog)) {
        while(!isdelim(*prog)) {
            *temp++ = *prog++;
            ++(*i);
        }
        printf("var: ");
        tok_type = VARIABLE;
    }
    else if(isdigit(*prog)) {
        while(!isdelim(*prog)) 
        {
            *temp++ = *prog++;
            ++(*i);
        }
        printf("num : ");
        tok_type = NUMBER;
    }
    *temp = '\0';
    printf("%s\n", token);
    return token;
}

void put_in_rpn(rpn *rpn_output, stack *stack_for_delims, char *token)
{
    if (strlen(token) == 1 && isdelim(token[0]))
    {
        //пока приоритет О2 выше О1, перекладываем из стека в опн
        //close brace
        if (token[0] == ')')
        {
            // while (stack_for_delims->token && stack_for_delims->token[0] != '(')
            // {
                // printf("%s\n", stack_for_delims->token);
                // strcpy(token, stack_for_delims->token);
                // token[strlen(stack_for_delims->token)] = '\0';
                
                // rpn_output->token = malloc(sizeof(token + 1));
                // strcpy(rpn_output->token, token);
                // rpn_output->token[strlen(token)] = '\0';
                // rpn *temp = malloc(sizeof(rpn)); 
                // temp->next = rpn_output;
                // rpn_output = temp; 
                // rpn_output->next = NULL;

                // stack *tmp = stack_for_delims;
                // printf("%s\n", stack_for_delims->prev->token);
                // stack_for_delims = stack_for_delims->prev;
                // free(tmp);
            // }
        }
        // stack_for_delims->token = malloc(sizeof(token + 1));
        // stack_for_delims->token[0] = token[0];
        // stack_for_delims->token[1] = '\0';
        // stack *temp = malloc(sizeof(stack));
        // temp->prev = stack_for_delims;
        // stack_for_delims = temp; 
    }
    else 
    {
        if (rpn_output == NULL)
        {
            rpn_output = malloc(sizeof(rpn));
            rpn_output->token = malloc(sizeof(token + 1));
            strcpy(rpn_output->token, token);
            rpn_output->next = NULL;
        }
        else
        {
            rpn *new = malloc(sizeof(rpn));
            new->token = malloc(sizeof(token + 1));
            new->next = NULL;
            strcpy(new->token, token);
            new->token[strlen(token)] = '\0';
            printf("mm %s\n", new->token);
            rpn_output->next = new;
            rpn_output = new; 
        }
    }
}

int dijkstra(char *input)
{
    int i = 0;
    char token[50];
    rpn *rpn_output = NULL;
    rpn *rpn_copy = rpn_output;
    stack *stack_for_delims = NULL;
    while (input[i])
    {
        get_token(token, input + i, &i);
        put_in_rpn(rpn_copy, stack_for_delims, token);
        printf("hmm %s\n", rpn_copy->token); //sega
    }
    printf("stack: \n");
    while (rpn_output)
    {
        printf("%s\n", rpn_output->token);
        rpn_output = rpn_output->next;
    }
}
int main()
{
    dijkstra("2/(32+3)*5");
}