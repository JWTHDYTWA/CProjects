#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct stc {
    int *arr;
    int sp;
} Stack;

enum operations {
    NONE, NUMBER, ADD, MUL
};

void stackInit(Stack *st, int size);
void stackDeinit(Stack *st);

unsigned int hash(char *str);
int main(int argc, char const *argv[])
{
    /* Переменные */
    
    char buffer[32];
    char o;
    int a, b, res;

    /* Открытие файлов */

    FILE * file_input = fopen("input.txt", "r");
    FILE * file_output = fopen("output.txt", "w");

    if (file_input == NULL ||  file_output == NULL)
    {
        perror("File error");
        return 1;
    }

    /* Логика */
    
    long long x = -65535;
    printf("i:%lld\n", x);

    while (1)
    {
        scanf("%d %c %d", &a, &o, &b);
        switch (o)
        {
        case '+':
            res = a + b;
            break;
        case '-':
            res = a - b;
            break;
        case '*':
            res = a * b;
            break;
        case '/':
            res = a / b;
            break;
        }
        printf("%d\n", res);
    }
    

    /* Вывод и закрытие файлов */
    
    fclose(file_input);
    fclose(file_output);
    return 0;
}

unsigned int hash(char *str)
{
    double A = 0.6180339887498949;
    double acc = 0;
    unsigned int c = 1;
    while (*str != '\0')
    {
        acc += (*str) * (c *= 173) * A;
        acc -= (int) acc;
        str++;
    }
    return acc * 0xFFFFFFFF;
}

void stackInit(Stack *st, int size)
{
    st->arr = malloc(sizeof(int)*size);
    st->sp = 0;
}

void stackDeinit(Stack *st)
{
    free(st->arr);
    st->arr = NULL;
    st->sp = 0;
}

int calc(char *str)
{
    int num_stack[32], num_sp = 0;
    int op_stack[32], op_sp = 0;
    char buff;
    char brackets = 0;
    char cont = 0;
    char last = 0;
    while (*str != '\0')
    {
        sscanf(str, "%c", &buff);
        if (buff >= '0' && buff <= '9')
        {
            num_stack[num_sp] += (buff-'0') * cont;
            cont *= 10;
        }
        else if (buff == '+' || buff == '-')
        {
            cont = 1;
        }
        else if (buff == '-')
        {

        }
        str++;
    }

    return num_stack[0];
}