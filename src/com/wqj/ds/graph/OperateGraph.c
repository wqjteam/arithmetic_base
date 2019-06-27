/**
  * Created by wqj on 2019/6/26.
  * description:操作图
 */

#include <malloc.h>
#include "OperateGraph.h"

void main(int argc, char *argv[]) {

    Vlink vlink[10];


}

void enqueue(verList *queue, Vlink vlink) {
    verList deliver = *queue, temp = (verList) malloc(sizeof(verLnode));
    temp->link = NULL;
    if (*queue == NULL) {
        *queue = temp;
    } else {
        while (deliver->link != NULL) {
            deliver = deliver->link;
        }
        deliver->link = temp;
    }
}

Vlink delqueue(verList *queue) {
    if (*queue == NULL) {
//        return NULL;
    } else {
        Vlink result = (*queue)->data;
//        free()
        *queue = (*queue)->link;
        return result;
    }
}


