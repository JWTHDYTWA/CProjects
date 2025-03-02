#include <stdio.h>
#include <stdlib.h>

#define u64 unsigned long long
#define u32 unsigned int

FILE * file_input;
FILE * file_output;

typedef struct {
    char Name[31];
    int BirthYear;
    char Country[11];
} ActorBio;

typedef struct {
    char ActorName[31];
    char MovieName[21];
} ActorInMovie;


int init();
void deinit();
int readBrackets(char *str);
int strcmp(char *a, char *b);

int main(int argc, char const *argv[])
{
    /* Переменные */
    
    int N, M;
    ActorBio *A;
    ActorInMovie *B;

    /* Открытие файлов */
    if (init() < 0) return -1;

    /* Логика */
    
    fscanf(file_input, "%d", &N);
    A = calloc(N, sizeof(ActorBio));
    for (size_t i = 0; i < N; i++)
    {
        readBrackets(A[i].Name);
        fscanf(file_input, "%d ", &A[i].BirthYear);
        readBrackets(A[i].Country);
    }
    
    fscanf(file_input, "%d", &M);
    B = calloc(M, sizeof(ActorInMovie));
    for (size_t i = 0; i < M; i++)
    {
        readBrackets(B[i].ActorName);
        readBrackets(B[i].MovieName);
    }
    
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < M; j++)
        {
            if (!strcmp(A[i].Name, B[j].ActorName))
            {
                fprintf(file_output, "\"%s\" %d \"%s\" \"%s\" \"%s\"\n",
                    A[i].Name, A[i].BirthYear, A[i].Country,
                    B[j].ActorName, B[j].MovieName);
            }
            
        }
    }
    
    
    /* Вывод и закрытие файлов */
    free(A);
    free(B);
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

int readBrackets(char *str)
{
    char buf;
    do
    {
        fscanf(file_input, "%c", &buf);
    } while (buf == ' ' || buf == '\n');
    
    if (buf != '"') return -1;
    fscanf(file_input, "%c", &buf);
    while (buf != '"')
    {
        *(str++) = buf;
        fscanf(file_input, "%c", &buf);
    }
    return 0;
}

int strcmp(char *a, char *b)
{
    while (*a != '\0' && *b != '\0')
    {
        if (*a != *b) return -1;
        a++;
        b++;
    }
    if (*a != *b) return -1;
    return 0;
}