#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define u64 unsigned long long
#define u32 unsigned int
#define FLDSIZE 100000

#define ADD 0
#define DEL 1

#define LIST_END -1
#define UNUSED -2

FILE * file_input;
FILE * file_output;

typedef struct {
    char str[8];
    int next;
} Node;

int init();
void deinit();
int findUnused(Node* f);
void fastFlush(Node *f);

Node field[FLDSIZE];
int F;

int main(int argc, char const *argv[])
{
    /* Переменные */
    
    memset(field, 0, sizeof(field));
    int T, N, Q;
    int M; // Посл. элем.

    /* Открытие файлов */
    if (init() < 0) return -1;

    /* Логика */
    
    for (int i = 0; i < FLDSIZE; i++)
    {
        field[i].next = UNUSED;
    }

    fscanf(file_input, "%d", &T);

    for (int i = 0; i < T; i++) // T - Тесты
    {
        fscanf(file_input, "%d%d%d", &N, &F, &Q);
        for (int j = 0; j < N; j++) // Заполнение списка из Input | И
        {
            fscanf(file_input, "%s%d", &field[j].str, &field[j].next);
            if (&field[j].next == -1) M = j;
        }
        for (int i = 0; i < Q; i++) // Обработка операций
        {
            char op, id;
            fscanf(file_input, "%d%d", &op, &id);

            if (op) // Удаление
            {
                if (id == -1)
                {
                    int old = F;
                    F = field[F].next;
                    field[old].next = UNUSED;
                }
                else
                {
                    int next = field[id].next;
                    field[id].next = field[next].next;
                    field[next].next = UNUSED;
                }
            }
            else // Вставка
            {
                if (id == -1)
                {
                    int sec = F;
                    F = findUnused(field);
                    field[F].next = sec;
                    fscanf(file_input, "%s", field[F].str);
                }
                else
                {
                    int new = field[id].next = findUnused(field);
                    field[new].next = -1;
                    fscanf(file_input, "%s", field[new].str);
                }
            }
        }
        fastFlush(field);
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

int findUnused(Node* f)
{
    for (int i = 0; i < FLDSIZE; i++)
    {
        if (f[i].next == UNUSED)
        {
            return i;
        }
    }
    return -1;
}

void fastFlush(Node *f)
{
    for (int i = 0; i < FLDSIZE && f[i].next != UNUSED; i++)
    {
        f[i].next = UNUSED;
    }
}
