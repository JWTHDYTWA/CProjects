#include <stdio.h>
#include <math.h>
int main(int argc, char const *argv[])
{
    /* Переменные */
    
    unsigned char a = 200, b = 200;

    /* Открытие файлов */

    FILE * file_input = fopen("input.txt", "r");
    FILE * file_output = fopen("output.txt", "w");

    if (file_input == NULL ||  file_output == NULL)
    {
        perror("File error");
        return 1;
    }

    /* Логика */
    
    printf("%d", a * b);
    
    /* Вывод и закрытие файлов */
    
    // fclose(file_input);
    // fclose(file_output);
    return 0;
}
