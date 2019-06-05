/**
  * Created by wqj on 2019/5/30.
  * description:
 */
#include <stdio.h>
#include <malloc.h>
#include "OperateTree.h"


int main(int argc, char *argv[]) {

    int arr[10] = {1, 2, 3, 4,5,6,7,8};

    int *arr2 = (int *) malloc(sizeof(int) * 10);
    for (int i = 0; i < 10; ++i) {
        arr2[i] = i;
    }
    int arr3[100] = {0};
    BiTree tree = createBinTree(arr, 8);
    int a=Treedeep(tree);
    int b=hierarchyNumber(tree, 2,NULL);
    int c=hierarchyNumber2(tree, 2);

    /**
     * ���Ա���
     *
     * */
     printf("ǰ��:\n");
    preOrder(tree);
    printf("\n����:\n");
    inOrder(tree);
    printf("\n����:\n");
    backOrder(tree);
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
        if(NULL==tree){
            return 0;
        }else{
            int lh=Treedeep(tree->left);
            int rh=Treedeep(tree->right);
            return (lh>rh)?(lh+1):(rh+1);
        }
}


int Treedeep2(BiTree tree) {
    if(NULL==tree){
        return 0;
    }else{
        int lh=Treedeep(tree->left);
        int rh=Treedeep(tree->right);
        return (lh>rh)?(lh+1):(rh+1);
    }
}

int hierarchyNumber(BiTree tree, int level,int *num) {
    if(num==NULL){
        int t=0;
        num=&t;
    }
    if(tree==NULL){
        return 0;
    }
    if(level==1){
        (*num)++;
    }
    hierarchyNumber(tree->right,level-1,num);
    hierarchyNumber(tree->left,level-1,num);
    return *num;
}

int hierarchyNumber2(BiTree tree, int level) {
    /**
     * ��ʼ����ǰ�ڵ����������һ�нڵ����
     * ���ڵ����ڲ���Ϊ1
     * */
    int curcount=1,nextcount=0,count=1;
    LinkList list=NULL;
    BiTree temp;
    enqueue(&list,tree);
    while(list!=NULL){
        temp=dequeue(&list);
        curcount--;
        if(temp->right!=NULL){
            enqueue(&list,temp->right);
            nextcount++;
        }
        if(temp->left!=NULL){
            enqueue(&list,temp->left);
            nextcount++;
        }
        if(curcount==0){
            count++;
            if(level==count){
              return  nextcount;
            }
            /**
             * ��¼��һ����Ҫ
             * �ȱ���������
             * */
            curcount=nextcount;
            nextcount=0;
        }
    }
    return 0;
}

int enqueue(LinkList *list,BiTree value){
    LinkList temp2=(LinkList)malloc(sizeof(LinkNode));
    temp2->next=NULL;
    temp2->data=value;
    if(*list==NULL){
        *list=temp2;
    }else{
        /**
         * ѭ���������һ���ڵ�
         * */
        LinkList temp;
        temp=*list;
     while(temp->next!=NULL){
         temp=temp->next;
     }
        temp->next=temp2;
    }
}

BiTree dequeue(LinkList *list){
    BiTree temp=(*list)->data;
    (*list)=(*list)->next;
    return temp;
}


