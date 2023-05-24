#include "scan_rpn.h"

void sum(stack **result)
{
    char sum[255];
    sprintf(sum, "%f", atof((*result)->token) + atof((*result)->prev->token));
    stack *temp = *result;
    *result = (*result)->prev;
    free(temp);
    free((*result)->token);
    (*result)->token = malloc(sizeof(sum) + 1);
    strcpy((*result)->token, sum);
}

void division(stack **result)
{
    char res[255];
    sprintf(res, "%f", atof((*result)->prev->token) / atof((*result)->token));
    stack *temp = *result;
    *result = (*result)->prev;
    free(temp);
    free((*result)->token);
    (*result)->token = malloc(sizeof(res) + 1);
    strcpy((*result)->token, res);
}

void multiplication(stack **result)
{
    char res[255];
    sprintf(res, "%f", atof((*result)->prev->token) * atof((*result)->token));
    stack *temp = *result;
    *result = (*result)->prev;
    free(temp);
    free((*result)->token);
    (*result)->token = malloc(sizeof(res) + 1);
    strcpy((*result)->token, res);
}

void difference(stack **result)
{
    char res[255];
    sprintf(res, "%f", atof((*result)->prev->token) - atof((*result)->token));
    stack *temp = *result;
    *result = (*result)->prev;
    free(temp);
    free((*result)->token);
    (*result)->token = malloc(sizeof(res) + 1);
    strcpy((*result)->token, res);
}

void mod(stack **result)
{
    char res[255];
    sprintf(res, "%d", atoi((*result)->prev->token) % atoi((*result)->token));
    stack *temp = *result;
    *result = (*result)->prev;
    free(temp);
    free((*result)->token);
    (*result)->token = malloc(sizeof(res) + 1);
    strcpy((*result)->token, res);
}

void power(stack **result)
{
    char res[255];
    sprintf(res, "%f", pow(atof((*result)->prev->token),atof((*result)->token)));
    stack *temp = *result;
    *result = (*result)->prev;
    free(temp);
    free((*result)->token);
    (*result)->token = malloc(sizeof(strlen(res) + 1));
    strcpy((*result)->token, res);
}

void sinus(stack **result)
{
    char res[255];
    sprintf(res, "%f", sin(atof((*result)->token)));
    free((*result)->token);
    (*result)->token = malloc(sizeof(strlen(res) + 1));
    strcpy((*result)->token, res);
}

void cosinus(stack **result)
{
    char res[255];
    sprintf(res, "%f", cos(atof((*result)->token)));
    free((*result)->token);
    (*result)->token = malloc(sizeof(strlen(res) + 1));
    strcpy((*result)->token, res);
}

void tangent(stack **result)
{
    char res[255];
    sprintf(res, "%f", tan(atof((*result)->token)));
    free((*result)->token);
    (*result)->token = malloc(sizeof(strlen(res) + 1));
    strcpy((*result)->token, res);
}

void atangent(stack **result)
{
    char res[255];
    sprintf(res, "%f", atan(atof((*result)->token)));
    free((*result)->token);
    (*result)->token = malloc(sizeof(strlen(res) + 1));
    strcpy((*result)->token, res);
}

void asinus(stack **result)
{
    char res[255];
    sprintf(res, "%f", asin(atof((*result)->token)));
    free((*result)->token);
    (*result)->token = malloc(sizeof(strlen(res) + 1));
    strcpy((*result)->token, res);
}

void acosinus(stack **result)
{
    char res[255];
    sprintf(res, "%f", acos(atof((*result)->token)));
    free((*result)->token);
    (*result)->token = malloc(sizeof(strlen(res) + 1));
    strcpy((*result)->token, res);
}

void square(stack **result)
{
    char res[255];
    sprintf(res, "%f", sqrt(atof((*result)->token)));
    free((*result)->token);
    (*result)->token = malloc(sizeof(strlen(res) + 1));
    strcpy((*result)->token, res);
}

void ln_func(stack **result)
{
    char res[255];
    sprintf(res, "%f", log(atof((*result)->token)));
    free((*result)->token);
    (*result)->token = malloc(sizeof(strlen(res) + 1));
    strcpy((*result)->token, res);
}

void log_func(stack **result)
{
    char res[255];
    sprintf(res, "%f", log10(atof((*result)->token)));
    free((*result)->token);
    (*result)->token = malloc(sizeof(strlen(res) + 1));
    strcpy((*result)->token, res);
}

