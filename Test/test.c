#include <stdio.h>
#include <stdlib.h>

#define u64 unsigned long long
#define u32 unsigned int

FILE * file_input;
FILE * file_output;

int init();
void deinit();
u32 gcd(u32 a, u32 b);
int mod(int x, int y);

int main(int argc, char const *argv[])
{
    /* Переменные */
    
    

    /* Открытие файлов */
    if (init() < 0) return -1;

    /* Логика */
    
    printf("%d", gcd(600,8822) );
    
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

u32 gcd(u32 a, u32 b)
{
    if (a == 0)
    {
        return b;
    }
    else
    {
        return gcd(b%a, a);
    }
}

int mod(int x, int y)
{
    
}