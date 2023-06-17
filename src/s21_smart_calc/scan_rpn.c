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


// void count_function(rpn **rpn_ready)
// {

// }

void calculate(rpn **rpn_ready, stack **result)
{
    while (*rpn_ready)
    {
        if (*result == NULL && !isdelim((*rpn_ready)->token[0]) && !isfunc((*rpn_ready)->token))
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
            }
            else if (strcmp((*rpn_ready)->token, "/") == 0)
            {
                division(result);
            }
            else if (strcmp((*rpn_ready)->token, "*") == 0)
            {
                multiplication(result);
            }
            else if (strcmp((*rpn_ready)->token, "-") == 0)
            {
                difference(result);
            }
            else if (strcmp((*rpn_ready)->token, "%") == 0)
            {
                mod(result);
            }
            else if (strcmp((*rpn_ready)->token, "^") == 0)
            {
                power(result);
            }
            else if (strcmp((*rpn_ready)->token, "sin") == 0)
            {
                sinus(result);
            }
            else if (strcmp((*rpn_ready)->token, "cos") == 0)
            {
                cosinus(result);
            }
            else if (strcmp((*rpn_ready)->token, "tan") == 0)
            {
                tangent(result);
            }
            else if (strcmp((*rpn_ready)->token, "atan") == 0)
            {
                atangent(result);
            }
            else if (strcmp((*rpn_ready)->token, "acos") == 0)
            {
                acosinus(result);
            }
            else if (strcmp((*rpn_ready)->token, "asin") == 0)
            {
                asinus(result);
            }
            else if (strcmp((*rpn_ready)->token, "sqrt") == 0)
            {
                square(result);
            }
            else if (strcmp((*rpn_ready)->token, "ln") == 0)
            {
                ln_func(result);
            }
            else if (strcmp((*rpn_ready)->token, "log") == 0)
            {
                log_func(result);
            }
        }
        else
        {
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
    char token[255], prev_token[255] = "", copy[255] = "";
    int i = 0, j = 0;
    while (input[i])
    {
        get_token(token, input + i, &i);
        if ((strlen(prev_token) == 0 || isdelim(prev_token[0])) && (strcmp(token, "+") == 0 || strcmp(token, "-") == 0))
        {
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
        strcpy(prev_token, token);
    }
    strcpy(dest, copy);
}

int scan_rpn(char *inp, char *result)
{
    rpn* rpn_ready = NULL;
    char input[255];
    unaries(inp, input);
    printf("%s\n", input);
    dijkstra(input, &rpn_ready);
    stack* res_stack = NULL;
    calculate(&rpn_ready, &res_stack);
    printf("\nresult: %s\n", res_stack->token);
    strcpy(result, res_stack->token);
    free(res_stack->token);
    return 0;
}

//int main()
//{
//    char input[] = "-5.2";
//    double result_real = -5.4;
//    char result_s21[255];
//    scan_rpn(input, result_s21);
//    // printf("%f\n", result_real);
//    printf("%f\n", atof(result_s21));
//}
