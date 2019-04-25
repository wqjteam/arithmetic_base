/**
  * Created by wqj on 2019/4/25.
 */
#include <stdio.h>

void swap(int *a, int *b, int len);

void joinstr(int *a, int *b, int len, int *c);

void orderArray(int *a, int len);

void twodimension(char *t[6]);

void main() {
    int a[] = {2, 1, 4, 3, 5};
    int b[] = {6, 7, 8, 9, 10};
    int c[10];

    /**
     * ��������־����±�Ϊ0�ĵ�ַ
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
     * �����������
     * */
    joinstr(a, b, sizeof(b) / sizeof(int), c);
    for (int i = 0; i < sizeof(c) / sizeof(int); ++i) {
        printf("%d\t", c[i]);

    }
    printf("\n");


    /**
     *
     * �������
     * */
    orderArray(a, sizeof(a) / sizeof(int));
    for (int i = 0; i < sizeof(a) / sizeof(int); ++i) {
        printf("%d\t", *(a + i));
    }
    printf("\n");


    /**
     *
     * ʹ�ö�ά����
     * */
    int *f[3][4] = { {0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11} };
    int (*z)[4]=f;
    printf("���:%d\n", *f);
    printf("���:%c", *(*(z+1)+2));
//    twodimension(z);
    printf("\n");

}

/**
 * ���ཻ������
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
* �������
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
         * Ѱ����������
         * */
        for (int j = 1; j <= i; ++j) {
            int *next;
            next = a + j;
            if (*max < *next) {
                max = next;
            }
        }

        /**
         * ����˳��
         * */
        int temp = *(a + i);
        *(a + i) = *max;
        *max = temp;
    }
}


void twodimension(char *t[6]) {
    for (int i = 0; i < 6; ++i) {
        int width = sizeof(*(t + i)) / sizeof(int);
        for (int j = 0; j < width; ++j) {
            /**
             * ע��˻�ȡ��ʽ
             * */
            printf("%c", *(*(t + i)) + j);
        }
        printf("\n");
    }


}