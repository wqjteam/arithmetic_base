/**
  * Created by wqj on 2019/6/4.
  * description:
 */
#include <stdio.h>
#include <OperateTree.h>

/**
 * ���������
? ? ? ? ��1���ȷ��ʸ��ڵ㡣
? ? ? ? ��2���ٷ�����������
? ? ? ? ��3����������������
    ���������
? ? ? ? ��1���ȷ�����������
? ? ? ? ��2���ٷ��ʸ��ڵ㡣
? ? ? ? ��3����������������
    ���������
? ? ? ? ��1���ȷ�����������
? ? ? ? ��2���ٷ�����������
? ? ? ? ��3�������ʸ��ڵ�

 * */
void preOrder(BiTree tree) {
    if (tree != NULL) {
        printf("%d,", tree->data);
        preOrder(tree->left);
        preOrder(tree->right);
    }

}

void inOrder(BiTree tree) {
    if (tree != NULL) {
        inOrder(tree->left);
        printf("%d,", tree->data);
        inOrder(tree->right);
    }
}

void backOrder(BiTree tree) {
    if (tree != NULL) {
        backOrder(tree->left);
        backOrder(tree->right);
        printf("%d,", tree->data);
    }
}


void levelOrder(BiTree tree) {
    LinkList queue = NULL;
    BiTree temp = NULL;
    enqueue(&queue, tree);
    int num = 1, level = 1, nextlevelnum = 0;
    while (num != 0) {
        temp = dequeue(&queue);
        printf("(����:%d:����:%d\n)", level, temp->data);
        /**
         * �����ҽڵ㶼����
         * ������
         * */
        if (temp->left != NULL) {
            enqueue(&queue, temp->left);
            nextlevelnum++;
        }
        if (temp->right != NULL) {
            enqueue(&queue, temp->right);
            nextlevelnum++;
        }
        num--;

        /**
         * ��� num=0,����¼���ӽڵ�
         * ֵ����num,һ��һ�����
         * */
        if (num == 0 && nextlevelnum != 0) {
            level++;
            num = nextlevelnum;
            nextlevelnum = 0;
        }
    }
}

/**
 *�����ӽڵ����õ����ڵ�
 * ���ʵ�ǰ�ڵ�(ͬʱ��ջ)
 * ��ȡ����ڵ�left 1. ��Ϊ�� : �����ӽڵ����õ�left��(������whileѭ��)
 *                  2. Ϊ��   : ��ջ�ڵ�temp,�����ӽڵ����õ�temp��right��(�����������ѭ��)
 * */
void preOrder2(BiTree tree) {
    LinkList stack = NULL;
    BiTree temp = NULL;
    int top = -1;
    while (tree != NULL || top >= 0) {
        while (tree != NULL) {
            printf("%d,", tree->data);
            pushSTACK(&stack, tree);
            top++;
            tree = tree->left;
        }
        if (top >= 0) {
            /**
             * ��ջ
             * */
            temp = popSTACK(&stack);
            top--;
            tree = temp->right;
        }
    }

}


/**
 *
 *�Ӷ��������ڵ㿪ʼ,�����ڵ���ջ
 * ��ָ��ڵ���������ڵ�
 * ������ڵ� 1 �����Ϊ�� : ����ڵ����ջ��(һֱѭ�������һ��)
 *            2 ���Ϊ��   : ��ջ�����,�����ӽڵ�ָ���ҽڵ�(����ѭ��Ѱ����ڵ�)
 *ֱ��ջ���޽ڵ�
 * */
void inOrder2(BiTree tree) {
    LinkList stack = NULL;
    BiTree temp = NULL;
    int top = -1;
    while (top >= 0 || tree != NULL) {
        while (tree != NULL) {
            pushSTACK(&stack, tree);
            top++;
            tree = tree->left;
        }
        if (top >= 0) {
            temp = popSTACK(&stack);
            top--;
            printf("%d,", temp->data);
            tree = temp->right;
        }
    }

}


