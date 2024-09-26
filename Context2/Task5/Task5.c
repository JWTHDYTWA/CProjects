#include <stdio.h>
#include <stdlib.h>

#define u64 unsigned long long
#define u32 unsigned long

int main(int argc, char const *argv[])
{
    /* Переменные */
    
    

    /* Открытие файлов */

    FILE * file_input = fopen("input.txt", "r");
    FILE * file_output = fopen("output.txt", "w");

    if (file_input == NULL ||  file_output == NULL)
    {
        perror("File error");
        return 1;
    }

    /* Логика */
    
    
    
    /* Вывод и закрытие файлов */
    
    fclose(file_input);
    fclose(file_output);
    return 0;
}