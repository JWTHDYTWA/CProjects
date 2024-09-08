#include <stdio.h>
#include <math.h>
int main(int argc, char const *argv[])
{
    /* Переменные */
    
    double dbg1 = 0;
    double dbg2 = 0;
    char buff[64];

    /* Открытие файлов */

    FILE * file_input = fopen("input.txt", "r");
    FILE * file_output = fopen("output.txt", "w");

    if (file_input == NULL ||  file_output == NULL)
    {
        perror("File error");
        return 1;
    }

    /* Логика */
    
    // while (1)
    // {
    //     scanf("%lf", &dbg1);
    //     printf("%d\n", (int)ceil(dbg1));
    // }
    
    fgets(buff, 63, file_input);
    printf("%s\n", buff);
    
    
    /* Вывод и закрытие файлов */
    
    // fclose(file_input);
    // fclose(file_output);
    return 0;
}
