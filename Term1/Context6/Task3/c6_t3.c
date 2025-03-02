#include <stdio.h>
#include <stdlib.h>

#define u64 unsigned long long
#define u32 unsigned int

FILE * file_input;
FILE * file_output;

enum op {
    NEW,
    DEL,
    DISPLAY,
    COUNT
};

#define BASE_LENGTH 50000

int init();
void deinit();

int countChar(char* s, char c);

char *String[BASE_LENGTH];
char allocated[BASE_LENGTH] = {0};
int iterator = 0;

int main(int argc, char const *argv[])
{
    /* Переменные */
    
    int N, t, l, id;
    char ch;

    /* Открытие файлов */
    if (init() < 0) return -1;

    /* Логика */
    
    fscanf(file_input, "%d", &N);

    for (int i = 0; i < N; i++)
    {
        fscanf(file_input, "%d", &t);
        switch (t)
        {
        case NEW:
            fscanf(file_input, "%d", &l);
            String[iterator] = malloc(l + 1);
            allocated[iterator] = 1;
            fscanf(file_input, "%s", String[iterator++]);
            break;
        case DEL:
            fscanf(file_input, "%d", &id);
            free(String[id]);
            allocated[id] = 0;
            break;
        case DISPLAY:
            fscanf(file_input, "%d", &id);
            fprintf(file_output, "%s\n", String[id]);
            break;
        case COUNT:
            fscanf(file_input, "%d %c", &id, &ch);
            fprintf(file_output, "%d\n", countChar(String[id], ch));
            break;
        }
    }
    
    for (int i = 0; i < iterator; i++)
    {
        if (allocated[i]) free(String[i]);
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

int countChar(char* s, char c)
{
    int counter = 0;
    while (*s != '\0')
    {
        if (*s == c) counter++;
        s++;
    }
    return counter;
}