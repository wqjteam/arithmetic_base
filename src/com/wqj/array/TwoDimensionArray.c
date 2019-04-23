#include <stdio.h>

#define M 2
#define N 3

void excutors(int a[][M], int b[][N], int alen, int blen);

/**
 *
 * 矩阵计算算法
 *
 * */
int main() {

    int aArray[N][M] = {1, 2, 3, 4, 5, 6};
    int bArray[M][N] = {1, 2, 3, 4, 5, 6};
    /**
     * 总数量
     * */
    int alen = sizeof(aArray) / sizeof(int);
    int blen = sizeof(bArray) / sizeof(int);

    /**
     *
     * 计算两个矩阵
     *
     * */

    excutors(aArray, bArray, sizeof(aArray) / sizeof(aArray[0]), sizeof(bArray) / sizeof(bArray[0]));

//    for

}


void excutors(int a[][M], int b[][N], int alen, int blen) {
    int c[alen][N];

    for (int i = 0; i < alen; ++i) {
        for (int j = 0; j < N; ++j) {
            int temp = 0;
            for (int k = 0; k < M; ++k) {
                temp += a[i][k] * b[k][j];
            }
            c[i][j] = temp;
        }
    }

    for (int l = 0; l < alen; ++l) {
        for (int i = 0; i < N; ++i) {
            printf("|%d", c[l][i]);
        }
        printf("\n");
    }

}
