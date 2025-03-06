#include <stdio.h>
#include <stdlib.h>

#define u64 unsigned long long
#define u32 unsigned long

char buffer[32];
int main(int argc, char const *argv[])
{
    /* Переменные */
    
    int num_n;
    int buffer;
    int pos = 0, neg = 0, zero = 0;

    /* Открытие файлов */

    FILE * file_input = fopen("input.txt", "r");
    FILE * file_output = fopen("output.txt", "w");

    if (file_input == NULL ||  file_output == NULL)
    {
        perror("File error");
        return 1;
    }

    /* Логика */
    
    fscanf(file_input, "%d", &num_n);

    for (int i = 0; i < num_n; i++)
    {
        fscanf(file_input, "%d", &buffer);
        if (buffer > 0) pos++;
        else if(buffer < 0) neg++;
        else zero++;
    }
    
    
    /* Вывод и закрытие файлов */
    
    fprintf(file_output, "%0.15lf %0.15lf %0.15lf", (double)neg/num_n, (double)zero/num_n, (double)pos/num_n);
    fclose(file_input);
    fclose(file_output);
    return 0;
}