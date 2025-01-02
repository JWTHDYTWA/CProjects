#include <stdio.h>
// #include <stdlib.h>

#define u64 unsigned long long
#define u32 unsigned int

#define MAXN 10000

FILE * file_input;
FILE * file_output;

typedef union {
    int Int;
    short Sht[2];
    char Byte[4];
} Repr;

enum Endian {
    LITTLE,
    BIG
};

int init();
void deinit();
void read_bin(char size, void *loc, int endianness);
void write_bin(char size, void *loc, int endianness);

int main(int argc, char const *argv[])
{
    /* Переменные */
    
    Repr N;
    int endian = LITTLE;
    int *A;
    int buff, accum = 0;

    /* Открытие файлов */
    if (init() < 0) return -1;

    /* Логика */
    
    fread(&N.Int, 4, 1, file_input);
    if (N.Int >= MAXN || N.Int < 0)
    {
        char tmp = N.Byte[0];
        N.Byte[0] = N.Byte[3];
        N.Byte[3] = tmp;
        tmp = N.Byte[1];
        N.Byte[1] = N.Byte[2];
        N.Byte[2] = tmp;
        endian = BIG;
    }
    
    for (size_t i = 0; i < N.Int; i++)
    {
        read_bin(4, &buff, endian);
        accum += buff;
    }
    

    write_bin(4, &accum, endian);
    
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

void read_bin(char size, void *loc, int endianness)
{
    if (endianness == LITTLE)
    {
        fread(loc, size, 1, file_input);
    }
    else
    {
        char *pointer = (char*)loc + size - 1;
        for (int i = 0; i < size; i++, pointer--)
        {
            fread(pointer, 1, 1, file_input);
        }
    }
}

void write_bin(char size, void *loc, int endianness)
{
    if (endianness == LITTLE)
    {
        fwrite(loc, size, 1, file_output);
    }
    else
    {
        char *pointer = (char*)loc + size - 1;
        for (int i = 0; i < size; i++, pointer--)
        {
            fwrite(pointer, 1, 1, file_output);
        }
    }
}