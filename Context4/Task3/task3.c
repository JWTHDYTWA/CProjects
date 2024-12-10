#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define u64 unsigned long long
#define u32 unsigned int

FILE * file_input;
FILE * file_output;

int init();
void deinit();

static char* strmem;
char* concat (char *pref , char *suff);

int main(int argc, char const *argv[])
{
    /* Переменные */
    
    char* str;
    char substr[101];
    int N;

    /* Открытие файлов */
    if (init() < 0) return -1;

    /* Логика */
    
    str = malloc(101);
    fscanf(file_input, "%d", &N);

    fscanf(file_input, "%s", str);
    for (int i = 1; i < N; i++)
    {
        fscanf(file_input, "%s", substr);
        concat(str, substr);
        str = strmem;
    }
    fprintf(file_output, "%s", strmem);
    
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

char * concat (char *pref , char *suff)
{
    strmem = pref;
    char *pcur = pref, *scur = suff;
    while (*pcur != '\0')
    {
        pcur++;
    }
    while (*scur != '\0')
    {
        scur++;
    }
    char* newstring = malloc((pcur-pref)+(scur-suff)+1);
    char* newcur = newstring;
    while (*pref != '\0')
    {
        *(newcur++) = *(pref++);
    }
    while (*suff != '\0')
    {
        *(newcur++) = *(suff++);
    }
    *newcur = '\0';
    free(strmem);
    strmem = newstring;
    return newcur;
}