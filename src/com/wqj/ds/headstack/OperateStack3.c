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





void INITIAL(LinkList top);

int isEMPTYS(LinkList top);

int PUSHLINK(LinkList topss, char item);

void test(int x, int z[], LinkList top);

int main(int argc, char *argv[]) {
    LinkList top, v, linklist = NULL;

    /**
     * linklist本身就是指针
     * */
    linklist = *createlinkList(3);


    v = (LinkList) malloc(sizeof(LNode));
    top = (LinkList) malloc(sizeof(LNode));
    char z11;
    printf("这是:%c\n", z11);
    v->data = 0;
    v->link = NULL;
    INITIAL(top);

    PUSHLINK(top, 'c');
    PUSHLINK(top, 'z');

    int x = 1;
    int z[1] = {1};
    test(x, z, v);

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



void INITIAL(LinkList top) {
    top = NULL;
}

int isEMPTYS(LinkList top) {
    top == NULL;
}

int PUSHLINK(LinkList topss, char item) {
    LinkList temp;
    temp = (LinkList) malloc(sizeof(LNode));
    temp->data = item;
    temp->link = topss;
    topss = temp;
    return 1;
}

void test(int x, int z[], LinkList top) {
    x = 8;
    z[0] = 8;
    top->data = '8';
}

