#include <stdio.h>
#include <stdlib.h>

#define u64 unsigned long long
#define u32 unsigned int

FILE * file_input;
FILE * file_output;

int init();
void deinit();
void myqsort(int *arr, int left, int right);

int A[100000];
int B[100000];
int C[100000];
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
        fscanf(file_input, "%d", &A[i]);
    }
    myqsort(A, 0, N-1);

    fscanf(file_input, "%d", &M);
    for (size_t i = 0; i < M; i++)
    {
        fscanf(file_input, "%d", &B[i]);
    }
    myqsort(B, 0, M-1);
    
    int i = 0, j = 0;
    while (i < N && j < M)
    {
        if (A[i] > B[j])
        {
            j++;
        }
        else if (A[i] < B[j])
        {
            C[count] = A[i++];
            while (A[i] == C[count] && i < N) i++;
            count++;
        }
        else
        {
            i++;
        }
    }
    while (i < N)
    {
        C[count] = A[i++];
        while (A[i] == C[count] && i < N) i++;
        count++;
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

/* 
int mergesort_nub(int *copy_ar, int *ar, int left, int right)
{
    if (right - left < 2)
        return left;
    if (right - left == 2)
    {
        if (ar[left] > ar[left + 1])
        {
            int temp = ar[left];
            ar[left] = ar[left + 1];
            ar[left + 1] = temp;
            return right;
        }
        else if (ar[left] == ar[left+1])
        {
            return left;
        }
    }
    int mid = (right + left) / 2;
    int idx = left, i = left, j = mid;
    int im = mergesort_nub(copy_ar, ar, left, mid);
    int jm = mergesort_nub(copy_ar, ar, mid, right);
    // слияние левой и правой сторон Аr
    // Todo
    while (idx < im + jm - mid) {
        if (j >= jm || (i < im && ar[i] < ar[j])) {
            if (idx > left && copy_ar[idx-1] == ar[i]) {
                i++;
                continue;
            }
            copy_ar[idx] = ar[i];
            i++;
        } else if (j < jm && i < im && ar[i] == ar[j]) {
            if (idx > left && copy_ar[idx-1] == ar[i]) {
                i++;
                j++;
                continue;
            }
            copy_ar[idx] = ar[i];
            i++;
            j++;
        } else {
            if (idx > left && copy_ar[idx-1] == ar[j]) {
                j++;
                continue;
            }
            copy_ar[idx] = ar[j];
            j++;
        }
        idx++;
    }
    for(int k = left; k < idx; k++) {
        ar[k] = copy_ar[k];
    }
    return idx;
}
 */