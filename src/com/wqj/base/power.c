#include <stdio.h>
d()
{
    int base, num;
    scanf_s("%d %d", &base, &num);
    double b = powerV(base, num);
    printf("½á¹ûÎª%f", b);
}

int powerV(int base, int num)
{
    double sum = base;
    for (int i = 1; i < num; i++)
    {
        sum = sum * base;
    }
    return sum;
}