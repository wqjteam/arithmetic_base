/**
  * Created by wqj on 2019/6/26.
  * description:操作图
 */

#include <malloc.h>
#include "OperateGraph.h"

void main(int argc, char *argv[]) {

    Vlink vlink[10];



// 邻接矩阵定义图  MV表示顶点间没有变，不邻接
    int Matrix[VNUM][VNUM] =
            {
                    {0,  10, MV, 30, 100},
                    {MV, 0,  50, MV, MV},
                    {MV, MV, 0,  MV, 10},
                    {MV, MV, 20, 0,  60},
                    {MV, MV, MV, MV, 0},
            };


}

void enqueue(LinkList *queue, int vlink) {
    LinkList deliver = *queue, temp = (LinkList) malloc(sizeof(LinkNode));
    temp->link = NULL;
    if (*queue == NULL) {
        *queue = temp;
    } else {
        while (deliver->link != NULL) {
            deliver = deliver->link;
        }
        deliver->link = temp;
    }
}

int delqueue(LinkList *queue) {
    if (*queue == NULL) {
//        return NULL;
    } else {
        int result = (*queue)->data;
//        free()
        *queue = (*queue)->link;
        return result;
    }
}


/**
 * 判断队列
 * 是否为空
 * */
int EmptyQ(LinkList queue) {
    if (queue == NULL) {
        return 1;
    }
    return 0;

}

void pushStack(LinkList *queue, int vlink) {
    /**
     * 如果入值为-1,
     * 那么入值为空
     * 不进行入栈
     * */
    if (vlink == -1) {
        return;
    }
    LinkList newnode = (LinkList) malloc(sizeof(LinkNode));
    newnode->data = vlink;
    newnode->link = (*queue);
    (*queue) = newnode;
}

int popStack(LinkList *queue) {
    int result = (*queue)->data;
    (*queue) = (*queue)->link;
    return result;
}

int readStack(LinkList *queue) {
    return (*queue)->data;
}

int EmptyStack(LinkList queue) {
    if (queue == NULL) {
        return 1;
    }
    return 0;
}


