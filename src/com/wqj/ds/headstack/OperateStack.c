/**
  * Created by wqj on 2019/5/14.
  * description: 初始化堆栈
 */
#include <stdio.h>

#define L 100
char STACK[L];
int top;

void initStack(int *top);

int full(int top);

int empty(int top);

int PUSH(char STACK[], int *top, char item);

int main() {
    top;

    initStack(&top);
}

/**
 *初始化堆栈
 * */
void initStack(int *top) {
    (*top) = -1;
}

/**
 * 测试堆栈
 * 是否为空
 * */
int empty(int top) {
    return top == -1;
}

/**
 * 测试top
 * 是否已满
 * 1:满 0:不满
 * */
int full(int top) {
    return top == L - 1;
}

int PUSH(char STACK[], int *top, char item) {
    if (full(top)) {
        return 0;
    } else {
        STACK[*++top] = item;
        return 1;
    }
}

int delete(char STACK[], int *top, int *item) {
    if (*top == 0) {
        return 0;
    }
    //将值赋给item中,不删除,插入时候直接替换
    item = STACK[*top--];
    return 1;

}

/**
 *
 * 对于两个栈占用一个数据的情况
 * */


