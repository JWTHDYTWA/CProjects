#include <stdio.h>
#include <stdlib.h>

#define u64 unsigned long long
#define u32 unsigned int

FILE * file_input;
FILE * file_output;

int init();
void deinit();

int merge ( const int *a , int ak , const int *b , int bk , int * res );
void myqsort(int *arr, int left, int right);

int main(int argc, char const *argv[])
{
    /* Переменные */
    
    int N, M;
    int *A, *B;
    int *Merged;

    /* Открытие файлов */
    if (init() < 0) return -1;

    /* Логика */
    
    fread(&N, sizeof(int), 1, file_input);
    fread(&M, sizeof(int), 1, file_input);

    A = malloc(sizeof(int) * N);
    B = malloc(sizeof(int) * M);
    Merged = malloc(sizeof(int) * (M+N));
    
    fread(A, sizeof(int), N, file_input);
    fread(B, sizeof(int), M, file_input);
    
    merge(A, N, B, M, Merged);
    
    fwrite(Merged, sizeof(int), N+M, file_output);
    
    /* Вывод и закрытие файлов */
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

int merge ( const int *a , int ak , const int *b , int bk , int * res )
{
    int *cur = res;
    for (int i = 0; i < ak; i++)
    {
        *cur = a[i];
        cur++;
    }
    for (int i = 0; i < bk; i++)
    {
        *cur = b[i];
        cur++;
    }
    myqsort(res, 0, ak+bk-1);
    return ak+bk;
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