/**
 * �������Ҫ��������������ɺ�Ŷ�������з���
 * �Ƚ��������������ڣ���ջ�ٽ��������������ڣ���ջ��Ȼ��ָ�����ӣ����������ӣ�����ָ���Һ��ӣ�
 * �ڶ�������ֽ�㹹�ɵ�ջ���г�ջ����ʱ,Ӧ��ע�⵽�����ص㡣
 * ��һ��Ҷ��㣬��������������Ϊ�գ�������ѭ��ʱ����ջ���Ƴ���
 * �ڶ�����һ����ջ�󣬿�������ջ�����Ĺ�ϵ������˫�׹�ϵ����˵����һ������ڸý��������Ҳ���Է��ʣ�ֱ�ӳ�ջ���ɡ�
 * ������˫�׹�ϵ������һ�����Ӧ���뱾�ο�ͷ��˵��ѭ�����йؽ�������ջ
 *
 * */
void backOrder2(BiTree tree) {
    LinkList stack = NULL;
    /**
     * preTree�����ж��Ƿ񵯳�
     * ���ڵ�
     * */
    BiTree temp = NULL, preTree;
    /**
   * ������־����
   * ����������������
   * 0:������
   * 1:������
   * */
    int top = 0, flag;
    while (top > 0 || tree != NULL) {
        /**
         * һֱȡ������ѹջ
         * */
        while (tree != NULL) {
            pushSTACK(&stack, tree);
            top++;
            tree = tree->left;
        }
        preTree = NULL;
        flag = 0;
        while (top > 0 && flag == 0) {
            temp = readSTACK(stack);
            /**
             * ��һ���ж��Ƿ����ҽڵ�
             * �ڶ����ж��Ƿ�����ϴ��ֽڵ�
             * ��������ҽڵ�,�϶��Ǹ��ڵ�
             * */
            if (temp->right == preTree) {
                /**
                 * ��ȡstack�е�����,
                 * ��ӡ
                 * */
                printf("%d,", temp->data);
                popSTACK(&stack);
                top--;
                preTree = temp;
            } else {
                /**
                 * ������ҽڵ�
                 * �������ڵ�ѹջ,Ѱ����ڵ�
                 * */
                tree = temp->right;
                /**
                 * ֤����������
                 * */
                flag = 1;
            }
        }
    }
}

void postOrder3(BiTree T) {
    BiTree tree = T, temp, stack1[1000];
    int stack2[1000];
    int top = -1, flag;
    while (tree != NULL || top >= 0) {
        while (tree != NULL) {
            stack1[++top] = tree;
            stack2[top] = 0;
            tree = tree->left;
        }
        if (top >= 0) {
            tree = stack1[top];
            flag = stack2[top--];
            if (flag == 0) {
                stack1[++top] = tree;
                stack2[top] = 1;
                tree = tree->right;
            } else {
                printf("%d,", tree->data);
                tree = NULL;
            }
        }
    }
}

/**
 * ��ȫ������˳��洢���������
 * */
void inorder3(BiTree *trees, int n) {
    BiTree head = NULL, temp = NULL;
    int top = -1, i = 0, STACK[100];
    if (n >= 0) {
        do {
            /**
             * ����trees[i] != NULL�Ϳ���ִ��һ�������
             * */
            while (i < n && trees[i] != NULL) {
                STACK[++top] = i; /**BiTree��λ��i��ջ*/
                i = i * 2 + 1;    /**�ҵ�I�����ӵ�λ��*/
            }
            i = STACK[top--]; /**��ջ*/
            printf("%d,", trees[i]);
            i = i * 2 + 2;     /**�ҵ��Һ��ӵ�λ��*/
        } while (!(i > n - 1 && top == -1));
    }
}


/**
 * ˳��洢�ĺ������
 * */
void postorder3(BiTree *trees, int n) {

}
