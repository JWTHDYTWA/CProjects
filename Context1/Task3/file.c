#include <stdio.h>
#include <stdlib.h>

char buffer[4];
int main(int argc, char const *argv[])
{
    /* Переменные */
    
    int count;
    int tmp;
    int sum = 0;

    /* Открытие файлов */

    FILE * file_input = fopen("input.txt", "r");
    FILE * file_output = fopen("output.txt", "w");

    if (file_input == NULL ||  file_output == NULL)
    {
        perror("File error");
        return 1;
    }

    /* Логика */
    
    fgets(buffer, 3, file_input);
    count = atoi(buffer);
    
    for (size_t i = 0; i < count; i++)
    {
        if (fscanf(file_input, "%d", &tmp) == EOF)
        {
            printf("Count mismatch!");
            return 1;
        }
        if (tmp % 2 == 0) sum += tmp;
    }

    fprintf(file_output, "%d", sum);
    
    /* Вывод и закрытие файлов */
    
    fclose(file_input);
    fclose(file_output);
    return 0;
}
