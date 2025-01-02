#include <stdio.h>
#include <stdlib.h>

#define u64 unsigned long long
#define u32 unsigned int

FILE * file_input;
FILE * file_output;

int init();
void deinit();

int main(int argc, char const *argv[])
{
    /* Переменные */
    
    int A, B;
    double S, D, R;
    long int C;

    /* Открытие файлов */
    if (init() < 0) return -1;

    /* Логика */
    
    fread(&A, 4, 1, file_input);
    fread(&B, 4, 1, file_input);
    S = (long double)A + B;
    D = S / 2;
    R = D - B;
    C = D < 0 && R != 0 ? (int)D - 1 : (int)D;

    fwrite(&C, 4, 1, file_output);
    
    /* Вывод и закрытие файлов */
    deinit();
    return 0;
}

int init()
{
    file_input = fopen("input.txt", "rb");
    file_output = fopen("output.txt", "wb");

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