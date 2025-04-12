#include <stdio.h>
#include <stdlib.h>

#define u64 unsigned long long
#define u32 unsigned int
#define i64 long long

FILE * file_input;
FILE * file_output;

int init();
void deinit();
int gcd(int a, int b);
// int gcd_ext(int a, int b, int *x, int *y);
int pow_binary(int b, int e, int m);

int main(int argc, char const *argv[])
{
    /* Переменные */
    
    int T, M, A;
    int x, y;

    /* Открытие файлов */
    if (init() < 0) return -1;

    /* Логика */
    
    fscanf(file_input, "%d %d", &T, &M);
    for (size_t i = 0; i < T; i++)
    {
        fscanf(file_input, "%d", &A);
        if (gcd(A, M) != 1)
        {
            fprintf(file_output, "-1\n");
        }
        else
        {
            // gcd_ext(A, M, &x, &y);
            fprintf(file_output, "%d\n", pow_binary(A, M-2, M));
        }
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

int gcd(int a, int b)
{
    if (a == 0) return b;
    else if (b == 0) return a;
    else if (a > b) return gcd(a%b, b);
    else return gcd(a, b%a);
}

// int gcd_ext(int a, int b, int *x, int *y)
// {
//     if (a == 0)
//     {
//         *x = 0;
//         *y = 1;
//         return b;
//     }
//     int x1, y1;
//     int gcd = gcd_ext(b%a, a, &x1, &y1);
//     *x = y1 - (b/a) * x1;
//     *y = x1;
//     return gcd;
// }

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