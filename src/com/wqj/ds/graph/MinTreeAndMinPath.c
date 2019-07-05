/**
  * Created by wqj on 2019/7/2.
  * description:
 */
#include <OperateGraph.h>


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
