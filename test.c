#include <stdio.h>
#include <math.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    /* Переменные */
    
    int K;
    int N;
    int C;

    int lastTs;
    int b;

    /* Открытие файлов */

    FILE * file_input = fopen("input.txt", "r");
    FILE * file_output = fopen("output.txt", "w");

    if (file_input == NULL ||  file_output == NULL)
    {
        perror("File error");
        return 1;
    }

    /* Логика */
    
    for (int i = 0; i < 60; i++)
    {
        lastTs = clock();
        int cnt = 0;
        while (clock() - lastTs < 1000)
        {
            cnt++;
        }
        printf("%d second: %d cycles\n", i+1, cnt);
    }
    
    /* Вывод и закрытие файлов */
    
    fclose(file_input);
    fclose(file_output);
    return 0;
}
