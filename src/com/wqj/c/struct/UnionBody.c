/**
  * Created by wqj on 2019/5/5.
 */
#include <stdio.h>
#include <process.h>
#include <mem.h>

/**
 * ������������
 * ȫ�־�̬��������
 * ����������Ķ���ֻ��һ������������Ч
 * ����Ϊ����ֵ
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
 * ������һ�������������ͬʱ������������ʼ������ṹ�����ĳ�ʼ����ͬ���ǣ�
 * ֻ�ܶԹ���������б��е�һ���������г�ʼ��
 *
 * */
int main() {
    printf("�ṹ�峤��\n", sizeof(un1));
    printf("int�ĳ���\n", sizeof(int));
    printf("un1��һ�ε�ֵ:age:%d,sex:%d,name:%s,grade:%f\n", un1.age, un1.sex, un1.name, un1.grade);
    un1.age=1;
    printf("un1�ڶ��ε�ֵ:age:%d,sex:%d,name:%s,grade:%f\n", un1.age, un1.sex, un1.name, un1.grade);
    union constantV un2 = {.grade= 4};
    printf("un2��һ�ε�ֵ:age:%d,sex:%d,name:%s,grade:%f\n", un2.age, un2.sex, un2.name, un2.grade);
    strcpy(un2.name,"213");
    printf("un2�ڶ��ε�ֵ:age:%d,sex:%d,name:%s,grade:%f\n", un2.age, un2.sex, un2.name, un2.grade);

    printf("\n\n\n");
    union MyUnion mu = {1};  // Ĭ�ϳ�ʼ����һ����Ա
    union MyUnion mu2 = {.chs = "hello"};  // ָ��Ҫ��ʼ���ĳ�Ա
    printf("mu.i=%d,mu.chs=%s\n", mu.i, mu.chs);  // һ����Ա��󱻸�ֵ�������Ļ��������ֵ
    printf("mu2.i=%d, mu2.chs=%s\n", mu2.i, mu2.chs);

    u2 = u; // ��ֵ��ʼ��
    strcpy(u2.chs, "hello world");  // �������������Ա��ֵ
    printf("u2.i=%d,u2.chs=%s\n", u2.i, u2.chs);
    printf("MyUnion = %d\n", sizeof(union MyUnion));

    union MyUnion *up = &u;  //����ָ�������ָ��
    up->i = 100;
    printf("%d\n", up->i);
//    system("pause");

}
