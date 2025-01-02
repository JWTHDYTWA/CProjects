#include <stdio.h>
#include <stdlib.h>

#define u64 unsigned long long
#define u32 unsigned int

FILE * file_input;
FILE * file_output;

int init();
void deinit();

int cX[300];
int cY[300];

int main(int argc, char const *argv[])
{
    /* Переменные */
    
    int N, M;
    // 0: функция, 1: определённая, 2: инъективная, 3: сюрьективная, 4: биективная
    int props[5] = {1,0,0,0,0};
    for (size_t i = 0; i < 300; i++)
    {
        cX[i] = 0;
        cY[i] = 0;
    }
    

    /* Открытие файлов */
    if (init() < 0) return -1;

    /* Логика */
    
    fscanf(file_input, "%d%d", &N, &M);
    for (size_t i = 0; i < M; i++)
    {
        int x, y;
        fscanf(file_input, "%d%d", &x, &y);
        cX[x-1]++;
        cY[y-1]++;
    }

    // Проверка на функцию
    for (size_t i = 0; i < N; i++)
    {
        if (cX[i] > 1)
        {
            props[0] = 0;
            break;
        }
    }
    
    if (props[0])
    {

        // Проверка на определённость
        props[1] = 1;
        for (size_t i = 0; i < N; i++)
        {
            if (cX[i] == 0)
            {
                props[1] = 0;
                break;
            }
        }
        
        // Проверка на инъективность
        props[2] = 1;
        for (size_t i = 0; i < N; i++)
        {
            if (cY[i] > 1)
            {
                props[2] = 0;
                break;
            }
        }
        
        // Проверка на определённость
        props[3] = 1;
        for (size_t i = 0; i < N; i++)
        {
            if (cY[i] == 0)
            {
                props[3] = 0;
                break;
            }
        }

        if (props[2] && props[3]) props[4] = 1;
        
        for (size_t i = 0; i < 5; i++)
        {
            if (props[i])
            {
                fprintf(file_output, "%d ", i + 1);
            }
            
        }

    }
    else
    {
        fprintf(file_output, "0\n");
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