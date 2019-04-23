//
// Created by lenovo on 2019/4/23.
//
#include <stdio.h>

int add(int a, int b) {
    printf("调用了add方法");
    if (a > b)
        return 0;
    else
        return 1;
}