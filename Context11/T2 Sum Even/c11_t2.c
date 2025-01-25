#include <stdio.h>
#include <stdlib.h>

#define u64 unsigned long long
#define u32 unsigned int

FILE * file_input;
FILE * file_output;

typedef void (*callback)(void *ctx, int *value);

typedef struct node {
    int value;
    struct node *next;
} List;

int init();
void deinit();
void listInsert(List **lst, int val);
void listDelete(List **lst);

void arrayForeach(void *ctx, callback func, int *arr, int n);
void listForeach(void *ctx, callback func, List *lst);
void sum(void *ctx, int *value);

int *A = NULL;
List *L = NULL;

int main(int argc, char const *argv[])
{
    /* Переменные */
    
    int N;
    int buf;
    int resA, resL;

    /* Открытие файлов */
    if (init() < 0) return -1;

    /* Логика */
    
    fscanf(file_input, "%d", &N);

    // Для массива
    A = malloc(sizeof(int) * N);
    for (size_t i = 0; i < N; i++)
    {
        fscanf(file_input, "%d", &buf);
        A[i] = buf;
        List **tmp = &L;
        listInsert(&L, buf);
    }
    

    arrayForeach(&resA, sum, A, N);
    listForeach(&resL, sum, L);

    fprintf(file_output, "%d %d", resA, resL);
    listDelete(&L);
    
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

void listInsert(List **lst, int val)
{
    if ((*lst) == NULL)
    {
        (*lst) = calloc(1, sizeof(List));
        (*lst)->value = val;
    }
    else
    {
        while ((*lst)->next != NULL)
        {
            lst = &(*lst)->next;
        }
        (*lst)->next = calloc(1, sizeof(List));
        (*lst)->next->value = val;
    }
}

void listDelete(List **lst)
{
    //if (*lst == NULL) return;
    List *ptr = (*lst);
    while ((ptr) != NULL)
    {
        List *tmp = ptr;
        ptr = ptr->next;
        free(tmp);
    }
}

void sum(void *ctx, int *value)
{
    int v = *(int*)value;
    if (v % 2 == 0)
    {
        *(int*)ctx += v;
    }
}

void arrayForeach(void *ctx, callback func, int *arr, int n)
{
    if (func == sum)
    {
        int acc = 0;
        for (size_t i = 0; i < n; i++)
        {
            sum(&acc, &arr[i]);
        }
        *(int*)ctx = acc;
    }
}

void listForeach(void *ctx, callback func, List *lst)
{
    if (func == sum)
    {
        int acc = 0;
        while (lst != NULL)
        {
            sum(&acc, &lst->value);
            lst = lst->next;
        }
        *(int*)ctx = acc;
    }
}