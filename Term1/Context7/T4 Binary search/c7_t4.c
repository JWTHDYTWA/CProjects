#include <stdio.h>
#include <stdlib.h>

#define u64 unsigned long long
#define u32 unsigned int

FILE * file_input;
FILE * file_output;

int init();
void deinit();
int bin_search_closest(int *arr, int size, int x);

int main(int argc, char const *argv[])
{
    /* Переменные */
    
    int N, Q;
    int *A;

    int R_old = 0;
    int X;

    /* Открытие файлов */
    if (init() < 0) return -1;

    /* Логика */
    
    fscanf(file_input, "%d", &N);
    A = malloc(sizeof(int) * N);
    for (size_t i = 0; i < N; i++)
    {
        fscanf(file_input, "%d", &A[i]);
    }

    fscanf(file_input, "%d", &Q);
    for (size_t i = 0; i < Q; i++)
    {
        fscanf(file_input, "%d", &X);
        X += R_old;
        R_old = bin_search_closest(A, N, X);
        fprintf(file_output, "%d\n", R_old);
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

int bin_search_closest(int *arr, int size, int x)
{
    int l = 0;
    int r = size - 1;
    int m;
    while (l <= r)
    {
        m = (l + r) / 2;
        if (arr[m] == x)
        {
            int maxi = m;
            while (arr[maxi+1] == x) maxi++;
            return maxi;
        }
        else if (arr[m] > x)
        {
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    return -1;
}