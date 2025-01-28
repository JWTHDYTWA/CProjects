#include <stdio.h>
#include <stdlib.h>

#define u64 unsigned long long
#define u32 unsigned int

FILE * file_input;
FILE * file_output;

int init();
void deinit();
void mergesort_nub(int *copy_ar, int *ar, int left, int right);

int main(int argc, char const *argv[])
{
    /* Переменные */
    
    int N;
    int *A;
    int *B;

    /* Открытие файлов */
    if (init() < 0) return -1;

    /* Логика */
    
    fread(&N, 4, 1, file_input);
    A = malloc(sizeof(int)*N);
    B = malloc(sizeof(int)*N);
    fread(A, 4, N, file_input);

    mergesort_nub(B, A, 0, N);

    fwrite(B, 4, N, file_output);
    free(A);
    free(B);
    
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

void mergesort_nub(int *copy_ar, int *ar, int left, int right)
{
    if (right - left < 2)
        return;
    if (right - left == 2)
    {
        if (ar[left] > ar[left + 1])
        {
            int temp = ar[left];
            ar[left] = ar[left + 1];
            ar[left + 1] = temp;
        }
        return;
    }
    int mid = (right + left) / 2;
    mergesort_nub(copy_ar, ar, left, mid);
    mergesort_nub(copy_ar, ar, mid, right);
    // слияние левой и правой сторон Аr
    int i = left, j = mid, idx = left;
    while (idx < right)
    {
        if (j >= right || (i < mid && ar[i] < ar[j]))
        {
            copy_ar[idx] = ar[i];
            i += 1;
        }
        else
        {
            copy_ar[idx] = ar[j];
            j += 1;
        }
        idx += 1;
    }
    for(int k = left; k < right; k++) {
        ar[k] = copy_ar[k];
    }
}