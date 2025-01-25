#include <stdio.h>
#include <stdlib.h>

#define u64 unsigned long long
#define u32 unsigned int
#define MAXN 100000

FILE * file_input;
FILE * file_output;

typedef struct {
    char exist;
    int value;
} TableEntry;

int init();
void deinit();

int *A;
int *Indices;
TableEntry Table[MAXN];

u32 hash(int key);

int main(int argc, char const *argv[])
{
    /* Переменные */
    
    int N;

    /* Открытие файлов */
    if (init() < 0) return -1;

    /* Логика */
    
    fread(&N, sizeof(int), 1, file_input);

    A = malloc(sizeof(int) * N);
    Indices = malloc(sizeof(int) * N);
    int count = 0;

    fread(A, sizeof(int), N, file_input);

    for (size_t i = 0; i < N; i++)
    {
        int index = hash(A[i]) % MAXN;
        while (1)
        {
            int ex = Table[index].exist;
            if (ex == 0)
            {
                Table[index].exist = 1;
                Table[index].value = A[i];
                Indices[count++] = index;
                break;
            }
            else if (Table[index].value == A[i])
            {
                break;
            }
            else
            {
                index++;
            }
        }
    }
    
    fwrite(&count, sizeof(int), 1, file_output);
    for (size_t i = 0; i < count; i++)
    {
        fwrite(&Table[Indices[i]].value, sizeof(int), 1, file_output);
    }
    

    free(A);
    free(Indices);
    
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

u32 hash(int key)
{
    double A = 0.6180339887498949;
    A *= key;
    A -= (int) A;
    return A * 0xFFFFFFFF;
}
