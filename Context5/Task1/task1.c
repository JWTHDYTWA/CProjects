#include <stdio.h>
#include <stdlib.h>

#define u64 unsigned long long
#define u32 unsigned int

FILE * file_input;
FILE * file_output;

int init();
void deinit();

typedef struct DateTime_s {
    int year, month, day;
    int hours, minutes, seconds;
} DateTime;

DateTime minimal(const DateTime * arr, int cnt);
int dateCmp(DateTime a, DateTime b);

int main(int argc, char const *argv[])
{
    /* Переменные */
    
    DateTime *dates;
    int N;

    /* Открытие файлов */
    if (init() < 0) return -1;

    /* Логика */
    
    fscanf(file_input, "%d", &N);
    dates = malloc(sizeof(DateTime)*N);

    for (size_t i = 0; i < N; i++)
    {
        fscanf(file_input, "%d%d%d%d%d%d",
            &dates[i].year, &dates[i].month, &dates[i].day,
            &dates[i].hours, &dates[i].minutes, &dates[i].seconds);
    }

    DateTime out = minimal(dates, N);
    fprintf(file_output, "%d %d %d %d %d %d",
        out.year, out.month, out.day, out.hours, out.minutes, out.seconds);
    
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

DateTime minimal(const DateTime * arr, int cnt)
{
    DateTime m = arr[0];
    for (size_t i = 1; i < cnt; i++)
    {
        if (dateCmp(m, arr[i]) == -1)
        {
            m = arr[i];
        }
    }
    return m;
}

int dateCmp(DateTime a, DateTime b)
{
    int *ca = (int*)(&a), *cb = (int*)(&b);
    for (int i = 0; i < 6; i++, ca++, cb++)
    {
        if (*ca < *cb) return 1;
        else if (*ca > *cb) return -1;
    }
    return 0;
}