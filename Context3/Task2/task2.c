#include <stdio.h>
#include <stdlib.h>

#define u64 unsigned long long
#define u32 unsigned int
#define u16 unsigned short

FILE * file_input;
FILE * file_output;

int init();
void deinit();

int main(int argc, char const *argv[])
{
    /* Переменные */
    
    u16 N;
    u16 *A;

    /* Открытие файлов */
    if (init() < 0) return -1;

    /* Логика */

    fscanf(file_input, "%hd", &N);
    A = malloc(sizeof(*A)*N);

    for (char i = 0; i < N; i++)
    {
        fscanf(file_input, "%hd", A+i);
    }

    for (u16 i = 1; i <= N; i++)
    {
        u16 sum = 0;
        for (u16 j = 1; j <= N/i; j++)
        {
            sum += A[j*i-1];
        }
        fprintf(file_output, i==1 ? "%d" : " %d", sum);
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