#include <stdio.h>
#include <stdlib.h>

#define u64 unsigned long long
#define u32 unsigned int

FILE * file_input;
FILE * file_output;

int init();
void deinit();

int gcd(int a, int b);

int main(int argc, char const *argv[])
{
    /* Переменные */
    
    int T;
    int A, B;

    /* Открытие файлов */
    if (init() < 0) return -1;

    /* Логика */

    fscanf(file_input, "%d", &T);
    
    for (size_t i = 0; i < T; i++)
    {
        fscanf(file_input, "%d %d", &A, &B);
        fprintf(file_output, "%d\n", gcd(A, B));
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
    if (b == 0) return a;
    if (a > b) return gcd(a%b, b);
    if (b > a) return gcd(a, b%a);
}