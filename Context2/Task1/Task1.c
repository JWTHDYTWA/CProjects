#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    /* Переменные */
    char* sieve;
    int number = 0;

    /* Открытие файлов */
    FILE * file_input = fopen("input.txt" , "r");
    FILE * file_output = fopen("output.txt", "w");

    if (file_input == NULL ||  file_output == NULL)
    {
        perror("File error");
        return 1;
    }

    /* Логика */
    fscanf(file_input, "%d", &number);
    sieve = calloc((number / 8) + 1, 1);

    for (int i = 2; i * i <= number; i++)
    {
        if (!(sieve[i/8] & (1 << (i%8))))
        {
            for (int j = i * i; j <= number; j += i) {
                sieve[j/8] |= (1 << (j%8));
            }
        }
    }
    
    for (int i = 2; i <= number; i++)
    {
        if (!(sieve[i/8] & (1 << (i%8))))
        {
            fprintf(file_output, "%d\n", i);
        }
    }
    
    /* Закрытие файлов */
    fclose(file_input);
    fclose(file_output);
    free(sieve);
    return 0;
}
