#include <stdio.h>
#include <stdlib.h>

#define u64 unsigned long long
#define u32 unsigned long

FILE * file_input;
FILE * file_output;

int init();
void deinit();

int main(int argc, char const *argv[])
{
    /* Переменные */
    int L, R, K;
    int count = 0;

    /* Инициализация */
    if (init()) return 1;

    /* Логика */
    fscanf(file_input, "%d %d %d", &L, &R, &K);
    // printf("Left border: %d\nRight Border: %d\nCondition: %d\n\n", L, R, K);
    int range = R-L+1;
    int limit = range / (K-1);

    for (int i = 1; i <= range && i <= limit; i++)
    {
        int sequence_w = K + (i - 1) * (K - 1);
        int x = range - sequence_w + 1;
        int variations = min(i,x);
        // printf("Width for %d: %d, x = %d\n", i, sequence_w, x);
        // printf("Iteration %d: %d variations\n\n", i, variations);
        count += variations;
    }
    fprintf(file_output, "%d", count);
    
    /* Деинициализация */
    deinit();
    return 0;
}

int init()
{
    file_input = fopen("input.txt", "r");
    file_output = fopen("output.txt", "w");

    if (file_input == NULL ||  file_output == NULL)
    {
        return 1;
    }
    return 0;
}

void deinit()
{
    fclose(file_input);
    fclose(file_output);
}