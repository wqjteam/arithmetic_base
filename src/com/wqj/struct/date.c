/**
  * Created by wqj on 2019/4/30.
 */
#include <stdio.h>
#include <malloc.h>
#include <mem.h>

/**
 * typedef  ԭ������  ��������
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


/**
 * ����������
 * */

// ����ʹ��
//struct MyStruct {
//    int a;
//    struct MyStruct my;  // �γ��˵ݹ�����
//};

// ��ȷʹ��
struct MyStruct {
    int a;
    struct MyStruct *my;  // ʹ��ָ��ṹ���ָ��
};

typedef struct {
    int height;
    char name[20];
    char sex;
    int age;
} person;


void main() {

    birthday d1 = {2, 11, 2019, 20190210, "����"};
    student s1 = {20, "asdasdasd", d1};
    birthday *d1_p = &d1;
    //��Ա�������÷�ʽ
//    1)  �ṹ�������.��Ա��
//    2)  �ṹ��ָ����->��Ա����
//    3) (*�ṹ��ָ����).��Ա����
    printf("����%c%c%c%c\n", s1.by.mon_name[0], s1.by.mon_name[1], s1.by.mon_name[2], s1.by.mon_name[3]);
    printf("����%c%c%c%c\n", d1_p->mon_name[0], d1_p->mon_name[1], d1_p->mon_name[2], d1_p->mon_name[3]);

    person per[3] = {{100, "XX", 'M', 18},
                     {100, "YY", 'F', 19},
                     {100, "ZZ", 'M', 20}};

    person *perp = (person *) malloc(sizeof(person) * 3);  // ��̬�����ڴ�

    for (int i = 0; i < 3; ++i) {
        perp[i].height = i;
        strcpy(perp[i].name, "name");
        perp[i].sex = i % 2 == 0 ? 'M' : 'F';
        perp[i].age = i * 10;
    }
    /**
     * �����е�����
     * */
    printf("����:%d\n", (perp + 2)->age);
}

