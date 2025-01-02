#include <stdio.h>
#include <stdlib.h>

#define u64 unsigned long long
#define u32 unsigned int

FILE * file_input;
FILE * file_output;

typedef struct {
    u32 key;
    char str[8];
} elem;

int init();
void deinit();

int main(int argc, char const *argv[])
{
    /* Переменные */
    
    int N;
    elem *fld;

    /* Открытие файлов */
    if (init() < 0) return -1;

    /* Логика */
    
    fscanf(file_input, "%d", &N);
    fld = malloc(sizeof(elem)*N);

    // Чтение входных данных
    for (int i = 0; i < N; i++)
    {
        fscanf(file_input, "%d%s", &fld[i].key, &fld[i].str);
    }

    // Сортировка
    for (int i = 0; i < N-1; i++)
    {
        char sorted = 1;
        for (int j = 0; j < N-i-1; j++)
        {
            if (fld[j].key > fld[j+1].key)
            {
                elem tmp = fld[j];
                fld[j] = fld[j+1];
                fld[j+1] = tmp;
                sorted = 0;
            }
        }
        if (sorted)
        {
            break;
        }
    }
    
    // Вывод
    for (int i = 0; i < N; i++)
    {
        fprintf(file_output, "%d %s\n", fld[i].key, fld[i].str);
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