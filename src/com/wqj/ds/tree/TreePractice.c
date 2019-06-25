#include <OperateTree.h>
#include <malloc.h>

/**
  * Created by wqj on 2019/6/21.
  * description:
 */


/**
 * 递归
 * 复制树
 * */
BiTree copyTree(BiTree T1) {
    BiTree T2;
    if (T1 == NULL) {
        return NULL;
    } else {
        T2 = (BiTree) malloc(sizeof(BiNode));
        T2->data = T1->data;
        T2->left = copyTree(T1->left);
        T2->right = copyTree(T1->right);
    }
    return T2;
}

BiTree preAndInToInsert(BiTree tree, int data, int num) {
    BiTree temp, deliver;
    temp = (BiTree) malloc(sizeof(BiNode));
    temp->right = NULL;
    temp->left = NULL;
    temp->data = data;
    temp->num = num;

    deliver = tree;
    if (tree == NULL) {
        tree = temp;
    } else {
        while (1) {
            /**
             * 不存在num相等的情况
             * */
            if (deliver->num > temp->num) {
                if (deliver->right == NULL) {
                    deliver->right = temp;
                    break;
                } else {
                    deliver = deliver->right;
                }
            } else {
                if (deliver->left == NULL) {
                    deliver->left = temp;
                    break;
                } else {
                    deliver = deliver->left;
                }
            }
        }
    }

}


/**
 * 判断二叉树
 * 是否是一个
 * 标准二叉树
 * */
int judgeSortBinTree(BiTree root) {
    BiTree deliver = root, temp;
    LinkList stack = NULL;
    int top = -1;
    while (deliver != NULL || top != -1) {
        while (deliver != NULL) {
            /**
             * 利用前序遍历
             * 作个判断
             *
             * */
            if (deliver->data > deliver->left->data || deliver->data < deliver->right->data) {
                return 0;
            }
            pushSTACK(&stack, deliver);
            top++;
            deliver = deliver->left;
        }
        if (top >= 0) {
            temp = popSTACK(&stack);
            deliver = temp->right;
        }
    }
    return 1;

}

