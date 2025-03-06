#include <stdio.h>
#include <stdlib.h>

#define u64 unsigned long long
#define u32 unsigned long

int main(int argc, char const *argv[])
{
    /* Переменные */
    
    char buffer;
    char prev_char = '.';
    short counter = 0;
    int flag;

    /* Открытие файлов */

    FILE * file_input = fopen("input.txt", "r");
    FILE * file_output = fopen("output.txt", "w");

    if (file_input == NULL ||  file_output == NULL)
    {
        perror("File error");
        return 1;
    }

    /* Логика */
    
    do {
        flag = fscanf(file_input, "%c", &buffer);
        if (buffer == '\n') break;
        if (buffer != '.' && prev_char == '.') counter++;
        prev_char = buffer;
    } while (flag != EOF);
    
    fprintf(file_output, "%d", counter);
    
    /* Вывод и закрытие файлов */
    
    fclose(file_input);
    fclose(file_output);
    return 0;
}