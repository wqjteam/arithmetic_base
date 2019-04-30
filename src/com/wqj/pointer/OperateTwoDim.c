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

    int yi[] = {1, 2, 3, 4, 5};
    int *yip = yi;
    printf("一维输出结果是%d\n", *(yi + 1));
    printf("一维输出结果是%d\n", *(yip + 1));
    //证实  不可以直接给指针复制,只可以先初始化,然后嫁接到到新创建的指正上
//    int *yip2={1,2,3,4,5};
//    printf("一维输出结果2是%d\n",*(yip2+1));
    /**
     *
     * 使用二维数组
     * */
    int f[3][4] = {{0, 1, 2,  3},
                   {4, 5, 6,  7},
                   {8, 9, 10, 11}};
    int (*z1)[4];
    z1 = f;//数组指正 指向数组名
    int *z2 = f[0];  //一般指针 指向f[0]第一行
    printf("一行有:%d列\n", sizeof(*f) / sizeof(int));
    printf("*(*(z1) + 2输  出:%d\n", *(*(z1) + 2)); //f[0][2]
    printf("z1[0][2]输  出:%d\n", z1[0][2]); //f[0][2]
    printf("*(*(z1 + 1) + 2)输  出:%d\n", *(*(z1 + 1) + 2)); //f[1][2]
    printf("*(*(z1) + 2)输  出:%d\n", *(*(z1) + 2)); //f[0][2]

    //传递“指针数组”  先将二维数组的行指针存储到一个指针数组中，再将指针数组传递到子函数中去
    //这种方法更加常用
    twodimension(z1, 3);
    printf("\n");
    //传递“数组指针”
    twodimension(f, 3);//都行

    printf("\n");
}

void twodimension(int (*t)[4], int len) {
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < 4; ++j) {
            /**
             * 注意此获取方式
             * */
            printf("%d\t", t[i][j]);//printf("%d\t", *(*(t + i)) + j); 两种方式都可以
        }
        printf("\n");
    }
}