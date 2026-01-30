#include <stdio.h>
int main()
{
    int a, b, c;
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);
    c = a + b;
    printf("Sum = %d\n", c);
    return 0;
}