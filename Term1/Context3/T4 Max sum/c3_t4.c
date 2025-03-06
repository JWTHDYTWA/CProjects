#include <stdio.h>
#include <stdlib.h>

#define u64 unsigned long long
#define u32 unsigned int

#define ARR_SIZE

FILE * file_input;
FILE * file_output;

int init();
void deinit();

int arr[5000];

int main(int argc, char const *argv[])
{
    /* Переменные */
    
    int N;

    /* Открытие файлов */
    if (init() < 0) return -1;

    /* Логика */
    
    fscanf(file_input, "%d", &N);
    for (size_t i = 0; i < N; i++)
    {
        fscanf(file_input, "%d", &arr[i]);
    }
    
    int L = 0,
        R = 0,
        temp_L = 0,
        max_cur = arr[0],
        max = arr[0];
    
    for (size_t i = 1; i < N; i++)
    {
        if (max_cur <= 0)
        {
            max_cur = arr[i];
            temp_L = i;
        }
        else
            max_cur += arr[i];
        
        if (max_cur > max)
        {
            max = max_cur;
            L = temp_L;
            R = i;
        }
    }
    
    fprintf(file_output, "%d %d %d", L, R, max);
    
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