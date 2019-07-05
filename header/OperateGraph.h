/**
  * Created by wqj on 2019/6/26.
  * description:
 */

#ifndef ARITHMETIC_BASE_OPERATEGRAPH_H
#define ARITHMETIC_BASE_OPERATEGRAPH_H

#endif //ARITHMETIC_BASE_OPERATEGRAPH_H

#include <stdio.h>

#define MAXNUMB 5

#define  VNUM 5

#define  MV 65536
typedef struct edge {
    int adjvex;             /** 指向头结点的下标*/
    int weight;            /** 权值*/
    struct edge *next; /** 指向下一个边节点*/
} Elink;

typedef struct ver {
    int data;    /** 数据存储区域*/
    Elink *link; /** 指向第一条边 */
} Vlink;


typedef struct verL {
    int data;    /** 数据存储区域*/
    struct verL *link; /** 指向第一条边 */
} LinkNode, *LinkList;
#define Max 10

void Traverl_DFS(Vlink G[], int visited[], int n);

void DFS(Vlink G[], int visited[], int v, LinkList stack);

void Traverl_BFS(Vlink G[], int visited[], int n);

void BFS(Vlink G[], int visited[], int v, LinkList queue);


int MINDIST(int s, int dist);

int WEARCH_VCR(int s,int dist[],int u);

void enqueue(LinkList *queue, int vlink);

int delqueue(LinkList *queue);

int EmptyQ(LinkList queue);

void pushStack(LinkList *queue, int vlink);

int popStack(LinkList *queue);

int readStack(LinkList *queue);

int EmptyStack(LinkList queue);