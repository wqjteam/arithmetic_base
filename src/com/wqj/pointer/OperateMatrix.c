/**
  * Created by wqj on 2019/4/26.
 */
#include <stdio.h>

#define col 9

void reversalMatrix(int (*ori)[col], int N);

void clockwiseMatrix(int (*ori)[col], int N);

int main() {
    int N;
    printf("���������ĳ��ȿ��\n");
    scanf("%d", &N);
    int original[col][col];
    int (*ori)[col];
    /**
     *
     * ����
     * Դ����
     *
     * */
    int acce = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
//            original[i][j] = acce;
            acce++;
        }
    }
    int hire = N / 2;
    ori = original;
    reversalMatrix(ori, N);
    clockwiseMatrix(ori, N);
    printf("\n");
    for (int k = 0; k < col; ++k) {
        for (int i = 0; i < col; ++i) {
            printf("%d\t", ori[k][i]);
        }
        printf("\n");
    }

}

/**
 * ��ת����
 * */
void reversalMatrix(int (*ori)[col], int N) {
    printf("���Խ��:%d\n", ori[1][0]);
//    printf("���Խ��2:%d\n", ori[2][0]);

}

/**
 * ��ʱ����ת����
 * orl ԭ����
 * N   ����
 * */
void clockwiseMatrix(int (*ori)[col], int N) {
    /**
     * �㷨��Ʒ�ΪN/2��
     * һ��Ϊ�Ŀ� A,B,C,D
     * */
    int m = 0;
    for (int hier = 0; hier < N / 2; ++hier) {
        /**
         * �Ŀ�
         * �������
         * */
        //A
        for (int i = hier; i < N - hier - 1; ++i) {
            ori[hier][i] = m;
            m++;
        }
        //B
        for (int j = hier; j < N - hier - 1; ++j) {
            ori[j][N - hier - 1] = m;
            m++;
        }
        //C
        for (int k = hier; k < N - hier - 1; k++) {
            ori[N - hier - 1][N - k - 1] = m;
            m++;
        }
        //D
        for (int l = hier; l < N - hier - 1; l++) {
            ori[N - l - 1][hier] = m;
            m++;

        }
        printf("");
    }
}
