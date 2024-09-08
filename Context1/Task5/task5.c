#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    /* Переменные */

    int A;
    int B;
    int floored;

    /* Открытие файлов */

    FILE * file_input = fopen("input.txt" , "r");
    FILE * file_output = fopen("output.txt", "w");

    if (file_input == NULL ||  file_output == NULL)
    {
        perror("File error");
        return 1;
    }

    /* Логика */
    
    fscanf(file_input, "%d%d", &A, &B);
    floored = (int)floor((double)A / B);
    fprintf(file_output, "%d %d %d %d",
        floored,
        (int)ceil((double)A / B),
        (int)round((double)A / B),
        A - floored * B);
    
    /* Закрытие файлов */
    
    fclose(file_input);
    fclose(file_output);
    return 0;
}
