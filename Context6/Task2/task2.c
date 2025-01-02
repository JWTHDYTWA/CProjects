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
void fullFlush(Node *f);

Node field[FLDSIZE];
int F;
int selector = 0;

int main(int argc, char const *argv[])
{
    /* Переменные */
    
    memset(field, 0, sizeof(field));
    int T, N, Q;
    int M; // Посл. элем.

    /* Открытие файлов */
    if (init() < 0) return -1;

    /* Логика */
    
    // Предварительное освобождение списка
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
            fscanf(file_input, "%s%d", field[j].str, &field[j].next);
        }
        for (int k = 0; k < Q; k++) // Обработка операций
        {
            int op, id;
            fscanf(file_input, "%d%d", &op, &id);

            if (op) // Удаление
            {
                if (id == LIST_END)
                {
                    int old = F;
                    F = field[F].next;
                    // field[old].next = UNUSED;
                    fprintf(file_output, "%s\n", field[old].str);
                }
                else
                {
                    int next = field[id].next;
                    field[id].next = field[next].next;
                    // field[next].next = UNUSED;
                    fprintf(file_output, "%s\n", field[next].str);
                }
            }
            else // Вставка
            {
                if (id == LIST_END)
                {
                    int sec = F;
                    F = findUnused(field);
                    field[F].next = sec;
                    fscanf(file_input, "%s", field[F].str);
                    fprintf(file_output, "%d\n", F);
                }
                else
                {
                    int foll = field[id].next;
                    int new = field[id].next = findUnused(field);
                    field[new].next = foll;
                    fscanf(file_input, "%s", field[new].str);
                    fprintf(file_output, "%d\n", new);
                }
            }
        }

        fprintf(file_output, "===\n");

        for (int cur = F; cur != LIST_END; cur = field[cur].next)
        {
            fprintf(file_output, "%s\n", field[cur].str);
        }

        fprintf(file_output, "===\n");

        // fastFlush(field);
        fullFlush(field);
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
    // for (int i = 0; i < FLDSIZE; i++)
    // {
    //     if (f[i].next == UNUSED)
    //     {
    //         return i;
    //     }
    // }
    // return -1;

    while (f[selector].next != UNUSED)
    {
        selector = (selector + 1) % FLDSIZE;
    }
    return selector;
}

void fastFlush(Node *f)
{
    for (int i = 0; i < FLDSIZE && f[i].next != UNUSED; i++)
    {
        f[i].next = UNUSED;
    }
}

void fullFlush(Node *f)
{
    for (int i = 0; i < FLDSIZE; i++)
    {
        f[i].next = UNUSED;
    }
}
