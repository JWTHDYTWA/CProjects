#include <stdio.h>
#include <stdlib.h>

#define u64 unsigned long long
#define u32 unsigned int

FILE * file_input;
FILE * file_output;

typedef struct br {
    int value;
    struct br *left;
    struct br *right;
} branch;

int init();
void deinit();

void addBranch(branch **r, int x);
void treeTraverse(branch *root, void (*fn)(int));
void outputNum(int x);

int main(int argc, char const *argv[])
{
    /* Переменные */
    
    int N;
    int *A;
    branch *BST = NULL;
    int buf;

    /* Открытие файлов */
    if (init() < 0) return -1;

    /* Логика */
    
    fread(&N, 4, 1, file_input);
    A = malloc(sizeof(int)*N);

    for (size_t i = 0; i < N; i++)
    {
        fread(&buf, 4, 1, file_input);
        addBranch(&BST, buf);
    }
    
    treeTraverse(BST, outputNum);
    
    /* Вывод и закрытие файлов */
    deinit();
    return 0;
}

int init()
{
    file_input = fopen("input.bin", "rb");
    file_output = fopen("output.bin", "wb");

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

void addBranch(branch **r, int x)
{
    if (*r == NULL)
    {
        *r = calloc(1, sizeof(branch));
        (*r)->value = x;
    }
    else
    {
        if (x <= (*r)->value) addBranch(&(*r)->left, x);
        else addBranch(&(*r)->right, x);
    }
}

void treeTraverse(branch *root, void (*fn)(int))
{
    if (root->left != NULL) treeTraverse(root->left, fn);
    fn(root->value);
    if (root->right != NULL) treeTraverse(root->right, fn);
}

void outputNum(int x)
{
    fwrite(&x, 4, 1, file_output);
}