#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define u64 unsigned long long
#define u32 unsigned int

FILE * file_input;
FILE * file_output;

int init();
void deinit();

int main(int argc, char const *argv[])
{
    /* Переменные */
    
    double Inf = INFINITY;
    int X = 5;

    /* Открытие файлов */
    if (init() < 0) return -1;

    /* Логика */
    
    X = X++ + ++X;
    printf("%llf", Inf / 1e300);

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