/**
  * Created by wqj on 2019/5/24.
  * description: 对队列操作 有
 */
#include <stdio.h>
#include <malloc.h>

#define M 10

typedef struct node3 {
    char data;
    struct node3 *link;
} QNode, *QLink;

void INITALQ(QLink *front, QLink *rear);

int pushQueue(QLink *front, QLink *rear, char data);

int deleteQueue(QLink *front, QLink *rear, char *data);

int delsQueue(QLink *front, QLink *rear);

int main() {
    QLink front, rear;
    char item;
    INITALQ(&front, &rear);

    pushQueue(&front, &rear, 'a');
    pushQueue(&front, &rear, 'b');
    pushQueue(&front, &rear, 'c');
    pushQueue(&front, &rear, 'd');
    deleteQueue(&front, &rear, &item);
    pushQueue(&front, &rear, 'e');
    deleteQueue(&front, &rear, &item);
    deleteQueue(&front, &rear, &item);
    deleteQueue(&front, &rear, &item);
    deleteQueue(&front, &rear, &item);
    pushQueue(&front, &rear, 'f');
    pushQueue(&front, &rear, 'g');
    pushQueue(&front, &rear, 'h');
    pushQueue(&front, &rear, 'j');
    delsQueue(&front, &rear);


}

void INITALQ(QLink *front, QLink *rear) {
    *front = NULL;
    *rear = NULL;
}

int EMPYTQ(QLink *front, QLink *rear) {
    return *front == NULL;
}

int pushQueue(QLink *front, QLink *rear, char data) {
    /**
     * 如果为NULL,那么就没偶一个
     * */
    QLink p = (QLink) malloc(sizeof(QNode));
    p->data = data;
    p->link = NULL;
    if (*front == NULL) {
        *front = p;
    } else {
        (*rear)->link = p;
    }
    *rear = p;
    return 1;
}

int deleteQueue(QLink *front, QLink *rear, char *data) {
    /**
     * 用来保存要释放的内存
     * */
    QLink q;
    /**
     *
     * 判断是否相等
     * */
    if (*front == NULL)
        return 0;
    *data = (*front)->data;
    q = (*front);
    *front = (*front)->link;
    free(q);
    /**
     * 取完数据之后如果发现
     * *front为空,证明数据全部跑完,
     * 将*rear也设置为NULL,无关系
     * */
    if (*front == NULL)
        *rear = NULL;
    return 1;

}


int delsQueue(QLink *front, QLink *rear) {
    /**
    * 用来保存要释放的内存
    * */
    QLink q;
    while (*front != NULL) {
        q = *front;
        *front = (*front)->link;
        free(q);
    }
    *rear = NULL;
    return 1;
}