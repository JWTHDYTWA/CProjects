#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d\n%d %d", a*b, a%b, b%a);
    return 0;
}
