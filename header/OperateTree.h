/**
  * Created by wqj on 2019/6/4.
  * description:
 */

//#ifndef ARITHMETIC_BASE_OPERATETREE_H
//#define ARITHMETIC_BASE_OPERATETREE_H
//
//#endif //ARITHMETIC_BASE_OPERATETREE_H
# include<stdio.h>
typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} BiNode, *BiTree;

typedef struct TreeNodeLocal {
    BiTree data;
    struct TreeNodeLocal *next;
} LinkNode,*LinkList;

int Treedeep(BiTree tree);

int initRootTree(BiTree *tree, int value);

BiTree createBinTree(int *value, int n);

int hierarchyNumber(BiTree tree, int level,int *num);

int hierarchyNumber2(BiTree tree, int level);

int enqueue(LinkList *list,BiTree value);

BiTree dequeue(LinkList *list);

void preOrder(BiTree tree);

void inOrder(BiTree tree);

void backOrder(BiTree tree);