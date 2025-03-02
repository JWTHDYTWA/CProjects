#include <stdio.h>
#include <stdlib.h>

#define u64 unsigned long long
#define u32 unsigned long

char buffer[32];
int main(int argc, char const *argv[])
{
    /* Переменные */

    u64 max_vol;
    unsigned long long variants = 0;

    /* Открытие файлов */

    FILE * file_input = fopen("input.txt", "r");
    FILE * file_output = fopen("output.txt", "w");

    if (file_input == NULL ||  file_output == NULL)
    {
        perror("File error");
        return 1;
    }

    /* Логика */
    
    fscanf(file_input, "%lld", &max_vol);

    for (int a = 1; a * a * a <= max_vol; a++)
    {
        for (int b = a; a * b * b <= max_vol; b++)
        {
            int max_c = max_vol / (a * b);
            if (max_c >= b)
            {
                variants += (max_c - b + 1);
            }
        }
    }
    
    /* Вывод и закрытие файлов */
    
    fprintf(file_output, "%lld", variants);
    fclose(file_input);
    fclose(file_output);
    return 0;
}