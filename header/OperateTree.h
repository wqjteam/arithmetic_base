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

/**
 * 用于队列和栈
 * */
typedef struct TreeNodeLocal {
    BiTree data;
    struct TreeNodeLocal *next;
} LinkNode, *LinkList;


int Treedeep(BiTree tree);

int initRootTree(BiTree *tree, int value);

BiTree createBinTree(int *value, int n);

int hierarchyNumber(BiTree tree, int level, int *num);

int hierarchyNumber2(BiTree tree, int level);

BiTree createGeneralizedTree(char *tree);



void preOrder(BiTree tree);

void inOrder(BiTree tree);

void backOrder(BiTree tree);

void levelOrder(BiTree tree);

void preOrder2(BiTree tree);

void inOrder2(BiTree tree);

void backOrder2(BiTree tree);










        int enqueue(LinkList *list, BiTree value);

BiTree dequeue(LinkList *list);

void pushSTACK(LinkList *stack, BiTree treeNode);

BiTree popSTACK(LinkList *stack);

BiTree readSTACK(LinkList stack);