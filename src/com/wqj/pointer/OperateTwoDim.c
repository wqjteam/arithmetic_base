/**
  * Created by wqj on 2019/4/26.
 */
#include <stdio.h>

void twodimension(int (*t)[4], int len);

/**
 2     二维数组的几个符号的测试
 3     1、a等同于&a[0]
 4     2、a[0]等同于&a[0][0]
 5     3、在数值上 a、&a、a[0]、&a[0]、&a[0][0] 是相等的，但是在类型上面是有区别的。
 6
7     int a[2][5] = {{1,2,3,4,5},{6,7,8,9,10}};
8
9     printf("a        = %p.\n", a);        // a       类型是 int (*)[5]
10     printf("&a       = %p.\n", &a);       // &a      类型是 int (*)[2][5]
11     printf("a[0]     = %p.\n", a[0]);     // a[0]    类型是 int *
12     printf("&a[0]    = %p.\n", &a[0]);    // &a[0]   类型是 int (*)[5]
13     printf("a[0][0]  = %d.\n", a[0][0]);  // a[0][0] 类型是 int
14     printf("&a[0][0] = %p.\n", &a[0][0]); // &a[0][0]类型是 int *
 */
void main() {
    /**
     *
     * 使用二维数组
     * */
    int f[3][4] = {{0, 1, 2,  3},
                   {4, 5, 6,  7},
                   {8, 9, 10, 11}};
    int (*z1)[4] = f;    //数组指正 指向数组名
    int *z2 = f[0];  //一般指针 指向f[0]第一行
    printf("一行有:%d列\n", sizeof(*f) / sizeof(int));
    printf("输  出:%d\n", *(*(z1) + 2)); //f[0][2]
    printf("输  出:%d\n", *(*(z1 + 1) + 2)); //f[1][2]
    printf("输  出:%d\n", *(*(z1) + 2)); //f[0][2]
    twodimension(z1,4);//twodimension(f,4);都行

    printf("\n");
}

void twodimension(int (*t)[4], int len) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < len; ++j) {
            /**
             * 注意此获取方式
             * */
            printf("%d", *(*(t + i)) + j);
        }
        printf("\n");
    }
}