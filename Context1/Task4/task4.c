#include <stdio.h>

char isPrime(int x);
int main(int argc, char const *argv[])
{
    /* Переменные */

    int number;
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
    
    fscanf(file_input, "%d", &number);
    if (isPrime(number)) fprintf(file_output, "YES");
    else fprintf(file_output, "NO");
    
    /* Закрытие файлов */
    
    fclose(file_input);
    fclose(file_output);
    return 0;
}

char isPrime(int x)
{
    if (x <= 1 || x % 2 == 0) return 0;
    for (int i = 3; i * i <= x; i += 2)
    {
        if (x % i == 0)
            return 0;
    }
    return 1;
}
