#include <stdio.h>

int main(int argc, char const *argv[])
{
    /* Переменные */

    int A, B;
    double divided;
    int floored, ceiled, rounded, rem;

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
    divided = (double)A / B;
    floored = divided < 0 ? (int)divided - 1 : (int)divided;
    ceiled = divided > 0 ? (int)divided : (int)divided + 1;
    if (divided - A/B < 0)
    {
        rounded = divided - A/B < -0.5 ? floored : ceiled;
    }
    else
    {
        rounded = divided - A/B > 0.5 ? ceiled : floored;
    }
    
    rem = A - floored * B;
    fprintf(file_output, "%d %d %d %d",
        floored,
        ceiled,
        rounded,
        A - floored * B);
    
    /* Закрытие файлов */
    
    fclose(file_input);
    fclose(file_output);
    return 0;
}
