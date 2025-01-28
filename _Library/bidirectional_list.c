
typedef struct list {
    int Num;
    struct list *Down;
    struct list *Up;
} List;

typedef struct deck {
    List *Top;
    List *Bottom;
} Deck;

void put_on_top(Deck *d, int n);
void put_on_bottom(Deck *d, int n);
int rm_from_top(Deck *d, int *b);
int rm_from_bottom(Deck *d, int *b);

void put_on_top(Deck *d, int n)
{
    if (d->Top == NULL)
    {
        d->Top = calloc(1, sizeof(List));
        d->Top->Num = n;
        d->Bottom = d->Top;
    }
    else
    {
        d->Top->Up = calloc(1, sizeof(List));
        d->Top->Up->Down = d->Top->Up;
        d->Top = d->Top->Up;
        d->Top->Num = n;
    }
}

void put_on_bottom(Deck *d, int n)
{
    if (d->Bottom == NULL)
    {
        d->Bottom = calloc(1, sizeof(List));
        d->Bottom->Num = n;
        d->Top = d->Bottom;
    }
    else
    {
        d->Bottom->Down = calloc(1, sizeof(List));
        d->Bottom->Down->Up = d->Bottom->Down;
        d->Bottom = d->Bottom->Down;
        d->Bottom->Num = n;
    }
}

int rm_from_top(Deck *d, int *b)
{
    if (d->Top == NULL)
    {
        return EMPTY_DECK;
    }
    
    *b = d->Top->Num;
    List *lnk = d->Top;
    d->Top = d->Top->Down;
    free(lnk);
    if (d->Top == NULL) d->Bottom = NULL;
    return OK;
}

int rm_from_bottom(Deck *d, int *b)
{
    if (d->Bottom == NULL)
    {
        return EMPTY_DECK;
    }
    
    *b = d->Bottom->Num;
    List *lnk = d->Bottom;
    d->Bottom = d->Bottom->Up;
    free(lnk);
    if (d->Bottom == NULL) d->Top = NULL;
    return OK;
}