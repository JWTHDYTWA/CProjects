#include <stdio.h>

int main(int argc, char const *argv[])
{
    /* Переменные */

    int count;
    int sum = 0;

    /* Открытие файлов */

    FILE * file_input = fopen("input.txt" , "r");
    FILE * file_output = fopen("output.txt", "w");

    if (file_input == NULL ||  file_output == NULL)
    {
        perror("File error");
        return 1;
    }

    /* Логика */
    
    fscanf(file_input, "%d", &count);
    for (size_t i = 1; i <= count; i++)
    {
        sum += i;
    }
    
    /* Вывод и закрытие файлов */
    
    fprintf(file_output, "%d", sum);
    fclose(file_input);
    fclose(file_output);
    return 0;
}
