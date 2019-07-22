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


    printf("\n\n\n");
    int k6[] = {49, 38, 65, 97, 76, 13, 27, 79};
    printf("递归快速排序:\n");
    recursionQuickSort(k6, 0, 7);
    for (int i = 0; i < 8; ++i) {
        printf(" %d", k6[i]);
    }


    printf("\n\n\n");
    int k7[] = {49, 38, 65, 97, 76, 13, 27, 79};
    printf("非递归快速排序:\n");
    QuickSort(k7, 8);
    for (int i = 0; i < 8; ++i) {
        printf(" %d", k7[i]);
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


/**
 * 递归快速排序
 * */
void recursionQuickSort(int k[], int low, int high) {
    int temp;
    int i = low, j = high;
    if (low < high) {
        temp = k[low];
        /**
         * 指定两个浮标 i j 分为在头部和尾部
         * 以第一个关键词的值为分界点
         * 将小于他的关键词放在右边
         * 将大于他的关键词放在左边
         * */
        while (i < j) {
            while (j > i && k[j] >= temp) --j;
            /**
             * 处理小于他的关键词
             * */
            if (i < j) {
                k[i] = k[j];
                i++;
            }
            while (i < j && k[i] < temp) ++i;
            /**
             * 处理大于他的关键词
             * */
            if (i < j) {
                k[j] = k[i];
                --j;

            }
        }
        k[i] = temp;
        /**
         * 用j+1还是i+1都是一样的
         * */
        recursionQuickSort(k, low, i - 1);
        recursionQuickSort(k, i + 1, high);
    }
}


/**
 * 非递归算法
 * */
void QuickSort(int k[], int n) {
    /**
     * 设置长度为n,保证不会溢出
     * */
    int z[n], front = 0, rear = 0, i, j, temp, low, high;
    z[rear++] = 0;
    z[rear++] = n - 1;
    while (front < rear) {
        /**
         * 出队列
         * */
        low = i = z[front++];
        high = j = z[front++];
        temp = k[i];

        while (i < j) {
            while (i < j && temp <= k[j]) j--;
            /**
              * 处理小于他的关键词
              */
            if (i < j) {
                k[i] = k[j];
                i++;
            }
            while (i < j && temp > k[i]) i++;
            /**
             * 处理大于他的关键词
             * */
            if (i < j) {
                k[j] = k[i];
                j--;
            }
        }
        /**
         * 落地第一个对比的数据
         * */
        k[i] = temp;
        /**
         * 入栈,需要下次遍历
         * 保证头和尾
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
 * 堆排序
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
