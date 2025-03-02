#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define u64 unsigned long long
#define u32 unsigned int

FILE * file_input;
FILE * file_output;

int init();
void deinit();

void reverse(char *start, int len);

int main(int argc, char const *argv[])
{
    /* Переменные */
    
    int N;
    char buffer[101];
    short L;

    /* Открытие файлов */
    if (init() < 0) return -1;

    /* Логика */
    
    fscanf(file_input, "%d", &N);
    for (int i = 0; i < N; i++)
    {
        fscanf(file_input, "%s", buffer);
        L = strlen(buffer);
        reverse(buffer, L);
        fprintf(file_output, "%s\n", buffer);
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

void reverse(char *start, int len)
{
    for (int i = 0; i < len/2; i++)
    {
        char tmp = start[i];
        start[i] = start[len-i-1];
        start[len-i-1] = tmp;
    }
}