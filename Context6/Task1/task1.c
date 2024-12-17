#include <stdio.h>
#include <stdlib.h>

#define u64 unsigned long long
#define u32 unsigned int

FILE * file_input;
FILE * file_output;

typedef struct {
    double value;
    int next;
} Node;

int init();
void deinit();

Node field[100000];

int main(int argc, char const *argv[])
{
    /* Переменные */
    
    int N, F;
    float fbuf;
    int ibuf;

    /* Открытие файлов */
    if (init() < 0) return -1;

    /* Логика */
    
    fscanf(file_input, "%d%d", &N, &F);

    for (int i = 0; i < N; i++)
    {
        fscanf(file_input, "%lf%d", &field[i].value, &field[i].next);
    }

    while (F != -1)
    {
        fprintf(file_output, "%.3lf\n", field[F].value);
        F = field[F].next;
    }
    
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