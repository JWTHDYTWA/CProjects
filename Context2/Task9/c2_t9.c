#include <stdio.h>
#include <stdlib.h>

#define u64 unsigned long long
#define u32 unsigned int
#define true 1
#define false 0

#define put(c) fprintf(file_output, "%c", c)

FILE * file_input;
FILE * file_output;

int init();
void deinit();

int main(int argc, char const *argv[])
{
    /* Переменные */
    
    char character;
    char ln_comment = false;
    char block_comment = 0;

    /* Открытие файлов */
    if (init() < 0) return -1;

    /* Логика */
    
    while (true)
    {
        if (fscanf(file_input, "%c", &character) != 1) break;

        if (!(ln_comment || block_comment))
        {
            if (character == '/')
            {
                if (fscanf(file_input, "%c", &character) != 1)
                {
                    put('/');
                    break;
                }
                if (character == '*')
                {
                    block_comment = true;
                }
                else if (character == '/')
                {
                    ln_comment = true;
                }
                else
                {
                    fprintf(file_output, "/%c", character);
                }
            }
            else put(character);
        }

        else
        {
            if (character == '\n')
            {
                ln_comment = false;
                put('\n');
            }
            if (block_comment && character == '*')
            {
                if (fscanf(file_input, "%c", &character) != 1) break;
                if (character == '/')
                {
                    block_comment = false;
                }
                else if (character == '\n') put('\n');
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
