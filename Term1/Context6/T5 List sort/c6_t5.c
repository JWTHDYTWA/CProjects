#include <stdio.h>
#include <stdlib.h>

#define u64 unsigned long long
#define u32 unsigned int

typedef struct node
{
    char str[8];
    struct node *next;
} Node;

FILE * file_input;
FILE * file_output;

int init();
void deinit();
char *new_node(Node **list);
void myqsort(int *arr, int left, int right);

Node *registry[1000000];
int cnt = 0;

int main(int argc, char const *argv[])
{
    /* Переменные */
    
    int N;

    /* Открытие файлов */
    if (init() < 0) return -1;

    /* Логика */
    
    fscanf(file_input, "%d", &N);
    for (size_t i = 0; i < N; i++)
    {
        int tmp;
        fscanf(file_input, "%d", &tmp);
        char *str = new_node(&registry[tmp]);
        fscanf(file_input, "%s", str);
        cnt++;
    }

    for (size_t i = 0; i < 1000000; i++)
    {
        if (cnt == 0) break;
        if (registry[i] != NULL)
        {
            Node *tmp = registry[i];
            do
            {
                fprintf(file_output, "%d %s\n", i, tmp->str);
                Node *old = tmp;
                tmp = tmp->next;
                cnt--;
                free(old);
            } while (tmp != NULL);
        }
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

char *new_node(Node **list)
{
    if (*list == NULL)
    {
        *list = malloc(sizeof(Node));
        (*list)->next = NULL;
        return (*list)->str;
    }
    else
    {
        while ((*list)->next != NULL)
        {
            list = &(*list)->next;
        }
        (*list)->next = malloc(sizeof(Node));
        (*list)->next->next = NULL;
        return (*list)->next->str;
    }
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