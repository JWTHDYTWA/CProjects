#include <stdio.h>
#include <stdlib.h>

#define u64 unsigned long long
#define u32 unsigned int

FILE * file_input;
FILE * file_output;

int init();
void deinit();

void printTime(int h, int m, int s);

int main(int argc, char const *argv[])
{
    /* Переменные */
    
    int num;

    /* Открытие файлов */
    if (init() < 0) return -1;

    /* Логика */
    
    fscanf(file_input, "%d", &num);
    for (int i = 0; i < num; i++)
    {
        int H, M, S;
        fscanf(file_input, "%d %d %d", &H, &M, &S);
        printTime(H,M,S);
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

void printTime(int h, int m, int s)
{
    fprintf(file_output, "%02d:%02d:%02d\n", h, m, s);
}
