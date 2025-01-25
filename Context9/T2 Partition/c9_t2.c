#include <stdio.h>
#include <stdlib.h>

#define u64 unsigned long long
#define u32 unsigned int

enum select {
    LEFT, RIGHT
};

FILE * file_input;
FILE * file_output;

int init();
void deinit();

int partition (int *a , int n , int pivot );
void myqsort(int *arr, int left, int right);

int A[100];

int main(int argc, char const *argv[])
{
    /* Переменные */
    
    int N;
    int P;
    // int *A;

    /* Открытие файлов */
    if (init() < 0) return -1;

    /* Логика */
    
    fread(&N, sizeof(int), 1, file_input);
    fread(&P, sizeof(int), 1, file_input);

    // A = malloc(sizeof(int) * N);
    
    fread(A, sizeof(int), N, file_input);
    
    int count = partition(A, N, P);
    
    fwrite(&count, sizeof(int), 1, file_output);
    fwrite(A, sizeof(int), N, file_output);
    
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

int partition (int *a , int n , int pivot )
{
    int p = pivot;
    int L = 0, R = 0;
    int parity = RIGHT;
    while (L < n && R < n)
    {
        while (a[L] < p)
            L++;
        while (a[R] > p)
            R++;
        if (L < n && R < n)
        {
            if (a[L] == p && a[R] != p)
            {
                if (parity == LEFT)
                {
                    int t = a[L];
                    a[L] = a[R];
                    a[R] = t;
                    L++;
                    R++;
                    parity = RIGHT;
                }
                else parity = LEFT;
            }
            else if (a[L] != p && a[R] == p)
            {
                if (parity == RIGHT)
                {
                    int t = a[L];
                    a[L] = a[R];
                    a[R] = t;
                    L++;
                    R++;
                    parity = LEFT;
                }
                else parity = RIGHT;
            }
            else
            {
                int t = a[L];
                a[L] = a[R];
                a[R] = t;
            }
            L++;
            R++;
        }
    }
    return L;
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
