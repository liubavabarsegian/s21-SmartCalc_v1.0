#include "scan_rpn.h"

void sum(stack **result)
{
    char sum[255];
    if (strchr((*result)->token, ',') || ((*result)->prev->token && (strchr((*result)->prev->token, ','))))
        sprintf(sum, "%lf", atof((*result)->token) + atof((*result)->prev->token));
    else if (strchr((*result)->token, '.') || ((*result)->prev->token && (strchr((*result)->prev->token, '.'))))
        sprintf(sum, "%lf", atof((*result)->token) + atof((*result)->prev->token));
    else
        sprintf(sum, "%d", atoi((*result)->token) + atoi((*result)->prev->token));
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
    sprintf(res, "%lf", atof((*result)->prev->token) / atof((*result)->token));
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
    if (strchr((*result)->token, ',') || ((*result)->prev->token && (strchr((*result)->prev->token, ','))))
        sprintf(res, "%lf", atof((*result)->prev->token) * atof((*result)->token));
    else if (strchr((*result)->token, '.') || ((*result)->prev->token && (strchr((*result)->prev->token, '.'))))
        sprintf(res, "%lf", atof((*result)->prev->token) * atof((*result)->token));
    else
        sprintf(res, "%d", atoi((*result)->prev->token) * atoi((*result)->token));
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
    if (strchr((*result)->token, ',') || ((*result)->prev->token && (strchr((*result)->prev->token, ','))))
        sprintf(res, "%lf", atof((*result)->prev->token) - atof((*result)->token));
    else if (strchr((*result)->token, '.') || ((*result)->prev->token && (strchr((*result)->prev->token, '.'))))
        sprintf(res, "%lf", atof((*result)->prev->token) - atof((*result)->token));
    else
        sprintf(res, "%d", atoi((*result)->prev->token) - atoi((*result)->token));
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
    if (strchr((*result)->token, ',') || ((*result)->prev->token && (strchr((*result)->prev->token, ','))))
        sprintf(res, "%f", fmod(atof((*result)->prev->token), atof((*result)->token)));
    else if (strchr((*result)->token, '.') || ((*result)->prev->token && (strchr((*result)->prev->token, '.'))))
        sprintf(res, "%f", fmod(atof((*result)->prev->token), atof((*result)->token)));
    else
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
    if (strchr((*result)->token, ',') || ((*result)->prev->token && (strchr((*result)->prev->token, ','))))
        sprintf(res, "%lf", pow(atof((*result)->prev->token),atof((*result)->token)));
    else if (strchr((*result)->token, '.') || ((*result)->prev->token && (strchr((*result)->prev->token, '.'))))
        sprintf(res, "%lf", pow(atof((*result)->prev->token),atof((*result)->token)));
    else
        sprintf(res, "%lf", pow(atoi((*result)->prev->token),atoi((*result)->token)));
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
    if (strchr((*result)->token, ','))
        sprintf(res, "%lf", sin(atof((*result)->token)));
    else if (strchr((*result)->token, '.'))
        sprintf(res, "%lf", sin(atof((*result)->token)));
    else
        sprintf(res, "%lf", sin(atoi((*result)->token)));
    free((*result)->token);
    (*result)->token = malloc(sizeof(strlen(res) + 1));
    strcpy((*result)->token, res);
}

void cosinus(stack **result)
{
    char res[255];
    if (strchr((*result)->token, ','))
        sprintf(res, "%lf", cos(atof((*result)->token)));
    else if (strchr((*result)->token, '.'))
        sprintf(res, "%lf", cos(atof((*result)->token)));
    else
        sprintf(res, "%lf", cos(atoi((*result)->token)));
    free((*result)->token);
    (*result)->token = malloc(sizeof(strlen(res) + 1));
    strcpy((*result)->token, res);
}

void tangent(stack **result)
{
    char res[255];
    if (strchr((*result)->token, ','))
        sprintf(res, "%lf", tan(atof((*result)->token)));
    else if (strchr((*result)->token, '.'))
        sprintf(res, "%lf", tan(atof((*result)->token)));
    else
        sprintf(res, "%lf", tan(atoi((*result)->token)));
    free((*result)->token);
    (*result)->token = malloc(sizeof(strlen(res) + 1));
    strcpy((*result)->token, res);
}

void atangent(stack **result)
{
    char res[255];
    if (strchr((*result)->token, ','))
        sprintf(res, "%lf", atan(atof((*result)->token)));
    else if (strchr((*result)->token, '.'))
        sprintf(res, "%lf", atan(atof((*result)->token)));
    else
        sprintf(res, "%lf", atan(atoi((*result)->token)));
    free((*result)->token);
    (*result)->token = malloc(sizeof(strlen(res) + 1));
    strcpy((*result)->token, res);
}

void asinus(stack **result)
{
    char res[255];
    if (strchr((*result)->token, ','))
        sprintf(res, "%lf", asin(atof((*result)->token)));
    else if (strchr((*result)->token, '.'))
        sprintf(res, "%lf", asin(atof((*result)->token)));
    else
        sprintf(res, "%lf", asin(atoi((*result)->token)));
    free((*result)->token);
    (*result)->token = malloc(sizeof(strlen(res) + 1));
    strcpy((*result)->token, res);
}

