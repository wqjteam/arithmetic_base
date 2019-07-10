/**
  * Created by wqj on 2019/7/10.
  * description:
 */
#include <stdio.h>

int main() {
    printf("123123");
}


/**
 * 顺序查找
 * resources 源文件
 * n 文件长度
 * find_data寻找的文件
 * */
int SEQ_SEACHER(int resources[], int n, int find_data) {
    for (int i = 0; i < n; i++) {
        if (find_data == resources[i]) {
            return i;
        }
    }
    return -1;
}

/**
 * 二分法查找
 * resources 源文件
 * n 文件长度
 * find_data寻找的文件
 * */
int BIN_SEACHER(int resources[], int n, int find_data) {

    int low = 0, high = n - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (resources[mid] == find_data) {
            return mid;
        }
        if (find_data > resources[mid]) {
            low = mid + 1;
        }
        if (find_data < resources[mid]) {
            high = mid - 1;
        }
    }
    return -1;
}
