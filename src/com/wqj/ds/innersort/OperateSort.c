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

void recursionQuickSort(int k[], int low, int high);

void QuickSort(int k[], int n);

void sift(int k[], int low, int high);

void heapSort(int k[], int n);

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


    printf("\n\n\n");
    int k6[] = {49, 38, 65, 97, 76, 13, 27, 79};
    printf("�ݹ��������:\n");
    recursionQuickSort(k6, 0, 7);
    for (int i = 0; i < 8; ++i) {
        printf(" %d", k6[i]);
    }


    printf("\n\n\n");
    int k7[] = {49, 38, 65, 97, 76, 13, 27, 79};
    printf("�ǵݹ��������:\n");
    QuickSort(k7, 8);
    for (int i = 0; i < 8; ++i) {
        printf(" %d", k7[i]);
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


/**
 * �ݹ��������
 * */
void recursionQuickSort(int k[], int low, int high) {
    int temp;
    int i = low, j = high;
    if (low < high) {
        temp = k[low];
        /**
         * ָ���������� i j ��Ϊ��ͷ����β��
         * �Ե�һ���ؼ��ʵ�ֵΪ�ֽ��
         * ��С�����Ĺؼ��ʷ����ұ�
         * ���������Ĺؼ��ʷ������
         * */
        while (i < j) {
            while (j > i && k[j] >= temp) --j;
            /**
             * ����С�����Ĺؼ���
             * */
            if (i < j) {
                k[i] = k[j];
                i++;
            }
            while (i < j && k[i] < temp) ++i;
            /**
             * ����������Ĺؼ���
             * */
            if (i < j) {
                k[j] = k[i];
                --j;

            }
        }
        k[i] = temp;
        /**
         * ��j+1����i+1����һ����
         * */
        recursionQuickSort(k, low, i - 1);
        recursionQuickSort(k, i + 1, high);
    }
}


/**
 * �ǵݹ��㷨
 * */
void QuickSort(int k[], int n) {
    /**
     * ���ó���Ϊn,��֤�������
     * */
    int z[n], front = 0, rear = 0, i, j, temp, low, high;
    z[rear++] = 0;
    z[rear++] = n - 1;
    while (front < rear) {
        /**
         * ������
         * */
        low = i = z[front++];
        high = j = z[front++];
        temp = k[i];

        while (i < j) {
            while (i < j && temp <= k[j]) j--;
            /**
              * ����С�����Ĺؼ���
              */
            if (i < j) {
                k[i] = k[j];
                i++;
            }
            while (i < j && temp > k[i]) i++;
            /**
             * ����������Ĺؼ���
             * */
            if (i < j) {
                k[j] = k[i];
                j--;
            }
        }
        /**
         * ��ص�һ���Աȵ�����
         * */
        k[i] = temp;
        /**
         * ��ջ,��Ҫ�´α���
         * ��֤ͷ��β
         * */
        if (low < i - 1) {
            z[rear++] = low;
            z[rear++] = i - 1;

        }
        if (high > i + 1) {
            z[rear++] = i + 1;
            z[rear++] = high;
        }

    }
}


/**
 *
 * ������
 *
 * */
void heapSort(int k[], int n) {
    int temp;
    for (int i = n / 2 - 1; i >= 0; ++i)
        sift(k, i, n - 1);
    for (int i = n - 1; i > 0; --i) {
        temp = k[0];
        k[0] = k[i];
        k[i] = temp;
        sift(k, 0, i - 1);
    }
}

void sift(int k[], int low, int high) {
    int i = low, j = 2 * i + 1;
    int temp = k[i];
    while (j <= high) {
        if (j < high && k[j] < k[j + 1]) {
            ++j;
        }
        if (temp < k[j]) {
            k[i] = k[j];
            i = j;
            j = 2 * i + 1;
        } else {
            break;
        }
    }
    k[i] = temp;
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