void calculate(rpn **rpn_ready, stack **result)
{
    while (*rpn_ready)
    {
        printf("%s\n", (*rpn_ready)->token);
        if (*result == NULL && !isdelim((*rpn_ready)->token[0]) && !isfunc((*rpn_ready)->token))
        {
            printf("NULL\n");
            *result = malloc(sizeof(stack));
            (*result)->token = malloc(sizeof((*rpn_ready)->token + 1));
            (*result)->prev = NULL;
            strcpy((*result)->token, (*rpn_ready)->token);
        }
        else if (isdelim((*rpn_ready)->token[0]) || isfunc((*rpn_ready)->token))
        {
            printf("%d\n", strcmp((*rpn_ready)->token, "+") == 0);
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
                difference(result);
                printf("HERE %s\n", (*result)->token);
            }
            else if (strcmp((*rpn_ready)->token, "%") == 0)
            {
                mod(result);
                printf("HERE %s\n", (*result)->token);
            }
            else if (strcmp((*rpn_ready)->token, "^") == 0)
            {
                power(result);
                printf("HERE %s\n", (*result)->token);
            }
            else if (strcmp((*rpn_ready)->token, "sin") == 0)
            {
                sinus(result);
                printf("HERE %s\n", (*result)->token);
            }
            else if (strcmp((*rpn_ready)->token, "cos") == 0)
            {
                cosinus(result);
                printf("HERE %s\n", (*result)->token);
            }
            else if (strcmp((*rpn_ready)->token, "tan") == 0)
            {
                tangent(result);
                printf("HERE %s\n", (*result)->token);
            }
            else if (strcmp((*rpn_ready)->token, "atan") == 0)
            {
                atangent(result);
                printf("HERE %s\n", (*result)->token);
            }
            else if (strcmp((*rpn_ready)->token, "acos") == 0)
            {
                cosinus(result);
                printf("HERE %s\n", (*result)->token);
            }
            else if (strcmp((*rpn_ready)->token, "asin") == 0)
            {
                asinus(result);
                printf("HERE %s\n", (*result)->token);
            }
            else if (strcmp((*rpn_ready)->token, "sqrt") == 0)
            {
                square(result);
                printf("HERE %s\n", (*result)->token);
            }
            else if (strcmp((*rpn_ready)->token, "ln") == 0)
            {
                ln_func(result);
                printf("HERE %s\n", (*result)->token);
            }
            else if (strcmp((*rpn_ready)->token, "log") == 0)
            {
                log_func(result);
                printf("HERE %s\n", (*result)->token);
            }
        }
        else
        {
            printf("ELSE\n");
            stack *new = malloc(sizeof(stack));
            new->token = malloc(sizeof((*rpn_ready)->token) + 1);
            strcpy(new->token, (*rpn_ready)->token);
            new->token[strlen(new->token)] = '\0';
            new->prev = *result;
            *result = new;
        }
        (*rpn_ready) = (*rpn_ready)->next;
    }
}

void unaries(char *input, char *dest)
{
    char token[255], prev_token[255] = "", copy[255];
    int i = 0, j = 0, n = 0;
    while (input[i])
    {
        get_token(token, input + i, &i);
        if ((isdelim(prev_token[0]) || strlen(prev_token) == 0) && (strcmp(token, "+") == 0 || strcmp(token, "-") == 0))
        {
            printf("a");
            copy[j] = '(';
            copy[j + 1] = '0';
            copy[j + 2] = token[0];
            get_token(token, input + i, &i);
            j += 3;
            strcpy(copy + j, token);
            j += strlen(token);
            copy[j] = ')';
            j++;
        }
        else 
        {
            strcpy(copy + j, token);
            j += strlen(token);
        }
        printf("copy %s    %i %i inp: %s  token %s   %s\n", copy, i, j, input + i, token, prev_token);
        strcpy(prev_token, token);
    }

    strcpy(dest, copy);
}

char *scan_rpn(char *inp)
{
    rpn* rpn_ready = NULL;
    char *input;
    unaries(inp, input);
    printf("after unaries %s\n", input);
    dijkstra(input, &rpn_ready);
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
    return res_stack->token;
}

int main()
{
    scan_rpn("-2^3");
}
