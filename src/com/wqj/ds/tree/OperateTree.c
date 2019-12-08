/**
  * Created by wqj on 2019/5/30.
  * description:
 */
#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include "OperateTree.h"


int main(int argc, char *argv[]) {

    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8};

    int *arr2 = (int *) malloc(sizeof(int) * 10);
    for (int i = 0; i < 10; ++i) {
        arr2[i] = i;
    }
    int arr3[100] = {0};
    BiTree tree = createBinTree(arr, 8);
    int a = Treedeep(tree);
    int b = hierarchyNumber(tree, 2, NULL);
    int c = hierarchyNumber2(tree, 2);

    /**
     * 测试遍历
     *
     * */
    printf("\n前序:\n");
    preOrder(tree);
    printf("\n前序2:\n");
    preOrder2(tree);
    printf("\n中序:\n");
    inOrder(tree);
    printf("\n中序2:\n");
    inOrder2(tree);
    printf("\n后序:\n");
    backOrder(tree);
    printf("\n后序2:\n");
    backOrder2(tree);
    printf("\n后序3:\n");
    postOrder3(tree);

    printf("\n\n一下为创建广义二叉树表:\n\n\n\n");
    char generalizedList[] = "1(2(3),4(5(,6),7))@";
    BiTree generaliz_tree = createGeneralizedTree(generalizedList);


    levelOrder(generaliz_tree);

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
BiTree createBinTree(int *value, int n) {

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
    BiNode *tree = (BiNode *) malloc(sizeof(BiNode) * n);
    for (int i = 0; i < n; ++i) {

        tree[i].data = value[i];
        tree[i].left = NULL;
        tree[i].right = NULL;
    }
    for (int j = 0; j <= n / 2 - 1; ++j) {
        if (2 * j + 1 <= n - 1) {
            tree[j].left = &tree[2 * j + 1];
        }
        if (2 * j + 2 <= n - 1) {
            tree[j].right = &tree[2 * j + 2];
        }
    }

    return tree;
}

/**
   * 对于完全二叉树
   * 遍历出深度
   * */
int Treedeep(BiTree tree) {
    if (NULL == tree) {
        return 0;
    } else {
        int lh = Treedeep(tree->left);
        int rh = Treedeep(tree->right);
        return (lh > rh) ? (lh + 1) : (rh + 1);
    }
}


int Treedeep2(BiTree tree) {
    if (NULL == tree) {
        return 0;
    } else {
        int lh = Treedeep(tree->left);
        int rh = Treedeep(tree->right);
        return (lh > rh) ? (lh + 1) : (rh + 1);
    }
}

int hierarchyNumber(BiTree tree, int level, int *num) {
    if (num == NULL) {
        int t = 0;
        num = &t;
    }
    if (tree == NULL) {
        return 0;
    }
    if (level == 1) {
        (*num)++;
    }
    hierarchyNumber(tree->right, level - 1, num);
    hierarchyNumber(tree->left, level - 1, num);
    return *num;
}

int hierarchyNumber2(BiTree tree, int level) {
    /**
     * 初始化当前节点个数，及下一行节点个数
     * 根节点所在层数为1
     * */
    int curcount = 1, nextcount = 0, count = 1;
    LinkList list = NULL;
    BiTree temp;
    enqueue(&list, tree);
    while (list != NULL) {
        temp = dequeue(&list);
        curcount--;
        if (temp->right != NULL) {
            enqueue(&list, temp->right);
            nextcount++;
        }
        if (temp->left != NULL) {
            enqueue(&list, temp->left);
            nextcount++;
        }
        if (curcount == 0) {
            count++;
            if (level == count) {
                return nextcount;
            }
            /**
             * 记录下一层需要
             * 先遍历的数据个数
             * */
            curcount = nextcount;
            nextcount = 0;
        }
    }
    return 0;
}

/**
 * 计算非空二叉树(顺序存储) 深度为h
 * 叶子结点的数量
 * */
int leaf1(BiTree *tree, int h) {
    int count = 0;
    /**
     * pow(2,h)-1 代表有
     * 深度为h,那么他的树节点个数
     * 2的吃方-1
     * */
    for (int i = 0; i < pow(2, h) - 1; ++i) {
        if (tree[i] != NULL && (tree[i])->left == NULL && tree[i]->right == NULL) {
            count++;
        }
    }
}

/**
 * 使用递归算法
 * */
int leaf2(BiTree tree) {
    int count = 0;
    /**
     * pow(2,h)-1 代表有
     * 深度为h,那么他的树节点个数
     * 2的吃方-1
     * */
    if (tree == NULL)

        if (tree->data != -1 && tree->left == NULL && tree->right == NULL) {
            return 1;
        } else {
            return leaf2(tree->right) + leaf2(tree->left);
        }

}


/**
 * 使用广义表
 * 构建二叉树
 * **/
BiTree createGeneralizedTree(char *tree) {

    BiTree T = NULL, pre, temp;
    LinkList stack = NULL;
    int flag = 0;
    while (*tree != '@') {
        switch (*tree) {
            case '(':
                /**
                 * 入栈
                 * */
                pushSTACK(&stack, pre);
                flag = 0;
                break;
            case ')':
                popSTACK(&stack);
                break;
            case ',':
                flag = 1;
                break;
            default:
                /**
                 * 判断根节点
                 * 是否存在
                 * */
                temp = (BiTree) malloc(sizeof(BiNode));
                temp->data = *tree - '0';
                temp->left = NULL;
                temp->right = NULL;
                pre = temp;
                if (T == NULL) {
                    T = temp;
                    stack = (LinkList) malloc(sizeof(LinkNode));
                    pushSTACK(&stack, pre);
                } else {
                    if (flag) {
                        readSTACK(stack)->right = temp;
                    } else {
                        readSTACK(stack)->left = temp;
                    }
                }
                break;

        }

        tree++;
    }
    return T;
}


int enqueue(LinkList *list, BiTree value) {
    LinkList temp2 = (LinkList) malloc(sizeof(LinkNode));
    temp2->next = NULL;
    temp2->data = value;
    if (*list == NULL) {
        *list = temp2;
    } else {
        /**
         * 循环渠道最后一个节点
         * */
        LinkList temp;
        temp = *list;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = temp2;
    }
}

BiTree dequeue(LinkList *list) {
    BiTree temp = (*list)->data;
    (*list) = (*list)->next;
    return temp;
}

void pushSTACK(LinkList *stack, BiTree treeNode) {
    LinkList temp = (LinkList) malloc(sizeof(LinkNode));
    temp->data = treeNode;
    temp->next = (*stack);
    *stack = temp;
}


BiTree popSTACK(LinkList *stack) {
    BiTree tree = (*stack)->data;
    (*stack) = (*stack)->next;
    return tree;
}

BiTree readSTACK(LinkList stack) {
    BiTree tree = stack->data;
    return tree;
}
