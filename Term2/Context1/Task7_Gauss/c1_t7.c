#include <stdio.h>
#include <stdlib.h>

#define u64 unsigned long long
#define u32 unsigned int
#define i64 long long
#define MAX_N 200
#define EPS 1e-8

FILE * file_input;
FILE * file_output;

int init();
void deinit();
int gauss(float m[MAX_N][MAX_N+1], int n);

float Matrix[MAX_N][MAX_N+1];

int main(int argc, char const *argv[])
{
    /* Переменные */
    
    int N;

    /* Открытие файлов */
    if (init() < 0) return -1;

    /* Логика */
    
    fscanf(file_input, "%d", &N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            fscanf(file_input, "%f", &Matrix[i][j]);
        }
    }
    gauss(Matrix, N);
    for (int i = 0; i < N; i++)
    {
        fprintf(file_output, "%f\n", Matrix[i][N]);
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

int gauss(float m[MAX_N][MAX_N+1], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        float coef = m[i][i];
        for (int j = i; j <= n; j++)
        {
            m[i][j] /= coef;
        }
        for (int j = i+1; j < n; j++)
        {
            float coef = m[j][i] / m[i][i];
            for (int k = 0; k <= n; k++)
            {
                m[j][k] -= m[i][k] * coef;
            }
        }
    }
    for (int i = n-1; i >= 0; i--)
    {
        float coef = m[i][i];
        for (int j = i; j <= n; j++)
        {
            m[i][j] /= coef;
        }
        for (int j = i-1; j >= 0; j--)
        {
            float coef = m[j][i] / m[i][i];
            for (int k = 0; k <= n; k++)
            {
                m[j][k] -= m[i][k] * coef;
            }
        }
    }
    return 1;
}