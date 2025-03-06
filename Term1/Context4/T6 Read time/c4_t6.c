#include <stdio.h>
#include <stdlib.h>

#define u64 unsigned long long
#define u32 unsigned int

FILE * file_input;
FILE * file_output;

int init();
void deinit();
int readTime(char *iStr, int *oHours , int *oMinutes, int *oSeconds);

int main(int argc, char const *argv[])
{
    /* Переменные */
    
    char buffer[100];
    int H, M, S;

    /* Открытие файлов */
    if (init() < 0) return -1;

    /* Логика */
    
    fgets(buffer, 101, file_input);
    int status = readTime(buffer, &H, &M, &S);
    if (status == 0)
    {
        H = -1;
        M = -1;
        S = -1;
    }
    fprintf(file_output, "%d %d %d %d\n", status, H, M, S);
    fprintf(file_output, "%d %d %d\n", status, H, M);
    fprintf(file_output, "%d %d\n", status, H);
    
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

int readTime(char *iStr, int *oHours , int *oMinutes, int *oSeconds)
{
    int hours, minutes, seconds;
    int digit;
    int scanned = sscanf(iStr, "%d:%d:%d", &hours, &minutes, &seconds);
    if (scanned > 1)
    {
        if (hours < 0 || hours > 23 || minutes < 0 || minutes > 59)
        {
            return 0;
        }
        if (scanned == 3)
        {
            if (seconds < 0 || seconds > 59)
                return 0;
            *oHours = hours;
            if (oMinutes) *oMinutes = minutes;
            if (oMinutes && oSeconds) *oSeconds = seconds;
        }
        else
        {
            *oHours = hours;
            *oMinutes = minutes;
            *oSeconds = 0;
        }
    }
    else return 0;

    return 1;
}