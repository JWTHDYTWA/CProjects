#include <stdio.h>
#include <stdlib.h>

#define u64 unsigned long long
#define u32 unsigned int

FILE * file_input;
FILE * file_output;

typedef struct LongNum_s {
    int len;
    int arr[500];
} LongNum;

LongNum addLong(LongNum a, LongNum b);
LongNum fib_helper(int n, LongNum a, LongNum b);
LongNum fibonacci(int n);

int init();
void deinit();

int main(int argc, char const *argv[])
{
    /* Переменные */
    
    

    /* Открытие файлов */
    if (init() < 0) return -1;

    /* Логика */
    
    
    
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

LongNum addLong(LongNum a, LongNum b) {
    LongNum result = {0, {0}}; // Инициализация результата
    int carry = 0;             // Перенос
    int i;
    for (i = 0; i < a.len || i < b.len || carry != 0; ++i) {
        if (i >= 500) break;   // Проверка на превышение максимальной длины
        int a_digit = (i < a.len) ? a.arr[i] : 0;
        int b_digit = (i < b.len) ? b.arr[i] : 0;
        int sum = a_digit + b_digit + carry;
        result.arr[i] = sum % 10;
        carry = sum / 10;
        result.len++;
    }
    return result;
}

LongNum fib_helper(int n, LongNum a, LongNum b) {
    if (n == 0) return b;
    LongNum next = addLong(a, b); // Следующее число Фибоначчи
    return fib_helper(n - 1, b, next); // Хвостовой рекурсивный вызов
}

LongNum fibonacci(int n) {
    if (n == 0) {
        LongNum zero = {1, {0}};
        return zero;
    } else if (n == 1)
    {
        LongNum one = {1, {1}};
        return one;
    }
    else {
        LongNum a = {1, {0}};
        LongNum b = {1, {1}};
        return fib_helper(n - 1, a, b);
    }
}