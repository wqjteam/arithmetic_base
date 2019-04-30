/**
  * Created by wqj on 2019/4/30.
 */
#include <stdio.h>

/**
 * typedef  原类型名  新类型名
 * */
typedef struct {
    int day;
    int month;
    int year;
    int yesterday;
    char mon_name[4];
} birthday;

typedef struct {
    int age;
    char name[20];
    birthday by;
} student;

void main() {


    birthday d1 = {2, 11, 2019, 20190210, "张三"};
    student s1 = {20, "asdasdasd", d1};
    printf("名字%c%c%c%c", s1.by.mon_name[0],s1.by.mon_name[1],s1.by.mon_name[2],s1.by.mon_name[3]);
}

