#include <stdio.h>
#include <stdlib.h>

#define u64 unsigned long long
#define u32 unsigned int
#define is_delim(c) (c == '.' || c == ',' || c == ';' || c == ':')

FILE * file_input;
FILE * file_output;

int init();
void deinit();
char *split(char *str, char **next, int *cntUpper, int *len);

char buffer[100001];

int main(int argc, char const *argv[])
{
    /* Переменные */
    
    int cntUpper = 0;
    int len = 0;
    char *str = buffer;
    char *next;

    /* Открытие файлов */
    if (init() < 0) return -1;

    /* Логика */
    
    fgets(buffer, 100000, file_input);
    while (str != NULL && *str != '\0')
    {
        str = split(str, &next, &cntUpper, &len);
        fprintf(file_output, "%d/%d %s\n", cntUpper, len, str);
        str = next;
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

char *split(char *str, char **next, int *cntUpper, int *len)
{
    while (is_delim(*str)) str++;
    char *res = str;
    int _len = 0;
    int _upper = 0;
    while (!is_delim(*str) && *str != '\0')
    {
        if (*str >= 'A' && *str <= 'Z') _upper++;
        _len++;
        str++;
    }
    if (*str == '\0') *next = NULL;
    else
    {
        *str = '\0';
        do str++;
        while (is_delim(*str));
        *next = str;
    }
    *len = _len;
    *cntUpper = _upper;
    return res;
}