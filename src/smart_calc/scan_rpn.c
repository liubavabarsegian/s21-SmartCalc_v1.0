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
    char res[10];
    sprintf(res, "%f", sin(atof((*result)->token)));
    free((*result)->token);
    (*result)->token = malloc(sizeof(strlen(res) + 1));
    strcpy((*result)->token, res);
}

void cosinus(stack **result)
{
    char res[10];
    sprintf(res, "%f", cos(atof((*result)->token)));
    free((*result)->token);
    (*result)->token = malloc(sizeof(strlen(res) + 1));
    strcpy((*result)->token, res);
}

void tangent(stack **result)
{
    char res[10];
    sprintf(res, "%f", tan(atof((*result)->token)));
    free((*result)->token);
    (*result)->token = malloc(sizeof(strlen(res) + 1));
    strcpy((*result)->token, res);
}

void atangent(stack **result)
{
    char res[10];
    sprintf(res, "%f", atan(atof((*result)->token)));
    free((*result)->token);
    (*result)->token = malloc(sizeof(strlen(res) + 1));
    strcpy((*result)->token, res);
}

void asinus(stack **result)
{
    char res[10];
    sprintf(res, "%f", asin(atof((*result)->token)));
    free((*result)->token);
    (*result)->token = malloc(sizeof(strlen(res) + 1));
    strcpy((*result)->token, res);
}

void acosinus(stack **result)
{
    char res[10];
    sprintf(res, "%f", acos(atof((*result)->token)));
    free((*result)->token);
    (*result)->token = malloc(sizeof(strlen(res) + 1));
    strcpy((*result)->token, res);
}

void square(stack **result)
{
    char res[10];
    sprintf(res, "%f", sqrt(atof((*result)->token)));
    free((*result)->token);
    (*result)->token = malloc(sizeof(strlen(res) + 1));
    strcpy((*result)->token, res);
}

void ln_func(stack **result)
{
    char res[10];
    sprintf(res, "%f", log(atof((*result)->token)));
    free((*result)->token);
    (*result)->token = malloc(sizeof(strlen(res) + 1));
    strcpy((*result)->token, res);
}

void log_func(stack **result)
{
    char res[10];
    sprintf(res, "%f", log10(atof((*result)->token)));
    free((*result)->token);
    (*result)->token = malloc(sizeof(strlen(res) + 1));
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
        else if (isdelim((*rpn_ready)->token[0]) || isfunc((*rpn_ready)->token))
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
        else if (!isdelim((*rpn_ready)->token[0]))
        {
            stack *new = malloc(sizeof(stack));
            new->token = malloc(sizeof((*rpn_ready)->token + 1));
            strcpy(new->token, (*rpn_ready)->token);
            new->token[strlen(new->token)] = '\0';
            new->prev = *result;
            *result = new;
        }
        (*rpn_ready) = (*rpn_ready)->next;
    }
}

char *scan_rpn(char *input)
{
    rpn* rpn_ready = NULL;
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
  scan_rpn("sin(1)^2");
}
