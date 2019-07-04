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


void Dijkstra(int Matrix[][VNUM], int sv) {
    int P[VNUM];             // 辅助数组
    int Dist[VNUM];          // 存放最短路径，权值
    int Mark[VNUM];         // 标记数组
    int i = 0;
    int j = 0;
    if()
}