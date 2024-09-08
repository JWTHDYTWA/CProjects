#include <stdio.h>
#include <stdlib.h>

char buffer[32];
int main(int argc, char const *argv[])
{
    /* Переменные */
    
    int app_n;
    int ref_app_n, ref_entrance, ref_floor, max_floor;

    int est_aof = 0, est_aie;
    int est_entrance, est_floor;

    /* Открытие файлов */

    FILE * file_input = fopen("input.txt", "r");
    FILE * file_output = fopen("output.txt", "w");

    if (file_input == NULL ||  file_output == NULL)
    {
        perror("File error");
        return 1;
    }

    /* Логика */
    
    fgets(buffer, 31, file_input);
    app_n = atoi(buffer);
    printf("Appartment number: %d\n", app_n);
    
    fgets(buffer, 31, file_input);
    sscanf(buffer, "%d %d %d %d", &ref_app_n, &ref_entrance, &ref_floor, &max_floor);
    printf("\tRef app number: %d\n\tRef entrance: %d\n\tRef floor: %d\n\tMax floor: %d\n", ref_app_n, ref_entrance, ref_floor, max_floor);

    for (int i = 1 ; i < 500; i++)
    {
        if ((ref_app_n - (ref_entrance - 1) * max_floor * i - (ref_floor - 1) * i) <= i)
        {
            est_aof = i;
            est_aie = max_floor * i;
            break;
        }
    }

    if (est_aof < 1)
    {
        printf("Couldn't find appartments on floor");
        return -1;
    }
    
    
    est_entrance = app_n / est_aie + 1;
    est_floor = (app_n % est_aie) / est_aof;

    /* Это была самая отбитая задача из набора... */
    
    /* Вывод и закрытие файлов */
    
    fprintf(file_output, "%d %d", est_entrance, est_floor);
    fclose(file_input);
    fclose(file_output);
    return 0;
}
