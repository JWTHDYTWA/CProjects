#include <stdio.h>
#include <stdlib.h>

#define u64 unsigned long long
#define u32 unsigned int

#define FROM_RIGHT(x) (x & 8)
#define FROM_BOTTOM(x) (x & 4)
#define TO_RIGHT(x) (x & 2)
#define TO_BOTTOM(x) (x & 1)

FILE * file_input;
FILE * file_output;

enum codes {
    OK,
    EMPTY_DECK
};

typedef struct ring {
    int *Arr;
    int Bot, Top;
    int Size, Count;
} Ring;

int init();
void deinit();

int init_ring(Ring *r, int size);
void insert_on_top(Ring *r, int n);
void insert_on_bottom(Ring *r, int n);
int rm_from_top(Ring *r, int *b);
int rm_from_bottom(Ring *r, int *b);

int main(int argc, char const *argv[])
{
    /* Переменные */
    
    int N, M;
    Ring L, R;
    char cmd[2] = "\0", op;

    /* Открытие файлов */
    if (init() < 0) return -1;

    /* Логика */
    
    fscanf(file_input, "%d", &N);
    init_ring(&L, N*2+1);
    init_ring(&R, N*2+1);
    for (size_t i = 1; i <= N; i++)
    {
        insert_on_bottom(&L, i);
        insert_on_bottom(&R, -i);
    }
    fscanf(file_input, "%d", &M);
    for (size_t i = 0; i < M; i++)
    {
        fscanf(file_input, "\n%c", cmd);
        sscanf(cmd, "%hhx", &op);
        Ring *from, *to;
        int tmp, status;
        from = FROM_RIGHT(op) ? &R : &L;
        to = TO_RIGHT(op) ? &R : &L;

        if (FROM_BOTTOM(op))
            status = rm_from_bottom(from, &tmp);
        else
            status = rm_from_top(from, &tmp);

        if (status == EMPTY_DECK) continue;

        if (TO_BOTTOM(op))
            insert_on_bottom(to, tmp);
        else
            insert_on_top(to, tmp);
    }
    
    fprintf(file_output, "%d  ", L.Count);
    for (size_t i = 0; i < L.Count; i++)
    {
        fprintf(file_output, "%d ", L.Arr[(L.Top+L.Size-i)%L.Size]);
    }
    fprintf(file_output, "\n%d  ", R.Count);
    for (size_t i = 0; i < R.Count; i++)
    {
        fprintf(file_output, "%d ", R.Arr[(R.Top+R.Size-i)%R.Size]);
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

int init_ring(Ring *r, int size)
{
    r->Arr = calloc(size, sizeof(int));
    r->Size = size;
    r->Bot = 0;
    r->Top = 0;
    r->Count = 0;
    if (r->Arr == NULL)
        return -1;
    else return 0;
}

void insert_on_top(Ring *r, int n)
{
    if (r->Count != 0)
    {
        r->Top = (r->Top + r->Size + 1) % r->Size;
    }
    r->Arr[r->Top] = n;
    r->Count++;
}

void insert_on_bottom(Ring *r, int n)
{
    if (r->Count != 0)
    {
        r->Bot = (r->Bot + r->Size - 1) % r->Size;
    }
    r->Arr[r->Bot] = n;
    r->Count++;
}

int rm_from_top(Ring *r, int *b)
{
    if (r->Count == 0)
    {
        return EMPTY_DECK;
    }
    *b = r->Arr[r->Top];
    r->Arr[r->Top] = 0;
    r->Top = (r->Top + r->Size - 1) % r->Size;
    r->Count--;
    return OK;
}

int rm_from_bottom(Ring *r, int *b)
{
    if (r->Count == 0)
    {
        return EMPTY_DECK;
    }
    *b = r->Arr[r->Bot];
    r->Arr[r->Bot] = 0;
    r->Bot = (r->Bot + r->Size + 1) % r->Size;
    r->Count--;
    return OK;
}