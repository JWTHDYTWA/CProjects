#include <stdio.h>
#include <stdlib.h>

#define u64 unsigned long long
#define u32 unsigned int

FILE * file_input;
FILE * file_output;

int init();
void deinit();
int bin_search_closest(int *arr, int size, int x);
int find_dist(int *arr, int size, int x, int *ind);

int main(int argc, char const *argv[])
{
    /* Переменные */
    
    int N, Q;
    int *arr;

    /* Открытие файлов */
    if (init() < 0) return -1;

    /* Логика */
    
    fscanf(file_input, "%d", &N);
    arr = malloc(sizeof(int) * N);
    for (size_t i = 0; i < N; i++)
    {
        fscanf(file_input, "%d", &arr[i]);
    }

    fscanf(file_input, "%d", &Q);
    for (size_t i = 0; i < Q; i++)
    {
        int x;
        fscanf(file_input, "%d", &x);
        int ind = bin_search_closest(arr, N, x);
        int dist = find_dist(arr, N, x, &ind);
        fprintf(file_output, "%d %d\n", ind, dist);
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
            return m;
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
    return m;
}

int find_dist(int *arr, int size, int x, int *ind)
{
    if (arr[*ind] > x)
    {
        while (arr[*ind-1] == arr[*ind] && *ind > 0) *ind--;
        return min(x - arr[*ind-1], arr[*ind] - x);
    }
    else if (arr[*ind] < x)
    {
        while (arr[*ind+1] == arr[*ind] && *ind < size - 1) *ind++;
        return min(x - arr[*ind], arr[*ind+1] - x);
    }
    else return 0;
}