#include <stdio.h>

char buffer[33];
int main(int argc, char const *argv[])
{
    /* Переменные */

    int dims[3];
    int p = 0;

    /* Открытие файлов */

    FILE * file_input = fopen("input.txt" , "r");
    FILE * file_output = fopen("output.txt", "w");

    if (file_input == NULL ||  file_output == NULL)
    {
        perror("File error");
        return 1;
    }

    /* Логика */
    
    fscanf(file_input, "%d%d%d", dims, dims+1, dims+2);
    for (size_t i = 0; i < 3; i++)
    {
        if (dims[i] <= 0)
        {
            p = -(i+1);
            break;
        }
    }
    
    if (p == 0)
    {
        p = (dims[0] * dims[1] + dims[1] * dims[2] + dims[2] * dims[0]) * 2;
    }
    
    /* Вывод и закрытие файлов */
    
    fprintf(file_output, "%d", p);
    fclose(file_input);
    fclose(file_output);
    return 0;
}
