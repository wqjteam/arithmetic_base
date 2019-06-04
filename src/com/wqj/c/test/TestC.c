/**
  * Created by wqj on 2019/5/10.
  * description:
 */
#include <stdio.h>

#define CANBERRA(x, y) ((x-y)/(x+y))

int main(int argc, char *argv[]) {
    /**
    *
    * */
    printf("CANBERRA(4, 1):%d\n", CANBERRA(4, 1));
    printf("CANBERRA(8, -4):%d\n", CANBERRA(8, -4));
    printf("CANBERRA(3.0, 2.0):%d\n", CANBERRA(3.0, 2.0));
    printf("CANBERRA(4.0, 1.0):%d\n", CANBERRA(4.0, 1.0));
    printf("CANBERRA(1.0 + 2.0, 0.0 + 2.0):%d\n", CANBERRA(1.0 + 2.0, 0.0 + 2.0));
    printf("CANBERRA(1.0 + 2.0, 1.0 + 1.0):%d\n", CANBERRA(1.0 + 2.0, 1.0 + 1.0));
    printf("\n\n\n\n");




    /**
     * ≤‚ ‘≤Œ ˝
     *
     * */
    printf("D:\\c_space\\arithmetic_base\\cmake-build-debug\\arithmetic_base_18.exe sample January February March\n");
    printf("argv[0]:%s\nargv[1]:%s\nargv[2]:%s\nargv[3]:%s\nargv[4]:%s\n", argv[0], argv[1], argv[2], argv[3], argv[4]);
    char *zz[100];
//    ++argv;
//    printf("argv[1][1]:%s\n", argv[2]);
//    printf("argv[1][1]:%c\n", argv[1][1]);
//    printf("argv[1][2]:%c\n", argv[1][2]);
//    printf("*++argv[0]:%c\n", *++argv[0]);
//    printf("*++argv[2]:%c\n", *++argv[2]);
//    printf("*++argv[3]:%c\n", *++argv[3]);
//    printf("*argv++[2]:%c\n", *argv++[2]);
//    printf("*argv++[2]:%c\n", *argv++[2]);
    printf("*(++argv)[2]:%c\n", *(++argv)[2]);
//    printf("*(argv++)[2]:%c\n", *(argv++)[2]);

//    int a[][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
//    int *c[3];
//    for (int i = 0; i < 3; ++i) {
//        c[i] = a[i];
//    }
//
//    printf("%d\n", *(c + 1));

}


