#include <stdio.h>
#include <stdlib.h>

#define u64 unsigned long long
#define u32 unsigned int
#define WIDTH 1000000
#define BUF_LEN 8

FILE * file_input;
FILE * file_output;

int init();
void deinit();
char * newElemById(int id);

// Можно было бы забабахать структурой, но по заданию массив :P
char *Array[WIDTH] = {NULL};
int sizes[WIDTH] = {0};
int elems[WIDTH] = {0};

int main(int argc, char const *argv[])
{
    /* Переменные */
    
    int N;
    char buffer[8];
    int index;

    /* Открытие файлов */
    if (init() < 0) return -1;

    /* Логика */
    
    fscanf(file_input, "%d", &N);

    for (size_t i = 0; i < N; i++)
    {
        fscanf(file_input, "%d", &index);
        fscanf(file_input, "%s", newElemById(index));
    }
    
    for (size_t i = 0; i < WIDTH; i++)
    {
        char* str = Array[i];
        for (size_t j = 0; j < elems[i]; j++)
        {
            fprintf(file_output, "%d %s\n", i, &str[BUF_LEN * j]);
        }
        free(Array[i]);
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

char * newElemById(int id)
{
    if (sizes[id] == 0)
    {
        sizes[id] = 4;
        Array[id] = realloc(Array[id], BUF_LEN * 4);
    }
    else if (elems[id] == sizes[id])
    {
        sizes[id] *= 2;
        Array[id] = realloc(Array[id], BUF_LEN * sizes[id]);
    }
    char *strings = Array[id];
    return &strings[BUF_LEN * (elems[id]++)];
}
