#include <stdio.h>
#include <stdlib.h>

char buffer[32];
int main(int argc, char const *argv[])
{
    /* Переменные */
    
    short hour, minute, second;
    int time, delta;

    /* Открытие файлов */

    FILE * file_input = fopen("input.txt", "r");
    FILE * file_output = fopen("output.txt", "w");

    if (file_input == NULL ||  file_output == NULL)
    {
        perror("File error");
        return 1;
    }

    /* Логика */
    fscanf(file_input, "%hd%hd%hd%d", &hour, &minute, &second, &delta);
    time = 3600 * hour + 60 * minute + second + delta;
    hour = (time / 3600 % 60) % 24;
    minute = time / 60 % 60;
    second = time % 60;
    
    /* Вывод и закрытие файлов */
    
    fprintf(file_output, "%d %d %d", hour, minute, second);
    fclose(file_input);
    fclose(file_output);
    return 0;
}
