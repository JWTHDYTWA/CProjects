#include <stdio.h>
#include <stdlib.h>

#define u64 unsigned long long
#define u32 unsigned int

FILE * file_input;
FILE * file_output;

int init();
void deinit();
int readNumeral(char c);
void writeNumeral(int x, char *c);
int fromString(char *str, int radix);
void toString(char *str, int num, int radix);

int main(int argc, char const *argv[])
{
    /* Переменные */
    
    int p, q;
    char N[32];

    /* Открытие файлов */
    if (init() < 0) return -1;

    /* Логика */
    
    fscanf(file_input, "%d%d%s", &p, &q, N);
    int num = fromString(N, p);
    toString(N, num, q);
    fprintf(file_output, "%s\n", N);
    
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

int readNumeral(char c)
{
    if (c >= '0' && c <= '9')
    {
        return c - '0';
    }
    else if (c >= 'a' && c <= 'z')
    {
        return c - 'a' + 10;
    }
    else return -1;
}

void writeNumeral(int x, char *c)
{
    if (x >= 0 && x <= 9)
    {
        *c = x + '0';
    }
    else if (x >= 10 && x <= 36)
    {
        *c = x + 'a' - 10;
    }
}

int fromString(char *str, int radix)
{
    int acc = 0;
    while (*str != '\0')
    {
        acc *= radix;
        acc += readNumeral(*str); // Предполагается, что символы в строке не выходят за пределы диапазона
        str++;
    }
    return acc;
}

void toString(char *str, int num, int radix)
{
    int i = 0;
    do
    {
        int rem = num % radix;
        writeNumeral(rem, &str[i++]);
        num /= radix;
    } while (num != 0);
    str[i] = '\0';

    for (int j = 0, k = i - 1; j < k; j++, k--)
    {
        char temp = str[j];
        str[j] = str[k];
        str[k] = temp;
    }
}