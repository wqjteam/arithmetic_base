/**
  * Created by wqj on 2019/6/4.
  * description:
 */
#include <stdio.h>
#include <OperateTree.h>
/**
 * 先序遍历：
        （1）先访问根节点。
        （2）再访问左子树。
        （3）最后访问右子树。
    中序遍历：
        （1）先访问左子树。
        （2）再访问根节点。
        （3）最后访问右子树。
    后序遍历：
        （1）先访问左子树。
        （2）再访问右子树。
        （3）最后访问根节点

 * */
void preOrder(BiTree tree){
    if(tree!=NULL){
        printf("%d,",tree->data);
        preOrder(tree->left);
        preOrder(tree->right);
    }

}

void inOrder(BiTree tree){
    if(tree!=NULL){
    inOrder(tree->left);
    printf("%d,",tree->data);
    inOrder(tree->right);
    }
}

void backOrder(BiTree tree){
if(tree!=NULL){
    backOrder(tree->left);
    backOrder(tree->right);
    printf("%d,",tree->data);
}
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

