/**
  * Created by wqj on 2019/5/9.
  * description:
 */
#include <stdio.h>
#include <malloc.h>

typedef struct node {
    char data;
    struct node *link;
} LNode, *LinkList;

LinkList createLink(int n);

LinkList insertLink(int num, char Item, LinkList list);

int main(int argc, char *argv[]) {
    /**
     * 创建内存LinkList
     * */
    LinkList a = createLink(2);
    /**
     * 在linklist前插入一个item
     * */
    LinkList b = insertLink(2, 'c', a);
    printf("");
}

LinkList createLink(int n) {
    LinkList p, r, list = NULL;
    for (int i = 1; i <= n; ++i) {
        p = (LinkList) malloc(sizeof(LNode));
        p->data = i;
        p->link = NULL;
        if (list == NULL) {
            list = p;
        } else {
            list->link = p;
        }
//        r = p;
    }
    return list;

}


LinkList insertLink(int num, char Item, LinkList list) {
    LinkList pre, new, temp;
    temp = list;
    for (int i = 1; i <= num; i++) {
        new = (LinkList) malloc(sizeof(LNode));
        new->data = Item;
        pre = temp;
        //第一个位置
        if (num - 1 == 0) {
            new->link = list;
            list = new;
        }
        //中间位置
        if (i == num - 1) {
            new->link = temp->link;//list不带参数指的是地址
            pre->link = new;
        } else {
            temp = temp->link;
        }
        //末尾


    }

    return list;
}


