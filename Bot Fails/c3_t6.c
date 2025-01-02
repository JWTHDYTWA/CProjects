#include <stdio.h>
#include <stdlib.h>

#define u64 unsigned long long
#define u32 unsigned int

FILE * file_input;
FILE * file_output;

int init();
void deinit();

short A[100000];
short B[100000];
short C[100000];
int count = 0;

int main(int argc, char const *argv[])
{
    /* Переменные */
    
    int N, M;

    /* Открытие файлов */
    if (init() < 0) return -1;

    /* Логика */
    
    fscanf(file_input, "%d", &N);
    for (size_t i = 0; i < N; i++)
    {
        fscanf(file_input, "%hd", &A[i]);
    }
    fscanf(file_input, "%d", &M);
    for (size_t i = 0; i < M; i++)
    {
        fscanf(file_input, "%hd", &B[i]);
    }
    
    for (size_t i = 0; i < N; i++)
    {
        int notIncl = 0;
        for (size_t j = 0; j < count; j++)
        {
            if (A[i] == C[j])
            {
                notIncl = 1;
                break;
            }
            
        }
        if (!notIncl)
        for (size_t j = 0; j < M; j++)
        {
            if (A[i] == B[j])
            {
                notIncl = 1;
                break;
            }
        }
        
        if (!notIncl)
        {
            C[count] = A[i];
            count++;
        }
    }
    
    fprintf(file_output, "%d\n", count);
    for (size_t i = 0; i < count; i++)
    {
        fprintf(file_output, "%hd ", C[i]);
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