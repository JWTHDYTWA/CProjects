#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define u64 unsigned long long
#define u32 unsigned int

FILE * file_input;
FILE * file_output;

typedef struct Label_s
{
    char name[16]; // имя автора (заканчивается нулём)
    int age;       // возраст автора (сколько лет)
} Label;

typedef struct NameStats_s
{
    int cntTotal; // сколько всего подписей
    int cntLong;  // сколько подписей с именами длиннее 10 букв
} NameStats;

typedef struct AgeStats_s
{
    int cntTotal;  // сколько всего подписей
    int cntAdults; // сколько подписей взрослых (хотя бы 18 лет)
    int cntKids;   // сколько подписей детей (меньше 14 лет)
} AgeStats;

int init();
void deinit();

void calcStats(const Label *arr, int cnt, NameStats *oNames, AgeStats *oAges);

int main(int argc, char const *argv[])
{
    /* Переменные */
    
    int N;
    Label *labels;
    NameStats namestats = {0,0};
    AgeStats agestats = {0,0,0};

    /* Открытие файлов */
    if (init() < 0) return -1;

    /* Логика */
    
    fscanf(file_input, "%d", &N);
    labels = malloc(sizeof(Label)*N);

    for (size_t i = 0; i < N; i++)
    {
        fscanf(file_input, "%s %d %*s", &labels[i].name, &labels[i].age);
    }
    
    calcStats(labels, N, &namestats, &agestats);

    fprintf(file_output, "names: total = %d\n", namestats.cntTotal);
    fprintf(file_output, "names: long = %d\n", namestats.cntLong);
    fprintf(file_output, "ages: total = %d\n", agestats.cntTotal);
    fprintf(file_output, "ages: adult = %d\n", agestats.cntAdults);
    fprintf(file_output, "ages: kid = %d", agestats.cntKids);
    
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

void calcStats(const Label *arr, int cnt, NameStats *oNames, AgeStats *oAges)
{
    for (size_t i = 0; i < cnt; i++)
    {
        oNames->cntTotal++;
        if (strlen(arr[i].name) > 10)
        {
            oNames->cntLong++;
        }
        oAges->cntTotal++;
        if (arr[i].age >= 18) oAges->cntAdults++;
        else if (arr[i].age < 14) oAges->cntKids++;
    }
}