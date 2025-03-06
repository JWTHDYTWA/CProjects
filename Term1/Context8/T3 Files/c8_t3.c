#include <stdio.h>
#include <stdlib.h>

#define i64 long long int
#define u64 unsigned long long
#define u32 unsigned int

FILE * file_input;
FILE * file_output;

//#pragma pack (push, 1)
typedef struct {
    char name[21];
    i64 size;
    char is_directory;
    i64 created;
    i64 modified;
    char is_hidden;
} file_signature;
//#pragma pack (pop)

int init();
void deinit();
int sign_comp(const void *A, const void *B);

file_signature *file_list[1024];
int file_count = 0;

int main(int argc, char const *argv[])
{
    /* Переменные */
    
    int N;
    u64 A, B;
    file_signature BUF;

    /* Открытие файлов */
    if (init() < 0) return -1;

    /* Логика */
    
    fread(&N, 4, 1, file_input);
    fread(&A, 8, 1, file_input);
    fread(&B, 8, 1, file_input);

    int fss = sizeof(file_signature);
    
    for (size_t i = 0; i < N; i++)
    {
        fread(&BUF.name, sizeof(BUF.name), 1, file_input);
        fread(&BUF.size, sizeof(BUF.size), 1, file_input);
        fread(&BUF.is_directory, sizeof(BUF.is_directory), 1, file_input);
        fread(&BUF.created, sizeof(BUF.created), 1, file_input);
        fread(&BUF.modified, sizeof(BUF.modified), 1, file_input);
        fread(&BUF.is_hidden, sizeof(BUF.is_hidden), 1, file_input);
        if (!(BUF.is_directory || BUF.is_hidden) && BUF.created >= A && BUF.modified <= B)
        {
            file_list[file_count] = malloc(sizeof(file_signature));
            *file_list[file_count++] = BUF;
        }
    }
    
    qsort(file_list, file_count, sizeof(file_signature*), sign_comp);

    for (size_t i = 0; i < file_count; i++)
    {
        fread(&file_list[i]->name, sizeof(BUF.name), 1, file_input);
        fread(&file_list[i]->size, sizeof(file_list[i]->size), 1, file_input);
        fread(&file_list[i]->is_directory, sizeof(file_list[i]->is_directory), 1, file_input);
        fread(&file_list[i]->created, sizeof(file_list[i]->created), 1, file_input);
        fread(&file_list[i]->modified, sizeof(file_list[i]->modified), 1, file_input);
        fread(&file_list[i]->is_hidden, sizeof(file_list[i]->is_hidden), 1, file_input);
        free(file_list[i]);
    }
    
    /* Вывод и закрытие файлов */
    deinit();
    return 0;
}

int init()
{
    file_input = fopen("input.txt", "rb");
    file_output = fopen("output.txt", "wb");

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

int sign_comp(const void *A, const void *B)
{
    const file_signature *s1 = A, *s2 = B;
    size_t x = sizeof(*s1);
    const char *a = s1->name, *b = s2->name;
    while (*a != '\0' && *b != '\0')
    {
        if (*a == *b)
        {
            a++;
            b++;
        }
        else break;
    }
    if (*a < *b) return -1;
    else if (*a > *b) return 1;
    else return 0;
}