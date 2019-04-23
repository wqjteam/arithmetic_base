#include<stdio.h>
#define PI 3.14156
void b()
{
    double radius,area,perimeter;
    printf("ÇëÊäÈë:\n");
    // scanf("%d",&radius);
    radius=2.14;
    area=PI*radius*radius;
    perimeter=2*radius*PI;
    printf("Radius=%6.2f Area=%6.2f Perimeter=%6.2f",radius,area,perimeter);
    printf("");
}