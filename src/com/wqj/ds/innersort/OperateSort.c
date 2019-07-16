/**
  * Created by wqj on 2019/7/11.
  * description:
 */
#include <stdio.h>

void INSERTSORT(int k[], int n);

void BIN_INSERTSORT(int k[], int n);

void BUBBLESORT(int k[], int n);

void SELECTSORT(int k[], int n);

void SHELLSORT(int k[], int n);

int main(int argc, char *argv[]) {

    int k[] = {49, 38, 65, 97, 76, 13, 27, 79};
    printf("��������:\n");
    INSERTSORT(k, 8);
    for (int i = 0; i < 8; ++i) {
        printf(" %d", k[i]);
    }

    printf("\n\n\n");
    int k2[] = {49, 38, 65, 97, 76, 13, 27, 79};
    printf("�۰��������:\n");
    BIN_INSERTSORT(k2, 8);
    for (int i = 0; i < 8; ++i) {
        printf(" %d", k2[i]);
    }

    printf("\n\n\n");
    int k3[] = {49, 38, 65, 97, 76, 13, 27, 79};
    printf("ѡ������:\n");
    SELECTSORT(k3, 8);
    for (int i = 0; i < 8; ++i) {
        printf(" %d", k3[i]);
    }

    printf("\n\n\n");
    int k4[] = {49, 38, 65, 97, 76, 13, 27, 79};
    printf("ð������:\n");
    BUBBLESORT(k4, 8);
    for (int i = 0; i < 8; ++i) {
        printf(" %d", k4[i]);
    }


    printf("\n\n\n");
    int k5[] = {49, 38, 65, 97, 76, 13, 27, 79};
    printf("ϣ������:\n");
    SHELLSORT(k5, 8);
    for (int i = 0; i < 8; ++i) {
        printf(" %d", k5[i]);
    }
    return 0;
}

/**
 * ��������
 * */
void INSERTSORT(int k[], int n) {
    int temp;
    /**
     * ��Ҫ�������2��n �±����1��n-1
     * */
    for (int i = 1; i < n; ++i) {
        temp = k[i];
        int j = i - 1;
        /**
         * �ƶ�����temp������
         * */
        while (j >= 0 && temp < k[j]) {
            k[j + 1] = k[j];
            j--;
        }
        /**
         * ���temp����
         * */
        k[j + 1] = temp;
    }
}

/**
 * �۰�
 * ��������
 * */
void BIN_INSERTSORT(int k[], int n) {
    int low, high, mid, temp;
    for (int i = 1; i < n; ++i) {
        temp = k[i];
        low = 0;
        high = i - 1;
        /**
         * Ѱ�Һ��ʵ�λ��
         * */
        while (low <= high) {
            mid = (low + high) / 2;
            if (temp < k[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        /**
         * �ƶ�����
         * */
        for (int j = i - 1; j >= low; j--) {
            k[j + 1] = k[j];
        }
        /**
        * ���temp����
        * */
        k[low] = temp;
    }
}

/**
 * ѡ������
 * ѡ�����С�� ���i������λ��
 * */
void SELECTSORT(int k[], int n) {
    int index, temp;
    for (int i = 0; i < n; ++i) {
        index = i;
        /**
         * Ѱ����С������
         * */
        for (int j = i + 1; j < n; ++j) {
            if (k[index] > k[j]) {
                index = j;
            }
        }
        /**
         * ��������
         * */
        if (index != i) {
            temp = k[index];
            k[index] = k[i];
            k[i] = temp;
        }

    }
}

/**
 * ð������
 * */
void BUBBLESORT(int k[], int n) {
    int i = n, temp, flag = 1;
    while (i > 0 && flag == 1) {
        flag = 0; /**  ÿ������֮ǰ �Ȱѱ�־flag��Ϊ0*/
        for (int j = 0; j < i; ++j) {
            if (j + 1 <= n - 1 && k[j] > k[j + 1]) {
                temp = k[j];
                k[j] = k[j + 1];
                k[j + 1] = temp;
                flag = 1;
            }
        }
        i--;
    }
}


/**
 *
 * ����gap ÿ�αȽϲ�ͬ��������
 * ϣ������
 * */
void SHELLSORT(int k[], int n) {
    int temp, gap = n;
    /**
     * ��ʼֵgapΪn,ѭ��һ�γ���2����ȡ��
     * */
    while (gap > 0) {
        gap = gap / 2;
        /**
         *
         * */
        for (int i = gap; i < n; ++i) {
            temp = k[i];
            int j;
            /**
             * ѭ���Աȼ��gap������
             * ���һ�����ֲ����Ϲ���
             * ˵��:ǰ���gap�Ѿ����������
             * j >= gap ��ֹj >= gap�����쳣
             * */
            for (j = i; j >= gap && k[j - gap] > temp; j -= gap) {
                /**
                 * �����ƶ�Ϊ����
                 * */
                k[j] = k[j - gap];
            }
            /**
             * ��temp�������뵽����λ��
             * */
            k[j] = temp;
        }
    }
}

void shell(int k[], int n) {
    int gap = n, temp;
    while (gap > 0) {
        gap = gap / 2;

        for (int i = gap; i < n; i++) {
            int j;
            for (j = i; j >= gap && k[j - gap] > temp; j -= gap) {
                k[j] = k[j - gap];
            }
            k[j] = temp;
        }
    }
}