void acosinus(stack **result)
{
    char res[255];
    if (strchr((*result)->token, ','))
        sprintf(res, "%lf", acos(atof((*result)->token)));
    else if (strchr((*result)->token, '.'))
        sprintf(res, "%lf", acos(atof((*result)->token)));
    else
        sprintf(res, "%lf", acos(atoi((*result)->token)));
    free((*result)->token);
    (*result)->token = malloc(sizeof(strlen(res) + 1));
    strcpy((*result)->token, res);
}

void square(stack **result)
{
    char res[255];
    if (strchr((*result)->token, ','))
        sprintf(res, "%lf", sqrt(atof((*result)->token)));
    else if (strchr((*result)->token, '.'))
        sprintf(res, "%lf", sqrt(atof((*result)->token)));
    else
        sprintf(res, "%lf", sqrt(atoi((*result)->token)));
    free((*result)->token);
    (*result)->token = malloc(sizeof(strlen(res) + 1));
    strcpy((*result)->token, res);
}

void ln_func(stack **result)
{
    char res[255];
    if (strchr((*result)->token, ','))
        sprintf(res, "%lf", log(atof((*result)->token)));
    else if (strchr((*result)->token, '.'))
        sprintf(res, "%lf", log(atof((*result)->token)));
    else
        sprintf(res, "%lf", log(atoi((*result)->token)));
    free((*result)->token);
    (*result)->token = malloc(sizeof(strlen(res) + 1));
    strcpy((*result)->token, res);
}

void log_func(stack **result)
{
    char res[255];
    if (strchr((*result)->token, ','))
        sprintf(res, "%lf", log10(atof((*result)->token)));
    else if (strchr((*result)->token, '.'))
        sprintf(res, "%lf", log10(atof((*result)->token)));
    else
        sprintf(res, "%lf", log10(atoi((*result)->token)));
    free((*result)->token);
    (*result)->token = malloc(sizeof(strlen(res) + 1));
    strcpy((*result)->token, res);
}

void count_function(rpn **rpn_ready, stack **result)
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
    if (strchr((*result)->token, ',') || strchr((*result)->token, '.'))
    {
        int i = strlen((*result)->token) - 1;
        while ((*result)->token[i] == '0')
        {
            char *copy;
            copy = malloc(i);
            strncpy(copy, (*result)->token, i);
            free((*result)->token);
            (*result)->token = malloc(i);
            if ((*result)->token)
            {
                strncpy((*result)->token, copy, i);
                (*result)->token[i ] = '\0';
            }
            i -= 1;
            free(copy);
        }
    }
}

int several_dots(char *str)
{
    int i = 0;
    int count = 0;
    while (str[i])
    {
        if (str[i] == '.' || str[i] == ',')
            count++;
        i++;
    }
    return (count > 1);
}

int calculate(rpn **rpn_ready, stack **result)
{
    int flag = SUCCESS;
    while (*rpn_ready)
    {
        if (*rpn_ready && (*rpn_ready)->token && several_dots((*rpn_ready)->token))
        {    
            flag = FAILURE;
            break;
        }
        else if (*result == NULL && !isdelim((*rpn_ready)->token[0]) && !isfunc((*rpn_ready)->token))
        {
            *result = malloc(sizeof(stack));
            (*result)->token = malloc(sizeof((*rpn_ready)->token + 1));
            (*result)->prev = NULL;
            strcpy((*result)->token, (*rpn_ready)->token);
        }
        else if (isdelim((*rpn_ready)->token[0]) || isfunc((*rpn_ready)->token))
        {
            count_function(rpn_ready, result);
        }
        else
        {
            stack *new = malloc(sizeof(stack));
            new->token = malloc(sizeof((*rpn_ready)->token) + 1);
            if (!new || !new->token)
                flag = FAILURE;
            else
            {
                strcpy(new->token, (*rpn_ready)->token);
                new->token[strlen(new->token)] = '\0';
                new->prev = *result;
                *result = new;
            }
        }
        if (flag != FAILURE)
            (*rpn_ready) = (*rpn_ready)->next;
    }
    return flag;
}

int unaries(char *input, char *dest)
{
    int flag = SUCCESS;
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
        // if ((strlen(prev_token) == 0 || isdelim(prev_token[0])) && isdelim(token[0]))
        //     flag = FAILURE;
        else
        {
            strcpy(copy + j, token);
            j += strlen(token);
        }
        strcpy(prev_token, token);
    }
    strcpy(dest, copy);
    return flag;
}

int scan_rpn(char *inp, char *result)
{
    int flag = SUCCESS;
    if (strlen(inp) == 0)
        flag = FAILURE;
    else if (!result)
        flag = FAILURE;
    else 
    {
        rpn* rpn_ready = NULL;
        char input[255];
        unaries(inp, input);
        if (dijkstra(input, &rpn_ready) == FAILURE)
            flag = FAILURE;
        else 
        {
            stack* res_stack = NULL;
            if (calculate(&rpn_ready, &res_stack) == FAILURE)
                flag = FAILURE;
            else
                strcpy(result, res_stack->token);
            if (res_stack && res_stack->token)
                free(res_stack->token);
            if (res_stack)
                free(res_stack);
        }
    }
    return flag;
}

// int main()
// {
//    char input[] = "9^4 - 78 / 5";
//    char result_s21[255];
//    printf("%d\n", scan_rpn(input, result_s21));
//    printf("%s\n", result_s21);
// }
