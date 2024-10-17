#include <stdio.h>
#include <math.h>
int main(int argc, char const *argv[])
{
    /* Переменные */
    
    char a;
    int tmp;

    /* Открытие файлов */

    FILE * file_input = fopen("input.txt", "r");
    FILE * file_output = fopen("output.txt", "w");

    if (file_input == NULL ||  file_output == NULL)
    {
        perror("File error");
        return 1;
    }

    /* Логика */
    
    do {
        tmp = fscanf(file_input, "%c", &a);
        fprintf(file_output, "%d:\"%c\" ", tmp, a);
    } while (tmp != EOF);
    
    /* Вывод и закрытие файлов */
    
    fclose(file_input);
    fclose(file_output);
    return 0;
}
