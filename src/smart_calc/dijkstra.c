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

void put_in_rpn(rpn **rpn_output, rpn **rpn_head, stack **stack_for_delims, char *token)
{
    if (isdelim(token[0]))
    {
        if ((*stack_for_delims) == NULL)
        {
            (*stack_for_delims) = malloc(sizeof(rpn));
            (*stack_for_delims)->token = malloc(sizeof(token + 1));
            strcpy((*stack_for_delims)->token, token);
            (*stack_for_delims)->prev = NULL;
        }
        else 
        {
            //пока приоритет О2 выше О1, перекладываем из стека в опн
            //close brace
            if (strcmp(token, ")") == 0)
            {
                while ((*stack_for_delims)->token && strcmp((*stack_for_delims)->token, "(") != 0)
                {
                    
                }
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
            }
            stack *new = malloc(sizeof(stack));
            new->token = malloc(sizeof(token + 1));
            strcpy(new->token, token);
            new->token[strlen(new->token)] = '\0';
            new->prev = (*stack_for_delims);
            (*stack_for_delims) = new;
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
            new->token[strlen(token)] = '\0';
            printf("mm %s\n", new->token);
            (*rpn_output)->next = new;
            (*rpn_output) = new; 
        }
    }
}

void dijkstra(char *input)
{
    int i = 0;
    char token[50];
    rpn *rpn_output = NULL;
    rpn *rpn_head;
    stack *stack_for_delims = NULL;
    stack *stack_head;
    while (input[i])
    {
        get_token(token, input + i, &i);
        put_in_rpn(&rpn_output, &rpn_head, &stack_for_delims, token);
    }
    printf("rpn: \n");
    while (rpn_head)
    {
        printf("%s ", rpn_head->token);
        rpn_head = rpn_head->next;
    }
    printf("\nstack: \n");
    while (stack_for_delims)
    {
        printf("%s ", stack_for_delims->token);
        stack_for_delims = stack_for_delims->prev;
    }
}
int main()
{
  dijkstra("2 / ( 32 + 3 ) * 5");
}
