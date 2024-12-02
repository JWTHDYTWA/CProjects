#include <stdio.h>
#include <math.h>

typedef struct
{
    char a;
    short b;
    int c;
} block;


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
    
    block A = { 127, 32765, 69 };
    block B;
    B = A;
    printf("%d %d %d", B.a, B.b, B.c);;
    
    /* Вывод и закрытие файлов */
    
    fclose(file_input);
    fclose(file_output);
    return 0;
}
