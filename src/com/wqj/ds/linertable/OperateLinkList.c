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

int linkListLen(LinkList list);

int deleteLinkByItem(char item, LinkList list);

LinkList createCirculationLink(int n);

LinkList reverseLink(LinkList list);

void printfLastKItem(LinkList list, int K);

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

    deleteLinkByItem(3, a);
    printf("长度:%d\n", linkListLen(a));

    LinkList e = createCirculationLink(7);
    printf("循环长度:%d\n", linkListLen(e));

    LinkList f = reverseLink(a);
    printfLastKItem(f, 1);

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

/**
 *  创建
 * 循环
 * 的list
 * */
LinkList createCirculationLink(int n) {
    LinkList list = NULL, p, pre;
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
    pre->link = list;
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
    for (int i = 1; i <= num - 1; ++i) {
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
    } while (nexttemp != NULL);
    return -1;

}


int linkListLen(LinkList list) {
    LinkList p = list;
    int len = 0;
    do {
        len++;
        p = p->link;
    } while ((p != NULL) && (p != list));
    return len;
}


LinkList reverseLink(LinkList list) {
    LinkList pre = NULL, next = NULL;
    while (list != NULL) {
        pre = list->link;//记录当前节点的写一个节点地址
        list->link = next;//当前节点指向下一个节点
        next = list;//next记录当前节点,给下一个节点用
        list = pre;//移动到下一个节点
    }
//    list = next;
    return next;
}

/**
 * 打印最后
 * K个元素
 * */
void printfLastKItem(LinkList list, int K) {
    LinkList pre = list, next = list;
    int i = 0;
    while (pre != NULL) {
        pre = pre->link;
        if (++i > K) {
            next = next->link;
        }

    }
    while (next != NULL) {
        printf("反转:%c\n", next->data);
        next = next->link;
    }
}