#include <stdio.h>
#include <stdlib.h>

#define u64 unsigned long long
#define u32 unsigned int

FILE * file_input;
FILE * file_output;

int init();
void deinit();
void myqsort(int *arr, int left, int right);

int main(int argc, char const *argv[])
{
    /* Переменные */
    
    int N;
    int *A;

    /* Открытие файлов */
    if (init() < 0) return -1;

    /* Логика */
    
    fread(&N, 4, 1, file_input);
    A = malloc(sizeof(int) * N);
    fread(A, sizeof(int), N, file_input);

    myqsort(A, 0, N);
    fwrite(A, sizeof(int), N, file_output);

    
    /* Вывод и закрытие файлов */
    free(A);
    deinit();
    return 0;
}

int init()
{
    file_input = fopen("input.txt", "rb");
    file_output = fopen("output.txt", "wb");

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

void myqsort(int *arr, int left, int right)
{
    if (left <= right)
    {
        int pivot = arr[(left + right) / 2];
        int L = left, R = right;
        while (L <= R)
        {
            while (arr[L] < pivot)
                L++;
            while (arr[R] > pivot)
                R--;
            if (L <= R)
            {
                int t = arr[L];
                arr[L] = arr[R];
                arr[R] = t;
                L++;
                R--;
            }
        }
        
        myqsort(arr, left, R);
        myqsort(arr, L, right);
    }
}