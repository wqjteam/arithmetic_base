/**
  * Created by wqj on 2019/5/30.
  * description:
 */
#include <stdio.h>
#include <malloc.h>

/**
 *
 * */
typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} BiNode, *BiTree;

typedef struct TreeNodeLocal {
    struct TreeNode *address;
    int local;
} STACK;

int Treedeep(BiTree *tree);

int initRootTree(BiTree *tree, int value);

int createBinTree(int *value, int n);

int main(int argc, char *argv[]) {


}


/**
 * 完全二叉树
 *
 * */
int initRootTree(BiTree *tree, int value) {
    BiTree temp;
    temp = (BiTree) malloc(sizeof(BiNode));
    temp->data = value;
    if (*tree == NULL) {
        *tree = temp;
    }
    return 1;
}

/**
 * 从无到有创建一个完全tree
 * */
int createBinTree(int *value, int n) {

    /**
     * 不排序,先填充左边,再填充右边
     *
     * */
    if (n < 1) {
        return 0;
    }
    /**
     * 先创建root节点
     * */
//    initRootTree(tree, value[0]);
    /**
     * 先得出树的深度
     * 然后判断该层的
     * 节点是否达到最大数
     * */
//    int deep = Treedeep(tree);

    /**
     * 先申请足够的内存,
     * 存放完全二叉树
     * */
    BiTree *tree = (BiTree) malloc(sizeof(BiNode) * n);
    for (int i = 0; i < n; ++i) {
        tree[i]->data = value[i];
        tree[i]->left = NULL;
        tree[i]->right = NULL;
    }
    for (int j = 0; j <= n / 2 - 1; ++j) {
        if (2 * j + 1 <= n - 1) {
            tree[j]->left = tree[2 * j + 1];
        }
        if (2 * j + 2 <= n - 1) {
            tree[j]->right = tree[2 * j + 2];
        }
    }


}

/**
   * 对于完全二叉树
   * 遍历出深度
   * */
int Treedeep(BiTree *tree) {
    int count = 0;
    if ((*tree) == NULL) {
        return count;
    }
    BiTree temp;
    do {
        count++;
        temp = (*tree)->left;
    } while (temp != NULL);
    return count;
}

int hierarchyNumber(BiTree tree, int *ln) {
    BiTree temp;
    STACK *stack = (STACK *) malloc(sizeof(struct TreeNodeLocal) * 1000);
    int top = -1;
    temp = tree;
    while (tree != NULL) {
        if (temp->left != NULL) {
            stack[++top];
            stack[top].address = temp->left;
            stack[top].local = 0;
            temp = temp->left;
        } else if (temp->right != NULL) {
            stack[++top];
            stack[top].address = temp->right;
            stack[top].local = 1;
            temp = temp->right;
        } else if (temp->right == NULL && temp->left == NULL) {
            /**
             * levelnumber加一
             * */
            ln[top]++;
            temp = stack[--top].address;
        }
    }
}
