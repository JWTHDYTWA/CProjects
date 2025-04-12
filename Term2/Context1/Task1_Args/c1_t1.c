#include <stdio.h>
#include <stdlib.h>

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
int match(const char *str1, const char *str2);

int main(int argc, char const *argv[])
{
    /* Переменные */
    
    char buf[32];
    long long a, b, m, op, res = 0;

    /* Открытие файлов */

    /* Логика */

    if (argc == 1)
    {
        fprintf(stderr, "No parameters specified.");
        return 13;
    }
    
    for (size_t i = 1; i < argc; i++)
    {
        if (match(argv[i], "-m"))
        {
            sscanf(argv[++i], "%lld", &m);
        }
        else if (match(argv[i], "add"))
        {
            sscanf(argv[++i], "%lld", &a);
            sscanf(argv[++i], "%lld", &b);
            op = ADD;
        }
        else if (match(argv[i], "sub"))
        {
            sscanf(argv[++i], "%lld", &a);
            sscanf(argv[++i], "%lld", &b);
            op = SUB;
        }
        else if (match(argv[i], "mul"))
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

int match(const char *str1, const char *str2)
{
    while (*str1 != '\0' && *str2 != '\0')
    {
        if (*str1 != *str2)
        {
            return 0;
        }
        str1++;
        str2++;
    }
    return 1;
}