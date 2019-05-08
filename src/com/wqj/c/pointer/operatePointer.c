/**
  * Created by wqj on 2019/4/25.
 */
#include <stdio.h>

void swap(int *a, int *b, int len);

void joinstr(int *a, int *b, int len, int *c);

void orderArray(int *a, int len);

//void twodimension(char *t[6]);

void main() {
    int a[] = {2, 1, 4, 3, 5};
    int b[] = {6, 7, 8, 9, 10};
    int c[10];

    /**
     * 数组的名字就是下标为0的地址
     * */
    swap(a, b, sizeof(a) / sizeof(int));
    for (int i = 0; i < sizeof(a) / sizeof(int); ++i) {
        printf("%d\t", a[i]);

    }
    printf("\n");
    for (int i = 0; i < sizeof(b) / sizeof(int); ++i) {
        printf("%d\t", b[i]);

    }
    printf("\n");


    /**
     * 测试组合数组
     * */
    joinstr(a, b, sizeof(b) / sizeof(int), c);
    for (int i = 0; i < sizeof(c) / sizeof(int); ++i) {
        printf("%d\t", c[i]);

    }
    printf("\n");


    /**
     *
     * 组合排序
     * */
    orderArray(a, sizeof(a) / sizeof(int));
    for (int i = 0; i < sizeof(a) / sizeof(int); ++i) {
        printf("%d\t", *(a + i));
    }
    printf("\n");




}

/**
 * 互相交换数据
 * */
void swap(int *a, int *b, int len) {
    for (int i = 0; i < len; ++i) {
        int temp = *a;
        *a = *b;
        *b = temp;
        a++;
        b++;
    }
}

/**
* 组合数据
* */
void joinstr(int *a, int *b, int len, int *c) {
    for (int i = 0; i < len; ++i) {
        *c = *a;
        a++;
        c++;
        *c = *b;
        b++;
        c++;
    }
}


void orderArray(int *a, int len) {
    for (int i = len - 1; i >= 0; i--) {
        int *max;
        max = a;
        /**
         * 寻找最大的数据
         * */
        for (int j = 1; j <= i; ++j) {
            int *next;
            next = a + j;
            if (*max < *next) {
                max = next;
            }
        }

        /**
         * 交换顺序
         * */
        int temp = *(a + i);
        *(a + i) = *max;
        *max = temp;
    }
}


