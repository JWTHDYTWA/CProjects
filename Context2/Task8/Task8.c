#include <stdio.h>
#include <stdlib.h>

#define u64 unsigned long long
#define u32 unsigned long

FILE * file_input;
FILE * file_output;

int init();
void deinit();

int toDays(int,int,int);
int leapCount(int);

int main(int argc, char const *argv[])
{
    /* Переменные */
    int D, M, Y, K;
    int total_days;

    /* Открытие файлов */
    if (init() < 0) return -1;

    /* Логика */
    fscanf(file_input, "%d %d %d %d", D, M, Y, K);
    total_days = toDays(D, M, Y);
    total_days += K;
    Y = total_days / (365 *); // @todo
    
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

int toDays(int day, int month, int year)
{
    int days = 0;
    days += year * 365 + leapCount(year - 1);
    days += (month == 1) ? 31 :
            (month == 2) ? 59 :
            (month > 7) ? (212 + (month-7) * 61 / 2 + (month-7) % 2) :
            (59 + month * 61 / 2 + month % 2);
    days += day;
    return days;
}

int toYears(int days)
{
    // Todo
    
}

int leapCount(int year)
{
    int days = 0;
    days += year / 400;
    days += year / 4 - year / 100;
    return days;
}