
unsigned int hash(char *str)
{
    double A = 0.6180339887498949;
    double acc = 0;
    unsigned int c = 1;
    while (*str != '\0')
    {
        acc += (*str) * (c *= 173) * A;
        acc -= (int) acc;
        str++;
    }
    return acc * 0xFFFFFFFF;
}