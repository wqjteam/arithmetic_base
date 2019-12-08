/**
  * Created by wqj on 2019/6/4.
  * description:
 */
#include <stdio.h>
#include <OperateTree.h>

/**
 * 先序遍历：
? ? ? ? （1）先访问根节点。
? ? ? ? （2）再访问左子树。
? ? ? ? （3）最后访问右子树。
    中序遍历：
? ? ? ? （1）先访问左子树。
? ? ? ? （2）再访问根节点。
? ? ? ? （3）最后访问右子树。
    后序遍历：
? ? ? ? （1）先访问左子树。
? ? ? ? （2）再访问右子树。
? ? ? ? （3）最后访问根节点

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
        printf("(层数:%d:数据:%d\n)", level, temp->data);
        /**
         * 将左右节点都放入
         * 队列中
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
         * 如果 num=0,将记录的子节点
         * 值赋给num,一层一层遍历
         * */
        if (num == 0 && nextlevelnum != 0) {
            level++;
            num = nextlevelnum;
            nextlevelnum = 0;
        }
    }
}

/**
 *将连接节点重置到根节点
 * 访问当前节点(同时入栈)
 * 并取出左节点left 1. 不为空 : 将链接节点重置到left上(继续走while循环)
 *                  2. 为空   : 弹栈节点temp,将链接节点重置到temp的right上(继续走上面的循环)
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
             * 弹栈
             * */
            temp = popSTACK(&stack);
            top--;
            tree = temp->right;
        }
    }

}


/**
 *
 *从二叉树根节点开始,将根节点入栈
 * 将指向节点关联到根节点
 * 访问左节点 1 如过不为空 : 将左节点加入栈中(一直循环到最后一个)
 *            2 如果为空   : 弹栈将输出,并连接节点指向右节点(继续循环寻找左节点)
 *直至栈中无节点
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
 * 后序遍历要求左右子树均完成后才对自身进行访问
 * 先将右子树（若存在）入栈再将左子树（若存在）入栈，然后指向左孩子（若存在左孩子，否则指向右孩子）
 * 在对这个部分结点构成的栈进行出栈操作时,应该注意到两个特点。
 * 第一、叶结点，他是左右子树均为空，而跳出循环时，从栈顶推出。
 * 第二、任一结点出栈后，考察他和栈顶结点的关系，若是双亲关系，则说明下一个结点在该结点访问完后也可以访问，直接出栈即可。
 * 若不是双亲关系，则下一个结点应进入本段开头所说的循环将有关结点持续入栈
 *
 * */
void backOrder2(BiTree tree) {
    LinkList stack = NULL;
    /**
     * preTree用于判断是否弹出
     * 根节点
     * */
    BiTree temp = NULL, preTree;
    /**
   * 用来标志是是
   * 左子树还是右子树
   * 0:左子树
   * 1:右子数
   * */
    int top = 0, flag;
    while (top > 0 || tree != NULL) {
        /**
         * 一直取左子树压栈
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
             * 第一次判断是否有右节点
             * 第二次判断是否等于上次又节点
             * 如果等于右节点,肯定是根节点
             * */
            if (temp->right == preTree) {
                /**
                 * 读取stack中的数据,
                 * 打印
                 * */
                printf("%d,", temp->data);
                popSTACK(&stack);
                top--;
                preTree = temp;
            } else {
                /**
                 * 如果有右节点
                 * 继续将节点压栈,寻找左节点
                 * */
                tree = temp->right;
                /**
                 * 证明是右子数
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
 * 完全二叉树顺序存储的中序遍历
 * */
void inorder3(BiTree *trees, int n) {
    BiTree head = NULL, temp = NULL;
    int top = -1, i = 0, STACK[100];
    if (n >= 0) {
        do {
            /**
             * 加上trees[i] != NULL就可以执行一般二叉树
             * */
            while (i < n && trees[i] != NULL) {
                STACK[++top] = i; /**BiTree的位置i进栈*/
                i = i * 2 + 1;    /**找到I的左孩子的位置*/
            }
            i = STACK[top--]; /**退栈*/
            printf("%d,", trees[i]);
            i = i * 2 + 2;     /**找到右孩子的位置*/
        } while (!(i > n - 1 && top == -1));
    }
}


/**
 * 顺序存储的后序遍历
 * */
void postorder3(BiTree *trees, int n) {

}
