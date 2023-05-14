#include "scan_rpn.h"

void sum(stack **result)
{
    char sum[10];
    sprintf(sum, "%f", atof((*result)->token) + atof((*result)->prev->token));
    stack *temp = *result;
    *result = (*result)->prev;
    free(temp);
    free((*result)->token);
    (*result)->token = malloc(sizeof(sum + 1));
    strcpy((*result)->token, sum);
}

void division(stack **result)
{
    char res[10];
    sprintf(res, "%f", atof((*result)->prev->token) / atof((*result)->token));
    stack *temp = *result;
    *result = (*result)->prev;
    free(temp);
    free((*result)->token);
    (*result)->token = malloc(sizeof(res + 1));
    strcpy((*result)->token, res);
}

void multiplication(stack **result)
{
    char res[10];
    sprintf(res, "%f", atof((*result)->prev->token) * atof((*result)->token));
    stack *temp = *result;
    *result = (*result)->prev;
    free(temp);
    free((*result)->token);
    (*result)->token = malloc(sizeof(res + 1));
    strcpy((*result)->token, res);
}

void difference(stack **result)
{
    char res[10];
    sprintf(res, "%f", atof((*result)->prev->token) - atof((*result)->token));
    stack *temp = *result;
    *result = (*result)->prev;
    free(temp);
    free((*result)->token);
    (*result)->token = malloc(sizeof(res + 1));
    strcpy((*result)->token, res);
}

void mod(stack **result)
{
    char res[10];
    sprintf(res, "%d", atoi((*result)->prev->token) % atoi((*result)->token));
    stack *temp = *result;
    *result = (*result)->prev;
    free(temp);
    free((*result)->token);
    (*result)->token = malloc(sizeof(res + 1));
    strcpy((*result)->token, res);
}

void power(stack **result)
{
    char res[10];
    sprintf(res, "%f", pow(atoi((*result)->prev->token),atoi((*result)->token)));
    stack *temp = *result;
    *result = (*result)->prev;
    free(temp);
    free((*result)->token);
    (*result)->token = malloc(sizeof(res + 1));
    strcpy((*result)->token, res);
}

void calculate(rpn **rpn_ready, stack **result)
{
    while (*rpn_ready)
    {
        if (*result == NULL && !isdelim((*rpn_ready)->token[0]))
        {
            *result = malloc(sizeof(stack));
            (*result)->token = malloc(sizeof((*rpn_ready)->token + 1));
            (*result)->prev = NULL;
            strcpy((*result)->token, (*rpn_ready)->token);
        }
        else if (!isdelim((*rpn_ready)->token[0]))
        {
            stack *new = malloc(sizeof(stack));
            new->token = malloc(sizeof((*rpn_ready)->token + 1));
            strcpy(new->token, (*rpn_ready)->token);
            new->token[strlen(new->token)] = '\0';
            new->prev = *result;
            *result = new;
        }
        else if (isdelim((*rpn_ready)->token[0]))
        {
            if (strcmp((*rpn_ready)->token, "+") == 0)
            {
                sum(result);
                printf("HERE %s\n", (*result)->token);
            }
            else if (strcmp((*rpn_ready)->token, "/") == 0)
            {
                division(result);
                printf("HERE %s\n", (*result)->token);
            }
            else if (strcmp((*rpn_ready)->token, "*") == 0)
            {
                multiplication(result);
                printf("HERE %s\n", (*result)->token);
            }
            else if (strcmp((*rpn_ready)->token, "-") == 0)
            {
                multiplication(result);
                printf("HERE %s\n", (*result)->token);
            }
            else if (strcmp((*rpn_ready)->token, "%") == 0)
            {
                multiplication(result);
                printf("HERE %s\n", (*result)->token);
            }
            else if (strcmp((*rpn_ready)->token, "^") == 0)
            {
                power(result);
                printf("HERE %s\n", (*result)->token);
            }
        }
        (*rpn_ready) = (*rpn_ready)->next;
    }
}

int main()
{
    rpn* rpn_ready = NULL;
    dijkstra("2 / (2^3 + 12 ) *5", &rpn_ready);
    stack* res_stack = NULL;
    rpn *copy = rpn_ready;
     while (copy)
    {
        printf("%s ", copy->token);
        copy = copy->next;
    }
    printf("\n");
    calculate(&rpn_ready, &res_stack);
    // while (rpn_ready)
    // {
    //     printf("%s ", rpn_ready->token);
    //     rpn_ready = rpn_ready->next;
    // }

}