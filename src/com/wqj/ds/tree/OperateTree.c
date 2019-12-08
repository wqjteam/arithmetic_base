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
     * ���Ա���
     *
     * */
    printf("\nǰ��:\n");
    preOrder(tree);
    printf("\nǰ��2:\n");
    preOrder2(tree);
    printf("\n����:\n");
    inOrder(tree);
    printf("\n����2:\n");
    inOrder2(tree);
    printf("\n����:\n");
    backOrder(tree);
    printf("\n����2:\n");
    backOrder2(tree);
    printf("\n����3:\n");
    postOrder3(tree);

    printf("\n\nһ��Ϊ���������������:\n\n\n\n");
    char generalizedList[] = "1(2(3),4(5(,6),7))@";
    BiTree generaliz_tree = createGeneralizedTree(generalizedList);


    levelOrder(generaliz_tree);

}


/**
 * ��ȫ������
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
 * ���޵��д���һ����ȫtree
 * */
BiTree createBinTree(int *value, int n) {

    /**
     * ������,��������,������ұ�
     *
     * */
    if (n < 1) {
        return 0;
    }
    /**
     * �ȴ���root�ڵ�
     * */
//    initRootTree(tree, value[0]);
    /**
     * �ȵó��������
     * Ȼ���жϸò��
     * �ڵ��Ƿ�ﵽ�����
     * */
//    int deep = Treedeep(tree);

    /**
     * �������㹻���ڴ�,
     * �����ȫ������
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
   * ������ȫ������
   * ���������
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
     * ��ʼ����ǰ�ڵ����������һ�нڵ����
     * ���ڵ����ڲ���Ϊ1
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
             * ��¼��һ����Ҫ
             * �ȱ��������ݸ���
             * */
            curcount = nextcount;
            nextcount = 0;
        }
    }
    return 0;
}

/**
 * ����ǿն�����(˳��洢) ���Ϊh
 * Ҷ�ӽ�������
 * */
int leaf1(BiTree *tree, int h) {
    int count = 0;
    /**
     * pow(2,h)-1 ������
     * ���Ϊh,��ô�������ڵ����
     * 2�ĳԷ�-1
     * */
    for (int i = 0; i < pow(2, h) - 1; ++i) {
        if (tree[i] != NULL && (tree[i])->left == NULL && tree[i]->right == NULL) {
            count++;
        }
    }
}

/**
 * ʹ�õݹ��㷨
 * */
int leaf2(BiTree tree) {
    int count = 0;
    /**
     * pow(2,h)-1 ������
     * ���Ϊh,��ô�������ڵ����
     * 2�ĳԷ�-1
     * */
    if (tree == NULL)

        if (tree->data != -1 && tree->left == NULL && tree->right == NULL) {
            return 1;
        } else {
            return leaf2(tree->right) + leaf2(tree->left);
        }

}


/**
 * ʹ�ù����
 * ����������
 * **/
BiTree createGeneralizedTree(char *tree) {

    BiTree T = NULL, pre, temp;
    LinkList stack = NULL;
    int flag = 0;
    while (*tree != '@') {
        switch (*tree) {
            case '(':
                /**
                 * ��ջ
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
                 * �жϸ��ڵ�
                 * �Ƿ����
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
         * ѭ���������һ���ڵ�
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
