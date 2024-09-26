#include <stdio.h>
#include <stdlib.h>

#define u64 unsigned long long
#define u32 unsigned long

char buffer[32];
int main(int argc, char const *argv[])
{
    /* Переменные */
    
    int rect[2][3];
    char flag = 0;

    /* Открытие файлов */

    FILE * file_input = fopen("input.txt", "r");
    FILE * file_output = fopen("output.txt", "w");

    if (file_input == NULL ||  file_output == NULL)
    {
        perror("File error");
        return 1;
    }

    /* Логика */
    
    fscanf(file_input, "%d %d %d %d %d %d", &rect[0][0], &rect[1][0], &rect[0][1], &rect[1][1], &rect[0][2], &rect[1][2]);
    for (char i = 0; i < 3; i++)
    {
        if (rect[0][i] > rect[1][i]) {
            int tmp = rect[0][i];
            rect[0][i] = rect[1][i];
            rect[1][i] = tmp;
        }
    }

    if (rect[0][0] >= rect[0][1] + rect[0][2] && rect[1][0] >= rect[1][1] + rect[1][2]) {
        flag = 1;
    }
    //@todo
    
    /* Вывод и закрытие файлов */
    
    fclose(file_input);
    fclose(file_output);
    return 0;
}