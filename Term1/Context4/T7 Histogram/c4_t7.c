#include <stdio.h>
#include <stdlib.h>

#define u64 unsigned long long
#define u32 unsigned int

#define is_valid(x) (x >= 32 && x <= 126)
#define norm(x) (x - 32)
#define rev(x) (x + 32)

FILE * file_input;
FILE * file_output;

int init();
void deinit();

int registry[94];

int main(int argc, char const *argv[])
{
    /* Переменные */
    
    char buff;

    /* Открытие файлов */
    if (init() < 0) return -1;

    /* Логика */
    
    while ((buff = fgetc(file_input)) != EOF)
    {
        if (is_valid(buff))
        {
            registry[norm(buff)]++;
        }
    }
    
    for (size_t i = 0; i < 94; i++)
    {
        if (registry[i] > 0)
        {
            fprintf(file_output, "%c ", rev(i), registry[i]);
            for (size_t j = 0; j < registry[i]; j++)
            {
                fputc('#', file_output);
            }
            fputc('\n', file_output);
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