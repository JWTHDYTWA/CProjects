#include <stdio.h>
#include <stdlib.h>

#define u64 unsigned long long
#define u32 unsigned int

#define MAX_N 1001

FILE * file_input;
FILE * file_output;

int init();
void deinit();
double binomial(double P[MAX_N][MAX_N], int k, int n);

double Pascal[MAX_N][MAX_N];

int main(int argc, char const *argv[])
{
    /* Переменные */
    
    int Num;
    int K, N;


    /* Открытие файлов */
    if (init() < 0) return -1;

    /* Логика */

    for (int n = 0; n < MAX_N; n++)
    {
        //Pascal[n] = malloc(sizeof(int)*(n+1));
        Pascal[0][0] = 1;
        for (int k = 0; k <= n; k++)
        {
            Pascal[n][k] = binomial(Pascal, k, n);
        }
    }
    
    
    fscanf(file_input, "%d", &Num);
    for (int i = 0; i < Num; i++)
    {
        fscanf(file_input, "%d%d", &N, &K);
        fprintf(file_output, "%.10g\r\n", Pascal[N][K]);
    }
    
    
    /* Вывод и закрытие файлов */
    deinit();
    return 0;
}

int init()
{
    file_input = fopen("input.txt", "r");
    file_output = fopen("output.txt", "w");

    if (file_input == NULL ||  file_output == NULL)
    {
        return -1;
    }
    return 1;
}

void deinit()
{
    fclose(file_input);
    fclose(file_output);
}

double binomial(double P[MAX_N][MAX_N], int k, int n)
{
    if (k==0||k==n)
        return 1;
    else
    {
        return (P[n-1][k]) + (P[n-1][k - 1]);
    }
}