#include <stdio.h>
#include <stdlib.h>

#define u64 unsigned long long
#define u32 unsigned long

FILE * file_input;
FILE * file_output;

int init();
void deinit();

int main(int argc, char const *argv[])
{
    /* Переменные */
    
    int amount;
    char buffer;
    char byte;

    /* Открытие файлов */
    if (init()) return 1;

    /* Логика */
    
    fscanf(file_input, "%d\n", &amount);
    // printf("Amount of bits: %d\n", amount);

    for (int i = 0; i < amount; i++)
    {
        // printf("### Iteration: %d\n", i);
        if (i % 8 == 0)
        {
            // printf("New byte\n");
            byte = 0;
        }
        fscanf(file_input, "%c", &buffer);

        switch (buffer)
        {
        case '1':
            byte |= 1 << (i % 8);
            // printf("Modifying byte: %hhu\n", byte);
            break;
        case '0':
            // Не нужно ничего делать, потому что байт изначально зануляется
            break;
        default:
            printf("Invalid character: %c (%hhu)\n", buffer, buffer);
            deinit();
            return -1;
        }

        if (i % 8 == 7)
        {
            // if (i == amount - 1) printf("Printing last byte\n");
            // else printf("Printing byte\n");

            fprintf(file_output, "%hhu", byte);
            if (i != amount - 1)
            {
                fprintf(file_output, " ");
            }
        }
        else if (i == amount - 1)
        {
            // printf("Printing last byte\n");
            fprintf(file_output, "%hhu", byte);
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
        perror("File error");
        return 1;
    }
    return 0;
}

void deinit()
{
    fclose(file_input);
    fclose(file_output);
}