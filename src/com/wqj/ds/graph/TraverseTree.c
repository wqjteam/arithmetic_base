/**
  * Created by wqj on 2019/6/27.
  * description:
 */

#include <OperateGraph.h>


/**
 * 深度
 * 优先搜索
 * */
void Traverl_DFS(Vlink G[], int visited[], int n) {
    /**
     * 应该是默认赋值0
     * */
    for (int i = 0; i < n; ++i) {
        visited[i]=0;
    }
    for (int j = 0; j <n ; ++j) {
        if( visited[j]!=1){
            DFS(G,visited,n);
        }

    }

}


/**
 * 广度优先
 * 搜索
 * */
void Traverl_BFS(Vlink G[], int visited[], int n){
    /**
    * 应该是默认赋值0
    * */
    for (int i = 0; i < n; ++i) {
        visited[i]=0;
    }
    for (int j = 0; j <n ; ++j) {
        if( visited[j]!=1){
            BFS(G,visited,n);
        }

    }
}


void BFS(Vlink G[], int visited[], int v) {
    int w;
    visited[v]=1;
    printf("数据输出%d\n", G[v].data);

}







void DFS(Vlink G[], int visited[], int v) {

    int temp = 0;
    Vlink *vlink = NULL;
    Elink *elink = NULL;
    do {

        printf("数据输出%d\n", G[v].data);
        visited[v] = 1;
        elink = G[v].link->adjvex;
        int adjvex = elink->adjvex;
        do {
            if (visited[adjvex] == 0) {
                break;
            }
            /**
             * 判断下 ,面没有节点报错
             * */
            adjvex = elink->adjvex;

            elink = elink->next;

        } while (elink->next != NULL);
        /**
         *判断visited[local]中是否被访问
         * ,如果最终被访问 ,这证明这次都结束了
         * */
        if (visited[adjvex] == 0) {
            vlink = &G[adjvex];

        } else {
            vlink = NULL;
        }
    } while (vlink != NULL);


}