//
// Created by lenovo on 2019/4/22.
//

#include <stdio.h>

int main() {

    int sorta[] = {3, 1, 4, 5, 6, 9, 4, 7, 0,8,6};

    /**
     *
     * ð��
     * ����
     *
     * */

    int len = sizeof(sorta) / sizeof(int);

    /**
     * �Ӻ�����ǰ��Ա�
     * */
    for (int i = len - 1; i >= 0; i--) {
        /**
         * ǰ�����ݽ��жԱ�
         * */
        for (int j = 0; j <= i; j++) {
            int temp;
            int next_int;
            if (j + 1 > i) {
                next_int = j;
            } else {
                next_int = j + 1;
            }
            if (sorta[j] > sorta[next_int]) {
                temp = sorta[next_int];
                sorta[next_int] = sorta[j];
                sorta[j] = temp;
            }
        }
    }

    for (int i = 0; i < len; i++) {

    printf("%d",sorta[i]);
    }
}

