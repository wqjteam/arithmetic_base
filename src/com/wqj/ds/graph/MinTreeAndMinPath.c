/**
  * Created by wqj on 2019/7/2.
  * description:
 */
#include <OperateGraph.h>
#include <malloc.h>


/**
 * 普里姆算法 适合求边树较多的数据 O(n^2)
 *
 * 还有另外一种 适合克鲁斯卡尔算法
 * */
void minspant_prim(int GE[][MAXNUMB], int n) {

    int lowcast[n], teend[n], mincost, k;
    for (int i = 0; i < n; ++i) {
        teend[i] = 0;
        /**  对辅助函数进行初始化,
         *
         * 默认所有节点依附1节点*/
        lowcast[i] = GE[0][i];
    }

    /**
     * 选择一条一端在U上,
     * 另一端在V-U上的所有边中的最小边(k,teend[k])
     * 需要取出n-1条边
     * */
    for (int j = 1; j < n; ++j) {
        mincost = MAXNUMB;
        for (int i = 1; i < n; ++i) {
            if (lowcast[i] > 0 && mincost > lowcast[i]) { /** lowcast[i]中查看是否被跟新过
                                                             * 标志定点加入U中(这里用print代替)*/
                mincost = lowcast[i];
                k = j;
            }
        }

        printf("(%d,%d)", teend[k], k); /**  输出最小树的一条边*/
        lowcast[k] = 0;                 /**  顶尖K加入到U中 */
        for (int l = 0; l < n; ++l) {   /**  更新lowcast[l] */
            if (GE[k][l] < lowcast[l]) {
                lowcast[l] = GE[k][l];
                teend[l] = k;
            }
        }
    }

}


void Dijkstra(int cost[][MAXNUMB], int v, int n, int dist[], int path[][MAXNUMB]) {
    int w, u, count, pos[n], s[MAXNUMB];
    for (int i = 0; i < n; ++i) {
        s[i] = 0;     /** 标记数组置为0*/
        dist[i] = cost[v][i]; /**  将邻接矩阵第V行元素依次送dist数组*/
        path[i][0] = v;       /** 源点v到个顶点的路径置为初值*/
        pos[i] = 0;           /** 第i条路径的位置计算器置为初值*/
    }

    s[v] = 1;
    count = 1;        /** 计算器赋值1*/

    while (count < n) {  /** 以下过程执行n-1次*/
        /** 利用s和dist在尚未找到最短路径的顶点中确定一个与V最近的顶点U */
        u = MINDIST(s, dist);
        s[u] = 1;     /** 置u的标记为1*/
        path[u][++pos[u]] = u;  /** 将U添加到从v到u的最短路径*/
        count++;                /** 极速器累加1*/
        while (1) {             /** 根据 U 跟新从 v到所有尚未确定的最短路径顶点的路径长度*/
            if ((w = WEARCH_VCR(s, dist, u) == -1)) {
                break;
            } else {
                if (dist[u] + cost[u][w] < dist[w]) {
                    dist[w] = dist[u] + cost[u][w];
                    for (int i = 0; i < pos[u]; ++i) {
                        path[w][i] = path[u][i];
                    }
                }
            }
        }
    }
}

int MINDIST(int s, int dist) {

}

int WEARCH_VCR(int s, int dist[], int u) {

}


void TOPO_SORT(Vlink G[], int n, int data[]) {

    Elink *p;
    int j, top = -1;
    /**
     * 堆栈初始化
     * */
    for (int i = 0; i < n; i++) {
        if (G[i].indegree == 0) {
            G[i].indegree = top;
            top = i;
        }
    }
    /**
     * 依次将入度为0的顶点压榨堆栈中
     * */
    for (int k = 0; k < n; ++k) {
        if (top == -1) {
            printf("\n网络中存在回路");
        } else {
            j = top;
            top = G[top].indegree; /** 退出栈顶元素*/
            printf("次序i%d:%d", i, G[j].data);   /**输出一个顶底*/
            p = G[j].link;
            while (p != NULL) {
                k = p->adjvex;          /** "删除"一条有j出发的临接顶点*/
                G[k].indegree--;        /** 当前输出邻接点的入度减一*/
                if (G[k].indegree == 0) {   /** 新的入度为0的顶点进栈*/
                    G[k].indegree = top;
                    top = k;
                }
                p = p->next;        /** 找到下一个邻接点*/
            }
        }
    }
}


/**
 * 计算三元矩阵的个节点的度
 * */
int DEG(int TA[][3], int n, int e, int degree[]) {

    /**
     * 初始化degree
     * */
    for (int i = 0; i < n; i++) {
        degree[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        degree[TA[i][0] - 1]++;
        degree[TA[i][1] - 1]++;
    }
}


/**
 * 由邻接矩阵转换为邻接链表
 * */
void ADDJLIST(Vlink G[], int n, int data[], int A[][n]) {

    Vlink *deliver = NULL, *new_vlink = NULL;
    for (int i = 0; i < n; ++i) {
        /**
         * 初始化V
         * */
        G[i].data = data[i];
        G[i].link = NULL;
        for (int j = 0; j < n; ++j) {
            if (A[i][j] != 0) {
                new_vlink = (Vlink *) malloc(sizeof(Vlink));
                new_vlink->data = j;
                new_vlink->link = NULL;
                /**
                 * 将连接添加到V的后面
                 * */
                if (G[i].link != NULL) {
                    G[i].link = new_vlink;
                } else {
                    deliver->link = new_vlink;
                }
                /**
                 * 重置deliver到新建的new_vlink上
                 * */
                deliver = new_vlink;
            }
        }
    }
}




