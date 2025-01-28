#include <stdio.h>
#include <stdlib.h>

#define i64 long long
#define u64 unsigned long long
#define u32 unsigned int

FILE * file_input;
FILE * file_output;

int init();
void deinit();

int main(int argc, char const *argv[])
{
    /* Переменные */
    
    int N;
    int P, Q;
    i64 M;

    /* Открытие файлов */
    if (init() < 0) return -1;

    /* Логика */
    
    fscanf(file_input, "%d", &N);
    for (size_t i = 0; i < N; i++)
    {
        fscanf(file_input, "%d/%d xor %llx", &P, &Q, &M);
        double div = (double) P / Q;
        i64 hogged = *(i64*)&div ^ M;
        div = *(double*)&hogged;
        fprintf(file_output, "%0.15g\n", div);
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