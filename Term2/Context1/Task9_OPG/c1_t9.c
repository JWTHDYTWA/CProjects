#include <stdio.h>
#include <stdlib.h>

#define u64 unsigned long long
#define u32 unsigned int
#define i64 long long
#define MFS 100

FILE * file_input;
FILE * file_output;

int init();
void deinit();
void turn(int FS, int x, int y);
void print_field(int FS);

char field[MFS][MFS];

int main(int argc, char const *argv[])
{
    /* Переменные */
    
    int FS;
    int X, Y;

    /* Открытие файлов */
    // if (init() < 0) return -1;

    /* Логика */
    
    scanf("%d", &FS);
    for (size_t i = 0; i < FS; i++)
    {
        for (size_t j = 0; j < FS; j++)
        {
            field[i][j] = '.';
        }
        field[i][FS] = '\0';
    }
    
    print_field(FS);
    while (1)
    {
        scanf("%d%d", &X, &Y);
        turn(FS, X-1, Y-1);
        print_field(FS);
    }
    
    
    /* Вывод и закрытие файлов */
    // deinit();
    return 0;
}

int init()
{
    file_input = fopen("input.txt", "r");
    file_output = fopen("output.txt", "w");

    if (file_input == NULL ||  file_output == NULL)
    {
        fprintf(stderr, "Error opening files\n");
        return -1;
    }
    return 1;
}

void deinit()
{
    fclose(file_input);
    fclose(file_output);
}

void turn(int FS, int x, int y)
{
    if (x > 0)
    {
        if (field[y][x-1] == '.')
        {
            field[y][x-1] = '*';
        }
        else
        {
            field[y][x-1] = '.';
        }
    }
    if (x < FS-1)
    {
        if (field[y][x+1] == '.')
        {
            field[y][x+1] = '*';
        }
        else
        {
            field[y][x+1] = '.';
        }
    }
    if (y > 0)
    {
        if (field[y-1][x] == '.')
        {
            field[y-1][x] = '*';
        }
        else
        {
            field[y-1][x] = '.';
        }
    }
    if (y < FS-1)
    {
        if (field[y+1][x] == '.')
        {
            field[y+1][x] = '*';
        }
        else
        {
            field[y+1][x] = '.';
        }
    }
    if (field[y][x] == '.')
    {
        field[y][x] = '*';
    }
    else
    {
        field[y][x] = '.';
    }
}

void print_field(int FS)
{
    printf("\n");
    for (size_t i = 0; i < FS; i++)
    {
        printf("%s\n", field[i]);
    }
}