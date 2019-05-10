/**
  * Created by wqj on 2019/5/9.
  * description:
 */
#include <stdio.h>
#include <malloc.h>
#include <mem.h>

typedef struct node {
    char data;
    struct node *link;
} LNode, *LinkList;

LinkList createLink(int n);

LinkList insertLink(int num, char Item, LinkList list);

LinkList deleteLink(int num, LinkList list);

int deleteLinkByItem(char item, LinkList list);

int main(int argc, char *argv[]) {
    /**
     * 创建内存LinkList
     * */
    LinkList a = createLink(4);
    /**
     * 在linklist前插入一个item
     * */
    LinkList b = insertLink(3, 'c', a);
//    printf("");

    LinkList c = deleteLink(3, a);
//    printf("%s", c);

    deleteLinkByItem('3', a);
    printf("");
}

LinkList createLink(int n) {
    LinkList p, pre, list = NULL;
    for (int i = 1; i <= n; ++i) {
        p = (LinkList) malloc(sizeof(LNode));
        p->data = i;
        p->link = NULL;
        if (list == NULL) {
            list = p;
            pre = list;
        } else {
            pre->link = p;
            pre = p;
        }
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


LinkList deleteLink(int num, LinkList list) {
    /**
     * 定位出位置
     * */
    LinkList pretemp, nexttemp;
    pretemp = list;
    nexttemp = list;
    //获取到需要删除的数据
    for (int i = 1; i <= num-1; ++i) {
        pretemp = nexttemp;
        nexttemp = nexttemp->link;
    }
    pretemp->link = nexttemp->link;
    return list;

}

int deleteLinkByItem(char item, LinkList list) {
    /**
     * 定位出位置
     * */
    LinkList pretemp, nexttemp;
    pretemp = list;
    nexttemp = list;
    //获取到需要删除的数据
    do {
        /**
         * 遍历出相等node
         * */
        if (nexttemp->data == item) {
            pretemp->link = nexttemp->link;
            return 1;
        }
        pretemp = nexttemp;
        nexttemp = nexttemp->link;
    } while (nexttemp == NULL);
    return -1;

}




