#include<stdio.h>

void reverseArray(int A[], int from, int to);

void frontArray(int A[], int n, int k);

int main(int argc, char const *argv[]) {
    /* code */
    int x[50];
    int a;
//    scanf("%d", &a);
    a = 1;
    x[a + 1]++;
    for (int i = 0; i < 10;) {
        printf("%d\n", i);
        ++i;
    }
    switch (1) {
        /**case 1:case 2 可以重叠*/
        case 1:
        case 2:
            printf("12213");
    };/** ;可加可不加*/

    int A[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    frontArray(A, 10, 1);
    printf("\n\n\n");
    for (int j = 0; j < 10; ++j) {
        printf("|%d|", A[j]);
    }
    printf("\n");
    return 0;


}

/**
 * 才去分而治之的方法
 * 分为 0到 n-k-1
 * 和n-k到n-1
 * */
void frontArray(int A[], int n, int k) {
    reverseArray(A, 0, n - k - 1);
    reverseArray(A, n - k, n - 1);
    reverseArray(A, 0, n - 1);

}

/**
 *
 * 翻转数组
 * */
void reverseArray(int A[], int from, int to) {
    int temp;
    for (; from < to; from++, to--) {
        temp = A[from];
        A[from] = A[to];
        A[to] = temp;
    }
}
