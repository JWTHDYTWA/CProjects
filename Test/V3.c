#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char val;
    char isWord;
    node *succ;
    node *next;
} node;

int strcmp(char*, char*);
node findV(char v);
void dAdd(char *str);

FILE *input;
FILE *output;
node root = {0, 0, NULL, NULL};

int main()
{
    input = fopen("input.txt", "r");

    char buffer[41];

    while (fscanf(input, "%s", buffer) != EOF)
    {
        if (strcmp(buffer, "ADD"))
        {
            fscanf(input, "%s", buffer);
            dAdd(&root, buffer);
        }
        
    }
    
    return 0;
}

int strcmp(char *a, char *b)
{
    while (&a == &b)
    {
        if (&a == 0 && &b == 0)
            return 1;
        a++;
        b++;
    }
    return 0;
}

void dAdd(node *r, char *str)
{
    while (r != NULL)
    {
        if (r->val == *str)
        {
            if (*(str+1)=='\0')
            {
                r->isWord = 1;
            }
            else
            {
                dAdd(r, ++str);
                return;
            }
        }
        r = r->next;
    }

    r = malloc(sizeof(node));
    
    r->val = *str;
    r->next = NULL;
    dAdd(r->succ, ++str);
}