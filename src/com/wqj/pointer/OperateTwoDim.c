/**
  * Created by wqj on 2019/4/26.
 */
#include <stdio.h>

void twodimension(int (*t)[4], int len);

/**
 2     ��ά����ļ������ŵĲ���
 3     1��a��ͬ��&a[0]
 4     2��a[0]��ͬ��&a[0][0]
 5     3������ֵ�� a��&a��a[0]��&a[0]��&a[0][0] ����ȵģ�����������������������ġ�
 6
7     int a[2][5] = {{1,2,3,4,5},{6,7,8,9,10}};
8
9     printf("a        = %p.\n", a);        // a       ������ int (*)[5]
10     printf("&a       = %p.\n", &a);       // &a      ������ int (*)[2][5]
11     printf("a[0]     = %p.\n", a[0]);     // a[0]    ������ int *
12     printf("&a[0]    = %p.\n", &a[0]);    // &a[0]   ������ int (*)[5]
13     printf("a[0][0]  = %d.\n", a[0][0]);  // a[0][0] ������ int
14     printf("&a[0][0] = %p.\n", &a[0][0]); // &a[0][0]������ int *
 */
void main() {
    /**
     *
     * ʹ�ö�ά����
     * */
    int f[3][4] = {{0, 1, 2,  3},
                   {4, 5, 6,  7},
                   {8, 9, 10, 11}};
    int (*z1)[4] = f;    //����ָ�� ָ��������
    int *z2 = f[0];  //һ��ָ�� ָ��f[0]��һ��
    printf("һ����:%d��\n", sizeof(*f) / sizeof(int));
    printf("��  ��:%d\n", *(*(z1) + 2)); //f[0][2]
    printf("��  ��:%d\n", *(*(z1 + 1) + 2)); //f[1][2]
    printf("��  ��:%d\n", *(*(z1) + 2)); //f[0][2]
    twodimension(z1,4);//twodimension(f,4);����

    printf("\n");
}

void twodimension(int (*t)[4], int len) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < len; ++j) {
            /**
             * ע��˻�ȡ��ʽ
             * */
            printf("%d", *(*(t + i)) + j);
        }
        printf("\n");
    }
}