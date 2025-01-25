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
    
    int N, M;
    int *A, *B, *C;

    /* Открытие файлов */
    if (init() < 0) return -1;

    /* Логика */
    
    fscanf(file_input, "%d", &N);
    A = malloc(sizeof(int)*N);
    for (size_t i = 0; i < N; i++)
    {
        fscanf(file_input, "%d", &A[i]);
    }
    
    fscanf(file_input, "%d", &M);
    B = malloc(sizeof(int)*M);
    for (size_t i = 0; i < M; i++)
    {
        fscanf(file_input, "%d", &B[i]);
    }
    
    myqsort(A, 0, N-1);
    myqsort(B, 0, M-1);

    C = malloc(sizeof(int)*N);
    int *cc = C;
    int cl = 0;
    int *ac = A, *bc = B;
    int *am = A + N - 1;
    int *bm = B + M - 1;

    while (ac <= am && bc <= bm)
    {
        if (*ac > *bc)
        {
            bc++;
        }
        else if (*ac < *bc)
        {
            *cc = *(ac++);
            while (*ac == *cc) ac++;
            cc++;
            cl++;
        }
        else
        {
            ac++;
        }
    }
    
    fprintf(file_output, "%d\n", cl);
    for (size_t i = 0; i < cl; i++)
    {
        fprintf(file_output, "%d ", C[i]);
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