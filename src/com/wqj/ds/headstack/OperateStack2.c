/**
  * Created by wqj on 2019/5/21.
  * description:
 */
#include <stdio.h>

int initstack(int *top);

int isFull(int *top);

int pushStack(char STACK[], int *top, int i, char item);

int deleteStack(char STACK[], int *top, int i, char *item);

#define M 200
char STACK[M];
int top[2];

int main(int argc, char *argv[]) {
    initstack(top);
    pushStack(STACK, top, 0, 'c');
    pushStack(STACK, top, 1, 'f');
    char item;
    deleteStack(STACK, top, 1, &item);
}

int initstack(int *top) {
    top[0] = -1;
    top[1] = M;
}

int isFull(int *top) {
    return top[0] == top[1] - 1;
}

int pushStack(char STACK[], int *top, int i, char item) {
    if (isFull(top)) {
        return 0;
    }

    if (i== 0) {
        STACK[++top[0]] = item;
    } else {
        STACK[--top[1]] = item;
    }

}

int deleteStack(char STACK[], int *top, int i, char *item) {
    /**
     * 先判断是否在顶点
     * */
    if (i == 1 && top[1] == M) { ;
        return 0;
    } else if (i == 0 && top[0] == -1) {
        return 0;
    }
    if (i == 0) {
        *item = STACK[top[0]--];
    } else {
        *item = STACK[top[1]++];
    }
    return 1;
}



