#include <stdio.h>
#include <mem.h>
#include <malloc.h>
#include <math.h>
#include "Bubble.h"

#define ABC(x) x*x
#define CANBERRA(x, y) ((x-y)/(x+y))
/**
 * 在使用main函数的带参版本的时，最常用的就是：int main(int argc , char* argv[]）;
 * 变量名称argc和argv是常规的名称，当然也可以换成其他名称。
 * 命令行执行的形式为：可执行文件名 参数1 参数2 … … 参数n。可执行文件名称和参数、参数之间均使用空格隔开
 * */
struct node1 {
    int a;
    int c;
    char str[100];
    struct node1 *z;
} SSSS;

void func2(int *x, int *y) {
    int *temp;
    *temp = *x;
    *x = *y;
    *y = *temp;
}

void recur(int num) {
    if (num == 0) return;
    else printf("%d\n", num);
    recur(num--);
}

int func3(int x, int y) {
    return 0;
}

void aaa2() {
    int a = 0;
    return;
}

int main(int argc, char *argv[]) {


    char c = 48;
    int i, mask = 01;
    i = 3, c = 'd';
    for (int j = 0; j < 5; ++j) {
        printf("%c", c | mask);
        mask = mask << 1;
    }

    int n = 366;
    int a, sum = 0;
    i = 0;
    while (n) {
        a = n % 8;
        n = n / 8;
        sum += a * pow(10, i);
        i++;
    }
    printf("\n\n");
    n = getchar();
    getchar();
    c = getchar();
    printf("\n%d\n%d", n, c);
    return 0;


}

