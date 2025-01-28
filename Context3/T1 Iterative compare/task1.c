#include <stdio.h>
#include <stdlib.h>

#define u64 unsigned long long
#define u32 unsigned int

FILE * file_input;
FILE * file_output;

int init();
void deinit();

int main(int argc, char const *argv[])
{
    /* Переменные */
    
    u32 N;
    u32 *B;

    /* Открытие файлов */
    if (init() < 0) return -1;

    /* Логика */
    
    fscanf(file_input, "%d", &N);
    B = malloc(sizeof(*B)*N);

    for (char i = 0; i < N; i++)
    {
        fscanf(file_input, "%d", B+i);
    }
    
    for (char i = 0; i < N; i++)
    {
        char cnt = 0;
        for (char j = i+1; j < N; j++)
        {
            if (B[j] < B[i]) cnt++;
        }
        fprintf(file_output, i==0 ? "%d" : " %d", cnt);
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