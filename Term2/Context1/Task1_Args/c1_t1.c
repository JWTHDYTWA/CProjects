#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define u64 unsigned long long
#define u32 unsigned int

enum operation {
    ADD,
    SUB,
    MUL
};

FILE * file_input;
FILE * file_output;

int init();
void deinit();

int main(int argc, char const *argv[])
{
    /* Переменные */
    
    char buf[32];
    long long a, b, m, op, res = 0;

    /* Открытие файлов */
    // if (init() < 0) return -1;

    /* Логика */

    if (argc == 1)
    {
        fprintf(stderr, "No parameters specified.");
        return -1;
    }

    // for (size_t i = 1; i < argc; i++)
    // {
    //     printf("%s ", argv[i]);
    // }
    // printf("\n");
    
    
    for (size_t i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-m") == 0)
        {
            sscanf(argv[++i], "%lld", &m);
        }
        else if (strcmp(argv[i], "add") == 0)
        {
            sscanf(argv[++i], "%lld", &a);
            sscanf(argv[++i], "%lld", &b);
            op = ADD;
        }
        else if (strcmp(argv[i], "sub") == 0)
        {
            sscanf(argv[++i], "%lld", &a);
            sscanf(argv[++i], "%lld", &b);
            op = SUB;
        }
        else if (strcmp(argv[i], "mul") == 0)
        {
            sscanf(argv[++i], "%lld", &a);
            sscanf(argv[++i], "%lld", &b);
            op = MUL;
        }
    }

    switch (op)
    {
    case ADD:
        res = a + b;
        break;
    
    case SUB:
        res = a - b;
        break;
    
    case MUL:
        res = a * b;
        break;
    }

    if (m)
    {
        res %= m;
        if (res < 0) res += m;
    }

    printf("%lld", res);

    /* Вывод и закрытие файлов */
    deinit();
    return 0;
}

int init()
{
    file_input = fopen("input.txt", "r");
    file_output = fopen("output.txt", "w");

    if (file_input == NULL ||  file_output == NULL)
    {
        return -1;
    }
    return 1;
}

void deinit()
{
    fclose(file_input);
    fclose(file_output);
}