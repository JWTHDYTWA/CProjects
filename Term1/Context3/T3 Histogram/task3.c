#include <stdio.h>
#include <stdlib.h>

#define u64 unsigned long long
#define u32 unsigned int

FILE * file_input;
FILE * file_output;

typedef struct pair
{
    int number;
    int count;
} pair;

int init();
void deinit();

int main(int argc, char const *argv[])
{
    /* Переменные */
    
    int N;
    int arrSize = 8;
    pair *gist = malloc(8 * sizeof(pair));

    int unique = 0;
    int tmp;

    /* Открытие файлов */
    if (init() < 0) return -1;

    /* Логика */
    
    fscanf(file_input, "%d", &N);
    // Подсчёт
    for (int i = 0; i < N; i++)
    {
        fscanf(file_input, "%d", &tmp);
        if (unique >= arrSize)
        {
            arrSize *= 2;
            gist = realloc(gist, arrSize * sizeof(pair));
        }
        char new = 1;
        for (int j = 0; j < unique; j++)
        {
            if (gist[j].number == tmp)
            {
                gist[j].count++;
                new = 0;
                break;
            }
        }
        if (new)
        {
            gist[unique].number = tmp;
            gist[unique].count = 1;
            unique++;
        }
    }
    
    // Сортировка
    for (int i = 0; i < unique - 1; i++)
    {
        for (int j = 0; j < unique - i - 1; j++)
        {
            if (gist[j].number > gist[j+1].number)
            {
                pair tmp = gist[j+1];
                gist[j+1] = gist[j];
                gist[j] = tmp;
            }
        }
    }

    // Вывод
    for (int i = 0; i < unique; i++)
    {
        fprintf(file_output, "%d: %d\n", gist[i].number, gist[i].count);
    }
    
    
    /* Вывод и закрытие файлов */
    free(gist);
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
