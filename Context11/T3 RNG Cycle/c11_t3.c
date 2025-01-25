#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#define u64 unsigned long long
#define u32 unsigned int
#define MAXN 2000000

typedef struct {
    char exist;
    uint64_t value;
} tableEntry;

FILE * file_input;
FILE * file_output;

int init();
void deinit();
u32 hash(int key);

uint64_t state = 1, M;
uint64_t a, b, c;
uint64_t func ( uint64_t s );

tableEntry table[MAXN];
int Indices[MAXN];
int count = 0;

int main(int argc, char const *argv[])
{
    /* Переменные */

    uint64_t min = UINT64_MAX, max = 0;
    

    /* Открытие файлов */
    if (init() < 0) return -1;

    /* Логика */
    
    fscanf(file_input, "%llu%llu%llu%llu", &M, &a, &b, &c);

    char repeat = 1;
    do {
        int index = hash(state) % MAXN;
        while (1)
        {
            int ex = table[index].exist;
            if (ex == 0)
            {
                table[index].exist = 1;
                table[index].value = state;
                Indices[count++] = index;
                break;
            }
            else if (table[index].value == state)
            {
                int fst;
                for (size_t i = count - 1; i >= 0; i--)
                {
                    if (table[Indices[i]].value == state)
                    {
                        fst = i;
                        break;
                    }
                }
                min = fst;
                max = count;
                repeat = 0;
                break;
            }
            else
            {
                index++;
            }
        }
        state = func(state);
    }
    while (repeat);
    
    fprintf(file_output, "%llu %llu", min, max);
    
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
uint64_t func ( uint64_t s ) {
    return (s*s*a + s*b + c) % M;
}

u32 hash(int key)
{
    double A = 0.6180339887498949;
    A *= key;
    A -= (int) A;
    return A * 0xFFFFFFFF;
}