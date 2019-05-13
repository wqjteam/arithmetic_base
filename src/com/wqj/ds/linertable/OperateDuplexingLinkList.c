/**
  * Created by wqj on 2019/5/13.
  * description:双向列表
 */
#include <stdio.h>
#include <malloc.h>

typedef struct node2 {
    char data;
    struct node2 *rlink, *llink;
} DNode, *DLinkList;

DLinkList createDLinkList(int n, int flag);

DLinkList insertItem(DLinkList list, char base, char new);

DLinkList deleteItem(DLinkList list, char base);

int main(int argc, char *argv[]) {
    //第一个参数是链表的长度,第二个参数是是否为循环
    DLinkList list = createDLinkList(5, 1);

    //插入邮编的一个数据
    insertItem(list, 5, 'a');

    //删除数据
    deleteItem(list, 5);
}

DLinkList createDLinkList(int n, int flag) {
    DLinkList list = NULL, pre, p;
    for (int i = 1; i <= n; ++i) {
        p = (DLinkList) malloc(sizeof(DNode));
        p->data = i;
        p->rlink = NULL;
        p->llink = NULL;
        if (list == NULL) {
            list = p;
            pre = list;
        } else {
            p->rlink = pre;
            pre->llink = p;
            pre = p;
        }
    }
    /**
     * 不等于0 则为true,循环的链表
     * */
    if (flag != 0) {
        list->rlink = pre;
        pre->llink = list;
    }
    return list;
}

/**
 * 双向列表
 * 插入数据
 * */
DLinkList insertItem(DLinkList list, char base, char new) {
    DLinkList temp, p;
    temp = list;
    do {
        if (temp->data == base) {
            p = (DLinkList) malloc(sizeof(DNode));
            p->data = new;
            p->rlink = temp;
            p->llink = temp->llink;
            temp->llink = p;
            /**
             * 判断是否是最后一个节点
             * */
            if (p->llink != NULL) {
                p->llink->rlink = p;
            }
        }
        temp = temp->llink;
    } while (temp != NULL && temp != list);
    return list;
};

DLinkList deleteItem(DLinkList list, char base) {
    DLinkList temp;
    temp = list;
    do {
        if (temp->data == base) {
            temp->rlink->llink = temp->llink;
            temp->llink->rlink = temp->rlink;
            free(temp);
        }
        temp = temp->llink;
    } while (temp != NULL && temp != list);
}