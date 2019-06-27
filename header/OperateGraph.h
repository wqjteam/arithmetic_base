/**
  * Created by wqj on 2019/6/26.
  * description:
 */

#ifndef ARITHMETIC_BASE_OPERATEGRAPH_H
#define ARITHMETIC_BASE_OPERATEGRAPH_H

#endif //ARITHMETIC_BASE_OPERATEGRAPH_H

#include <stdio.h>

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
    Vlink data;    /** 数据存储区域*/
    struct verL *link; /** 指向第一条边 */
} verLnode,*verList;
#define Max 10

void Traverl_DFS(Vlink G[], int visited[], int n);

void DFS(Vlink G[], int visited[], int v);

void Traverl_BFS(Vlink G[], int visited[], int n);

void BFS(Vlink G[], int visited[], int v);

void enqueue(verList *queue, Vlink vlink);

Vlink delqueue(verList *queue);