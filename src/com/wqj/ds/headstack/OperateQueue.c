/**
  * Created by wqj on 2019/5/24.
  * description: 对队列操作 有
 */
#include <stdio.h>

#define M 10
char QUEUE[M];
int front, rear;

void INITALQ(int *front, int *rear);

int isFull(int front, int rear);

int addQueue(char QUEUE[], char item, int *rear);

int delQueue(char QUEUE[], char *item, int *front, int *rear);

int main() {
    INITALQ(&front, &rear);
    addQueue(QUEUE, 'a', &rear);
    addQueue(QUEUE, 'b', &rear);
    addQueue(QUEUE, 'c', &rear);
    addQueue(QUEUE, 'd', &rear);
    addQueue(QUEUE, 'f', &rear);
    char item;
    delQueue(QUEUE, &item, &front, &rear);
}

void INITALQ(int *front, int *rear) {
    *front = -1;
    *rear = -1;
}

int isFull(int front, int rear) {
    return front == rear;
}

int addQueue(char QUEUE[], char item, int *rear) {
    if (*rear == M - 1) {
        return 0;
    }
    QUEUE[++*rear] = item;
    return 1;
}

int delQueue(char QUEUE[], char *item, int *front, int *rear) {
    if (*front == *rear) {
        return 0;
    }

    *item = QUEUE[++*front];
    return 1;
}

