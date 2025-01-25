#include <stdio.h>
#include <stdlib.h>

#define u64 unsigned long long
#define u32 unsigned int

FILE * file_input;
FILE * file_output;

int init();
void deinit();

int main(int argc, char const *argv[])
{
    /* Переменные */
    
    

    /* Открытие файлов */
    if (init() < 0) return -1;

    /* Логика */
    
    
    
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

static void heapify(void **ar, int (*cmp)(const void *, const void *), int idx, int max)
{
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    int largest;
    if (left < max && cmp(ar[left], ar[idx]) > 0)
    {
        largest = left;
    }
    else
    {
        largest = idx;
    }
    if (right < max && cmp(ar[right], ar[largest]) > 0)
    {
        largest = right;
    }
    if (largest != idx)
    {
        void *tmp;
        tmp = ar[idx];
        ar[idx] = ar[largest];
        ar[largest] = tmp;
        heapify(ar, cmp, largest, max);
    }
}
static void buildHeap(void **ar, int (*cmp)(const void *, const void *), int n)
{
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
    {
        heapify(ar, cmp, i, n);
    }
}

void sortPointers(void **ar, int n, int (*cmp)(const void *, const void *))
{
    int i;
    buildHeap(ar, cmp, n);
    for (i = n - 1; i >= 1; i--)
    {
        void *tmp;
        tmp = ar[0];
        ar[0] = ar[i];
        ar[i] = tmp;
        heapify(ar, cmp, 0, i);
    }
}