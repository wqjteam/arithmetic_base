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
    printf("插入排序:\n");
    INSERTSORT(k, 8);
    for (int i = 0; i < 8; ++i) {
        printf(" %d", k[i]);
    }

    printf("\n\n\n");
    int k2[] = {49, 38, 65, 97, 76, 13, 27, 79};
    printf("折半插入排序:\n");
    BIN_INSERTSORT(k2, 8);
    for (int i = 0; i < 8; ++i) {
        printf(" %d", k2[i]);
    }

    printf("\n\n\n");
    int k3[] = {49, 38, 65, 97, 76, 13, 27, 79};
    printf("选择排序:\n");
    SELECTSORT(k3, 8);
    for (int i = 0; i < 8; ++i) {
        printf(" %d", k3[i]);
    }

    printf("\n\n\n");
    int k4[] = {49, 38, 65, 97, 76, 13, 27, 79};
    printf("冒泡排序:\n");
    BUBBLESORT(k4, 8);
    for (int i = 0; i < 8; ++i) {
        printf(" %d", k4[i]);
    }


    printf("\n\n\n");
    int k5[] = {49, 38, 65, 97, 76, 13, 27, 79};
    printf("希尔排序:\n");
    SHELLSORT(k5, 8);
    for (int i = 0; i < 8; ++i) {
        printf(" %d", k5[i]);
    }
    return 0;
}

/**
 * 插入排序
 * */
void INSERTSORT(int k[], int n) {
    int temp;
    /**
     * 需要排序的是2到n 下标就是1到n-1
     * */
    for (int i = 1; i < n; ++i) {
        temp = k[i];
        int j = i - 1;
        /**
         * 移动大于temp的数据
         * */
        while (j >= 0 && temp < k[j]) {
            k[j + 1] = k[j];
            j--;
        }
        /**
         * 落地temp数据
         * */
        k[j + 1] = temp;
    }
}

/**
 * 折半
 * 插入排序
 * */
void BIN_INSERTSORT(int k[], int n) {
    int low, high, mid, temp;
    for (int i = 1; i < n; ++i) {
        temp = k[i];
        low = 0;
        high = i - 1;
        /**
         * 寻找合适的位置
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
         * 移动数据
         * */
        for (int j = i - 1; j >= low; j--) {
            k[j + 1] = k[j];
        }
        /**
        * 落地temp数据
        * */
        k[low] = temp;
    }
}

/**
 * 选择排序
 * 选择出最小的 与第i个交换位置
 * */
void SELECTSORT(int k[], int n) {
    int index, temp;
    for (int i = 0; i < n; ++i) {
        index = i;
        /**
         * 寻找最小的数据
         * */
        for (int j = i + 1; j < n; ++j) {
            if (k[index] > k[j]) {
                index = j;
            }
        }
        /**
         * 交换数据
         * */
        if (index != i) {
            temp = k[index];
            k[index] = k[i];
            k[i] = temp;
        }

    }
}

/**
 * 冒泡排序
 * */
void BUBBLESORT(int k[], int n) {
    int i = n, temp, flag = 1;
    while (i > 0 && flag == 1) {
        flag = 0; /**  每趟排序之前 先把标志flag立为0*/
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
 * 设置gap 每次比较不同的数据量
 * 希尔排序
 * */
void SHELLSORT(int k[], int n) {
    int temp, gap = n;
    /**
     * 起始值gap为n,循环一次除以2向下取整
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
             * 循环对比间隔gap的数据
             * 如果一旦发现不符合规则
             * 说明:前面的gap已经是有序的了
             * j >= gap 防止j >= gap出现异常
             * */
            for (j = i; j >= gap && k[j - gap] > temp; j -= gap) {
                /**
                 * 往后移动为数据
                 * */
                k[j] = k[j - gap];
            }
            /**
             * 把temp数据填入到交换位置
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
