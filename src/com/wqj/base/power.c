#include <stdio.h>
int powerV(int base, int num);
int main()
{
    int base, num;
    scanf("%d %d", &base, &num);
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