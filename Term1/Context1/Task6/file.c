#include <stdio.h>

char buffer[8];
int main(int argc, char const *argv[])
{
    /* Переменные */
    
    int count;
    int tmp;

    short min = 32767;
    char i_min;
    short max = -32768;
    char i_max;

    /* Открытие файлов */

    FILE * file_input = fopen("input.txt", "r");
    FILE * file_output = fopen("output.txt", "w");

    if (file_input == NULL ||  file_output == NULL)
    {
        perror("File error");
        return 1;
    }

    /* Логика */
    
    fgets(buffer, 7, file_input);
    count = atoi(buffer);
    
    for (char i = 1; i <= count; i++)
    {
        if (fscanf(file_input, "%d", &tmp) == EOF)
        {
            printf("Count mismatch!");
            return 1;
        }
        if (tmp < min)
        {
            min = tmp;
            i_min = i;
        }
        if (tmp > max)
        {
            max = tmp;
            i_max = i;
        }
    }
    
    /* Вывод и закрытие файлов */
    
    fprintf(file_output, "%d %d %d %d", min, i_min, max, i_max);
    fclose(file_input);
    fclose(file_output);
    return 0;
}
