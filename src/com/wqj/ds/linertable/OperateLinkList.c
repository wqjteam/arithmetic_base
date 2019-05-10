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
     * �����ڴ�LinkList
     * */
    LinkList a = createLink(4);
    /**
     * ��linklistǰ����һ��item
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
        //��һ��λ��
        if (num - 1 == 0) {
            new->link = list;
            list = new;
        }
        //�м�λ��
        if (i == num - 1) {
            new->link = temp->link;//list��������ָ���ǵ�ַ
            pre->link = new;
        } else {
            temp = temp->link;
        }
        //ĩβ


    }

    return list;
}


LinkList deleteLink(int num, LinkList list) {
    /**
     * ��λ��λ��
     * */
    LinkList pretemp, nexttemp;
    pretemp = list;
    nexttemp = list;
    //��ȡ����Ҫɾ��������
    for (int i = 1; i <= num-1; ++i) {
        pretemp = nexttemp;
        nexttemp = nexttemp->link;
    }
    pretemp->link = nexttemp->link;
    return list;

}

int deleteLinkByItem(char item, LinkList list) {
    /**
     * ��λ��λ��
     * */
    LinkList pretemp, nexttemp;
    pretemp = list;
    nexttemp = list;
    //��ȡ����Ҫɾ��������
    do {
        /**
         * ���������node
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




