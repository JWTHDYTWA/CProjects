#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    /* Переменные */

    char buffer[32];

    /* Открытие файлов */

    FILE * file_input = fopen("input.txt" , "r");
    FILE * file_output = fopen("output.txt", "w");

    if (file_input == NULL ||  file_output == NULL)
    {
        perror("File error");
        return 1;
    }

    /* Логика */
    
    fscanf(file_input, "%s", buffer);
    
    if (strncmp(buffer, "Sun", 3) == 0)
    {
        fprintf(file_output, "7");
    }
    else if (strncmp(buffer, "Mon", 3) == 0) {
        fprintf(file_output, "1");
    }
    else if (strncmp(buffer, "Tue", 3) == 0) {
        fprintf(file_output, "2");
    }
    else if (strncmp(buffer, "Wed", 3) == 0) {
        fprintf(file_output, "3");
    }
    else if (strncmp(buffer, "Thu", 3) == 0) {
        fprintf(file_output, "4");
    }
    else if (strncmp(buffer, "Fri", 3) == 0) {
        fprintf(file_output, "5");
    }
    else if (strncmp(buffer, "Sat", 3) == 0) {
        fprintf(file_output, "6");
    }
    
    /* Закрытие файлов */
    
    fclose(file_input);
    fclose(file_output);
    return 0;
}
