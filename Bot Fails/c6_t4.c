#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define u64 unsigned long long
#define u32 unsigned int
#define FLDSIZE 100000

#define LIST_END -1
#define UNUSED -2

FILE * file_input;
FILE * file_output;

enum op {
    NEW_BEFORE = -1,
    DEL,
    NEW_AFTER
};

typedef struct {
    long int val;
    int prev;
    int next;
} Node;

int init();
void deinit();
int findUnused(Node* f);
void fastFlush(Node *f);
void fullFlush(Node *f);

Node field[FLDSIZE];
int F, L;
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
    // for (int i = 0; i < FLDSIZE; i++)
    // {
    //     field[i].next = UNUSED;
    // }

    fscanf(file_input, "%d", &T);

    for (int i = 0; i < T; i++) // T - Тесты
    {
        selector = 0;
        fscanf(file_input, "%d%d%d%d", &N, &F, &L, &Q);
        for (int j = 0; j < N; j++, selector++) // Заполнение списка из Input | И
        {
            fscanf(file_input, "%ld%d%d", &field[selector].val, &field[selector].next, &field[selector].prev);
        }
        for (int k = 0; k < Q; k++) // Обработка операций
        {
            int op, id, new, temp;
            fscanf(file_input, "%d%d", &op, &id);

            switch (op)
            {
            
            case DEL:
                
                int t_prev = field[id].prev;
                int t_next = field[id].next;

                if (t_prev != LIST_END)
                {
                    field[t_prev].next = t_next;
                }
                else
                {
                    F = t_next;
                }
                
                if (t_next != LIST_END)
                {
                    field[t_next].prev = t_prev;
                }
                else
                {
                    L = t_prev;
                }

                fprintf(file_output, "%ld\n", field[id].val);
                // field[id].next = UNUSED;

                break; // End DEL

            case NEW_AFTER:
            
                new = selector++;

                if (id == LIST_END)
                {
                    id = F;
                    field[F].prev = new;
                    F = new;
                    field[new].prev = LIST_END;
                    field[new].next = id;
                }
                else
                {
                    temp = field[id].next;      // <- (id) <-> [new] <-> (temp)
                    if (temp != LIST_END)
                        field[temp].prev = new;
                    field[id].next = new;
                    field[new].next = temp;
                    field[new].prev = id;
                }

                fscanf(file_input, "%ld", &field[new].val);
                fprintf(file_output, "%d\n", new);

                break; // End NEW_AFTER

            case NEW_BEFORE:
            
                new = selector++;

                if (id == LIST_END)
                {
                    id = L;
                    field[L].next = new;
                    L = new;
                    field[new].next = LIST_END;
                    field[new].prev = id;
                }
                else
                {
                    temp = field[id].prev;
                    if (temp != LIST_END)
                        field[temp].next = new;
                    field[id].prev = new;
                    field[new].prev = temp;
                    field[new].next = id;
                }
                
                fscanf(file_input, "%ld", &field[new].val);
                fprintf(file_output, "%d\n", new);

                break; // End NEW_BEFORE
            
            }
        }

        fprintf(file_output, "===\n");

        for (int cur = F; cur != LIST_END; cur = field[cur].next)
        {
            fprintf(file_output, "%ld\n", field[cur].val);
        }

        fprintf(file_output, "===\n");

        // fastFlush(field);
        // fullFlush(field);
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
