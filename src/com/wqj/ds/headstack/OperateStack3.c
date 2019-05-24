/**
  * Created by wqj on 2019/5/22.
  * description:
 */
#include <stdio.h>
#include <malloc.h>


typedef struct node1 {
    char data;
    struct node1 *link;
} LNode, *LinkList;

LinkList *createlinkList(int length);

int INITIAL(LinkList *topxx);

int isEMPTYS(LinkList top);

int isEMPTYS(LNode *top);

int PUSHLINK(LinkList *topss, char item);

int POPLINK(LinkList *topss, char *item);

int main(int argc, char *argv[]) {
    LinkList top, v, linklist = NULL;
    /**
     * linklist本身就是指针
     * */
    linklist = *createlinkList(3);

    v = (LinkList) malloc(sizeof(LNode));
    top = (LinkList) malloc(sizeof(LNode));
    v->data = 0;
    v->link = NULL;

    PUSHLINK(&top, 'c');
    PUSHLINK(&top, 'z');

    char *item;
    char a = '0';
    item = &a;
    POPLINK(&top, item);

}

int INITIAL(LinkList *topxx) {
    *topxx = NULL;
    return 1;
}


int PUSHLINK(LinkList *topss, char item) {
    LinkList temp;
    temp = (LinkList) malloc(sizeof(LNode));
    temp->data = item;
    temp->link = *topss;
    *topss = temp;
    return 1;
}

int POPLINK(LinkList *topss, char *item) {
    *item = (*topss)->data;
    *topss = (*topss)->link;
    return 1;
}

int isEMPTYS(LinkList top) {
    top == NULL;
}

LinkList *createlinkList(int length) {
    LinkList temp, pre;
    LinkList static list = NULL;
    do {
        temp = (LinkList) malloc(sizeof(LNode));
        temp->link = NULL;
        temp->data = length;
        if (list == NULL) {
            list = temp;
            pre = list;
        }
        pre->link = temp;
        pre = temp;

    } while (--length > 0);
    return &list;
}

