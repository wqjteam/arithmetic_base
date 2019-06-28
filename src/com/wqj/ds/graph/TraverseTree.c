/**
  * Created by wqj on 2019/6/27.
  * description:
 */

#include <OperateGraph.h>


/**
 * 深度
 * 优先搜索
 * */
void Traverl_DFS(Vlink G[], int visited[], int n) {
    /**
     * 应该是默认赋值0
     * */
    for (int i = 0; i < n; ++i) {
        visited[i] = 0;
    }
    for (int j = 0; j < n; ++j) {
        if (visited[j] != 1) {
            DFS(G, visited, n);
        }

    }

}


/**
 * 广度优先
 * 搜索
 * */
void Traverl_BFS(Vlink G[], int visited[], int n) {
    /**
    * 应该是默认赋值0
    * */
    LinkList queue = NULL;
    for (int i = 0; i < n; ++i) {
        visited[i] = 0;
    }
    for (int j = 0; j < n; ++j) {
        if (visited[j] != 1) {
            BFS(G, visited, n, queue);
        }

    }
}


void BFS(Vlink G[], int visited[], int v, LinkList queue) {
    Elink *elink = NULL;
    int w;
    visited[v] = 1; /**  访问之后将其置为*/
    printf("数据输出%d\n", G[v].data);/**  访问位置*/
    enqueue(&queue, v); /** 入栈*/
    while (!EmptyQ(queue)) {
        v = delqueue(&queue);

        /**
         * 先访问第一个邻接点
         * 可能会出现 没有邻连接点的情况
         * */
        if (G[v].link == NULL) {
            w = -1;
        } else {
            elink = G[v].link->next;
            w = elink->adjvex;
        }
        /**
         *
         * */
        while (w != -1) {
            if (visited[w] == 0) {
                visited[w] = 1; /**  访问之后将其置为*/
                printf("数据输出%d\n", G[w].data);/**  访问位置*/
                enqueue(&queue, w); /** 入队列*/
            }
            /**
             * 获取到下一个edge
             * */
            if (elink->next != NULL) {
                w = elink->adjvex;
            } else {
                w = -1;
                elink = elink->next;/** 传递变量循环*/
            }
        }

    }

}


void DFS(Vlink G[], int visited[], int v, LinkList stack) {
    int w;
    Elink *elink = NULL;
    Vlink *vlink = NULL;
    /**
     * 先压入一个v
     * */
    pushStack(&stack, v);
    while (!EmptyStack(stack)) {
        /**
         * 弹出,并访问数据
         * */
        w = popStack(&stack);
        printf("数据输出%d\n", G[w].data);
        visited[w] = 1;

        /**
         * 遍历出没有被访问的节点
         * */
        elink = G[w].link;
        while (elink != NULL) {
            int i = elink->adjvex;
            if (visited[i] == 0) {
                /**
                 * 如果没有访问过
                 * 压栈进入
                 * */
                pushStack(&stack, i);
                elink == NULL;
            } else {
                elink = elink->next;
            }
        }


    }
}

