#include <stdio.h>
#include <stdlib.h>

#define u64 unsigned long long
#define u32 unsigned int
#define i64 long long

#define MAX_N 1000001

FILE * file_input;
FILE * file_output;

int init();
void deinit();
int binomial(int k, int n, int m);
int pow_binary(int b, int e, int m);

int factorial[MAX_N];
int fact_inv[MAX_N];

int main(int argc, char const *argv[])
{
    /* Переменные */
    
    int T;
    int K, N;


    /* Открытие файлов */
    if (init() < 0) return -1;

    /* Логика */

    factorial[0] = 1;
    fact_inv[0] = 1;
    for (int i = 1; i < MAX_N; i++)
    {
        factorial[i] = ((i64)factorial[i-1] * i) % 1000000007;
        fact_inv[i] = pow_binary(factorial[i], 1000000005, 1000000007);
    }

    fscanf(file_input, "%d", &T);
    
    for (int i = 0; i < T; i++)
    {
        fscanf(file_input, "%d%d", &N, &K);
        fprintf(file_output, "%d\n", binomial(N,K, 1000000007));
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

    int div = ((i64)fact_inv[k] * fact_inv[n-k]) % m;
    return ((i64)factorial[n] * div) % m;
}

int pow_binary(int b, int e, int m)
{
    b = b % m;
    i64 accum = 1;
    while (e != 0)
    {
        if (e % 2)
        {
            accum = (accum * b) % m;
        }
        b = ((i64)b * b) % m;
        e >>= 1;
    }
    return accum;
}