/**
  * Created by wqj on 2019/5/5.
 */
#include <stdio.h>
#include <process.h>
#include <mem.h>

/**
 * 共用体类似于
 * 全局静态公共变量
 * 共用体里面的东西只有一个变量可以生效
 * 其他为垃圾值
 *
 * */
union constantV {
    int age;
    int sex;
    char name[20];
    float grade;
} un1 = {.name="qwe"};

union MyUnion {
    int i;
    char chs[11];
} u = {10}, u2 = {.chs="niko"};


/**
 *
 * 在声明一个共用体变量的同时，可以完成其初始化，与结构变量的初始化不同的是，
 * 只能对共用体变量列表中的一个变量进行初始化
 *
 * */
int main() {
    printf("结构体长度\n", sizeof(un1));
    printf("int的长度\n", sizeof(int));
    printf("un1第一次的值:age:%d,sex:%d,name:%s,grade:%f\n", un1.age, un1.sex, un1.name, un1.grade);
    un1.age=1;
    printf("un1第二次的值:age:%d,sex:%d,name:%s,grade:%f\n", un1.age, un1.sex, un1.name, un1.grade);
    union constantV un2 = {.grade= 4};
    printf("un2第一次的值:age:%d,sex:%d,name:%s,grade:%f\n", un2.age, un2.sex, un2.name, un2.grade);
    strcpy(un2.name,"213");
    printf("un2第二次的值:age:%d,sex:%d,name:%s,grade:%f\n", un2.age, un2.sex, un2.name, un2.grade);

    printf("\n\n\n");
    union MyUnion mu = {1};  // 默认初始化第一个成员
    union MyUnion mu2 = {.chs = "hello"};  // 指定要初始化的成员
    printf("mu.i=%d,mu.chs=%s\n", mu.i, mu.chs);  // 一个成员最后被赋值，其他的会出现垃圾值
    printf("mu2.i=%d, mu2.chs=%s\n", mu2.i, mu2.chs);

    u2 = u; // 赋值初始化
    strcpy(u2.chs, "hello world");  // 给共用体变量成员赋值
    printf("u2.i=%d,u2.chs=%s\n", u2.i, u2.chs);
    printf("MyUnion = %d\n", sizeof(union MyUnion));

    union MyUnion *up = &u;  //定义指向共用体的指针
    up->i = 100;
    printf("%d\n", up->i);
//    system("pause");

}
