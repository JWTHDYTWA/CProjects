#include <stdlib.h>

typedef struct
{
    int elements;
    int size;
    void *array;
} DynamicArray;

DynamicArray dynamicArray()
{
    DynamicArray ret = {0, 0, NULL};
    return ret;
}

void *newElementPointer(DynamicArray arr, size_t elemSize)
{
    if (arr.size == 0)
    {
        arr.array = malloc(elemSize * 4);
        arr.size = 4;
    }
    else if (arr.elements > arr.size)
    {
        arr.size *= 2;
        arr.array = realloc(arr.array, elemSize * arr.size);
    }
    return (void*)((char*)arr.array + (arr.elements++) * elemSize);
}

void *elementPointer(DynamicArray arr, size_t elemSize, int id)
{
    if (id > arr.size) return NULL;
    return (void*)((char*)arr.array + elemSize * id);
}

void *newElementPointerById(DynamicArray arr, size_t elemSize, int id)
{
    while (arr.size <= id)
    {
        arr.size *= 2;
    }
    arr.array = realloc(arr.array, elemSize * arr.size);
}