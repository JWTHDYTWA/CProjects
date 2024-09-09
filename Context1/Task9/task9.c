#include <stdio.h>
#include <stdlib.h>

char buffer[32];
int main(int argc, char const *argv[])
{
    /* Переменные */
    
    unsigned long long max_vol;
    unsigned i = 0;
    unsigned long long variants;

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
    while (max_vol > 0)
    {
        variants += max_vol /= 2; // ДОДЕЛАТЬ ДО 10.09
    }
    
    /* Вывод и закрытие файлов */
    
    fprintf(file_output, "%lld", hour, minute, second);
    fclose(file_input);
    fclose(file_output);
    return 0;
}
