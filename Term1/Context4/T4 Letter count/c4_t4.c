#include <stdio.h>
#include <stdlib.h>

#define u64 unsigned long long
#define u32 unsigned int

FILE * file_input;
FILE * file_output;

int init();
void deinit();
int calcLetters(char *iStr, int *oLowerCnt, int *oUpperCnt, int *oDigitsCnt);

int main(int argc, char const *argv[])
{
    /* Переменные */
    
    char line[101];
    int lower, upper, digits, total;

    /* Открытие файлов */
    if (init() < 0) return -1;

    /* Логика */
    
    int line_cnt = 1;
    while (fgets(line, 100, file_input) != NULL)
    {
        total = calcLetters(line, &lower, &upper, &digits);
        fprintf(file_output,
            "Line %d has %d chars: %d are letters (%d lower, %d upper), %d are digits.\n",
            line_cnt++, total, lower+upper, lower, upper, digits);
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

int calcLetters(char *iStr, int *oLowerCnt, int *oUpperCnt, int *oDigitsCnt)
{
    int i = 0;
    int lowerCnt = 0, upperCnt = 0, digitsCnt = 0;
    while (iStr[i] != '\0' && iStr[i] != '\n')
    {
        if (iStr[i] >= 'a' && iStr[i] <= 'z')
            lowerCnt++;
        else if (iStr[i] >= 'A' && iStr[i] <= 'Z')
            upperCnt++;
        else if (iStr[i] >= '0' && iStr[i] <= '9')
            digitsCnt++;
        i++;
    }
    *oLowerCnt = lowerCnt;
    *oUpperCnt = upperCnt;
    *oDigitsCnt = digitsCnt;
    return i;
}