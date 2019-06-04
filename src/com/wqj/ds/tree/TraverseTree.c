/**
  * Created by wqj on 2019/6/4.
  * description:
 */
#include <stdio.h>
#include "OperateTree.c"

int preOrder(BiTree tree){
    printf("%d,",tree->data);
    preOrder(tree->left);
    preOrder(tree->right);
}

int inOrder(BiTree tree){
    preOrder(tree->left);
    printf("%d,",tree->data);
    preOrder(tree->right);
}

int backOrder(BiTree tree){
    preOrder(tree->left);
    preOrder(tree->left);
    printf("%d,",tree->data);
}

int preOrder2(BiTree tree){
    printf("%d,",tree->data);
    preOrder(tree->left);
    preOrder(tree->right);
}

int inOrder2(BiTree tree){
    preOrder(tree->left);
    printf("%d,",tree->data);
    preOrder(tree->right);
}

int backOrder2(BiTree tree){
    preOrder(tree->left);
    preOrder(tree->left);
    printf("%d,",tree->data);
}

