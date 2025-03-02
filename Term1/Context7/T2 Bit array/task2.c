#include <stdio.h>

#define u64 unsigned long long
#define u32 unsigned int

#define UINT_MAX 4294967295

typedef unsigned int bitword;

#define blen (sizeof(bitword)*8)

FILE * file_input;
FILE * file_output;

int init();
void deinit();

void bitsetZero ( bitword * arr , int num );
int bitsetGet ( const bitword * arr , int idx );
void bitsetSet ( bitword * arr , int idx , int newval );
int bitsetAny ( const bitword * arr , int left , int right );

// bitword *field = NULL;
bitword field[1000000];
int fieldlen = 0;

int main(int argc, char const *argv[])
{
    /* Переменные */
    
    int N;

    /* Открытие файлов */
    if (init() < 0) return -1;

    /* Логика */
    
    fscanf(file_input, "%d", &N);
    for (int i = 0; i < N; i++)
    {
        int op, a1, a2;
        fscanf(file_input, "%d%d", &op, &a1);
        switch (op)
        {
        case 0:
            // if (a1 > fieldlen)
            // {
            //     field = realloc(field, (a1 - 1) / sizeof(bitword) + 1);
            //     fieldlen = a1;
            // }
            bitsetZero(field, a1);
            break;
        case 1:
            fprintf(file_output, "%d\n", bitsetGet(field, a1));
            break;
        case 2:
            fscanf(file_input, "%d", &a2);
            bitsetSet(field, a1, a2);
            break;
        case 3:
            fscanf(file_input, "%d", &a2);
            fprintf(file_output, "%s\n", bitsetAny(field, a1, a2) ? "some" : "none");
            break;
        default:
            break;
        }
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

void bitsetZero ( bitword * arr , int num )
{
    for (int i = 0; i < (num - 1) / blen; i++)
    {
        arr[i] = 0;
    }
    arr[(num - 1) / blen] &= ~(UINT_MAX >> (blen - num % blen));
}

int bitsetGet ( const bitword * arr , int idx )
{
    return (arr[idx / blen] & (1 << idx % blen)) ? 1 : 0;
}

void bitsetSet ( bitword * arr , int idx , int newval )
{
    if (newval)
    {
        arr[idx / blen] |= (1 << idx % blen);
    }
    else
    {
        arr[idx / blen] &= ~(1 << idx % blen);
    }
}

int bitsetAny ( const bitword * arr , int left , int right )
{
    right--;
    int wordl = left / blen;
    int wordr = right / blen;
    
    if (wordl == wordr)
    {
        return arr[wordl] & (UINT_MAX >> right - left) << left ? 1 : 0;
    }
    else
    {
        if (arr[wordl] & UINT_MAX << left)
        {
            return 1;
        }
        for (int i = wordl + 1; i < wordr; i++)
        {
            if (arr[i]) return 1;
        }
        u32 mask = UINT_MAX >> (blen - right % blen);
        if (arr[wordr] & UINT_MAX >> (blen - right % blen - 1))
        {
            return 1;
        }
        
        return 0;
    }
}