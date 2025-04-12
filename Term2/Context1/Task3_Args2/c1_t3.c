#include <stdio.h>
#include <stdlib.h>

#define false 0
#define true 1
#define u64 unsigned long long
#define u32 unsigned int

FILE * file_input;
FILE * file_output;

int init();
void deinit();

int main(int argc, char const *argv[])
{
    /* Переменные */
    
    char p;

    /* Открытие файлов */
    if (init() < 0) return -1;

    /* Логика */
    
    int brackets = false;
    int word = false;
    
    while (1)
    {
        p = fgetc(file_input);
        if (p == EOF)
        {
            if (word) fprintf(file_output, "]\n");
            break;
        }
        if (!brackets)
        {
            if (p == '"')
            {
                fprintf(file_output, "[");
                brackets = true;
            }
            else
            {
                if (!word)
                {
                    if (p != ' ')
                    {
                        word = true;
                        fprintf(file_output, "[%c", p);
                    }
                }
                else
                {
                    if (p == ' ')
                    {
                        word = false;
                        fprintf(file_output, "]\n");
                    }
                    else
                    {
                        fprintf(file_output, "%c", p);
                    }
                }
            }
        }
        else
        {
            if (p == '"')
            {
                fprintf(file_output, "]\n");
                brackets = false;
            }
            else
            {
                fprintf(file_output, "%c", p);
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