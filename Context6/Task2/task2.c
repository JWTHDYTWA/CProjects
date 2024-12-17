#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define u64 unsigned long long
#define u32 unsigned int
#define FLDSIZE 100000

#define ADD 0
#define DEL 1

FILE * file_input;
FILE * file_output;

typedef struct {
    char str[8];
    char used;
    int next;
} Node;

int init();
void deinit();
int findUnused(Node* f);

Node field[FLDSIZE];

int main(int argc, char const *argv[])
{
    /* Переменные */
    
    memset(field, 0, sizeof(field));
    int T, N, F, Q;
    int M; // Посл. элем.

    /* Открытие файлов */
    if (init() < 0) return -1;

    /* Логика */
    
    fscanf(file_input, "%d", &T);

    for (int i = 0; i < T; i++) // T - Тесты
    {
        fscanf(file_input, "%d%d%d", &N, &F, &Q);
        for (int j = 0; j < N; j++) // Заполнение списка из Input
        {
            fscanf(file_input, "%s%d", &field[j].str, &field[j].next);
            field[j].used = 1;
            if (&field[j].next == -1) M = j;
        }
        for (int i = 0; i < Q; i++) // Обработка операций
        {
            char op, index;
            fscanf(file_input, "%d%d", &op, &index);

            int pred = F, cur;

            if (index == F)
            {
                cur = field[F].next;
            }
            else
            {
                while (field[pred].next != index && field[pred].next != -1)
                {
                    pred = field[pred].next;
                }
                cur = field[pred].next;
            }

            if (op) // Удаление
            {
                if (index == F)
                {
                    F = cur;
                }
                else if (index == -1)
                {
                    field[pred]
                }
                else
                {
                    field[pred].next = field[cur].next;
                }
            }
            else // Вставка
            {
                if (index == F)
                {
                    F = cur;
                }
                else if (index == -1)
                {

                }
                fscanf(file_input, "%s", field[index].str);
                field[pred].next = 
            }
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

int findUnused(Node* f)
{
    for (int i = 0; i < FLDSIZE; i++)
    {
        if (!f[i].used)
        {
            return i;
        }
        
    }
    return -1
}