#include <stdio.h>
#include <math.h>
#include <time.h>

int binomial(int k, int n)
{
    if (k == 0 || k == n)
        return 1;
    else
        return binomial(k, n-1) + binomial(k-1, n-1);
}

int main(int argc, char const *argv[])
{
    /* Переменные */
    
    int K;
    int N;
    int C;

    int a;
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
    
    printf("Enter k, n: ");
    scanf("%d%d", &K, &N);
    a = clock();
    C = binomial(K, N);
    b = clock();
    printf("%d - Time taken: %ld ms", C, b - a);
    
    /* Вывод и закрытие файлов */
    
    fclose(file_input);
    fclose(file_output);
    return 0;
}
