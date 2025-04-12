#include <stdio.h>
#include <stdlib.h>

#define u64 unsigned long long
#define u32 unsigned int

FILE * file_input;
FILE * file_output;

int init();
void deinit();
int binomial(int k, int n, int m);

int main(int argc, char const *argv[])
{
    /* Переменные */
    
    int M, T;
    int K, N;


    /* Открытие файлов */
    if (init() < 0) return -1;

    /* Логика */

    fscanf(file_input, "%d %d", &M, &T);
    
    for (int i = 0; i < T; i++)
    {
        fscanf(file_input, "%d%d", &N, &K);
        fprintf(file_output, "%d\n", binomial(N,K,M));
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

int binomial(int n, int k, int m)
{
    if (k<0||k>n) return 0;
    if (k==0||k==n) return 1;
    return (binomial(n-1,k,m) + binomial(n-1,k-1,m)) % m;
}