/**
  * Created by wqj on 2019/6/17.
  * description:
 */
#include <OperateTree.h>
#include <malloc.h>

BiTree createIndexTree(int *data, int n) {
    BiTree root = NULL, deliver = NULL, temp = NULL;
    for (int i = 0; i < n; i++) {
        temp = (BiTree) malloc(sizeof(BiNode));
        temp->data = i;
        temp->right = NULL;
        temp->left = NULL;
        if (root == NULL) { /**判断是否存在头结点*/
            root = temp;
            continue;
        }
        deliver = root;
        while (1) {
            if (deliver->data > temp->data) { /**判断是否大于*/
                if (deliver->right == NULL) {
                    deliver->right = temp;
                    break;
                } else {
                    deliver = deliver->right;
                }
            } else { /**对于小于插入右边*/
                if (deliver->left == NULL) {
                    deliver->left = temp;
                    break;
                } else {
                    deliver = deliver->left;
                }
            }
        }
    }
    return root;

}

/**
 * 1.被删除结点为叶结点,则直接删除
 * 2.被删除结点无左子树,  则用右子树的根结点 取代被删除结点
 * 3.被删除结点无右子树,  则用左子树的根结点 取代被删除结点
 * 4.被删除结点的左、右子 树都存在，则用被删除 结点的右子树中值最小 的结点
 * （或被删除结点 的左子树中值最大的结 点)取代被删除结点
 * */

BiTree deleteBiTree(BiTree root, int qdata) {
    BiTree deliver = root, predeliver = NULL, temp = NULL;
    while (1) {
        if (deliver == NULL) {
            printf("找不到");
            break;
        }
        if (deliver->data == qdata) {
            /**
             * 如果deliver的左右子节点都为NULL
             */
            if (deliver->left == NULL && deliver->right == NULL) {
                if (predeliver->left == deliver) {
                    predeliver->left = NULL;
                } else {
                    predeliver->right = NULL;
                }
            }

            /**
             * 如果deliver的左子节点都为NULL,右节点不为NULL
             */
            if (deliver->left == NULL && deliver->right != NULL) {
                if (predeliver->left == deliver) {
                    predeliver->left = deliver->right;
                } else {
                    predeliver->right = deliver->right;
                }
            }


            /**
             * 如果deliver的右子节点都为NULL,左节点不为NULL
             */
            if (deliver->right == NULL && deliver->left != NULL) {
                if (predeliver->right == deliver) {
                    predeliver->left = deliver->left;
                } else {
                    predeliver->right = deliver->left;
                }
            }

            /**
             * 对付第四种
             * 情况
             * */
            if (deliver->right != NULL && deliver->left != NULL) {
                /**
                 * 找左子树中最大的节点
                 * 或者右子数最小的节点
                 * 填充该位置
                 * */

                findLeftMaxData(deliver, predeliver);

            }

            break;
        }
        if (deliver->data > qdata) {
            predeliver = deliver;
            deliver = deliver->left;
        } else {
            predeliver = deliver;
            deliver = deliver->right;
        }
    }

}

void findLeftMaxData(BiTree deliver, BiTree preDeliver) {
    /**找左子树中最大的节点*/
    BiTree deliver2 = deliver->left, predeliver2 = deliver->left;
    while (deliver2->right != NULL) {/** 一直寻找右节点即为最大的节点*/
        predeliver2 = deliver2;
        deliver2 = deliver2->right;
    }

    /**处理寻找移动的节点*/
    if (predeliver2->right == deliver2) {
        predeliver2->left = deliver2->left;
    } else {
        predeliver2->right = deliver2->left;
    }

    /**添加末尾*/
    deliver2->left == NULL;
    deliver2->right == NULL;
    if (deliver->left != deliver2) {

        deliver2->left = deliver->left;
    }
    if (deliver2->right != deliver2) {

        deliver2->right = deliver->right;
    }
    /**处理替换节点*/
    if (preDeliver->left == deliver) {
        preDeliver->left = deliver2;
    } else {
        preDeliver->right = deliver2;
    }


}
/**
 * 寻找data的双亲节点
 *
 * */
void findfatherItem(BiTree tree,int data){
    while(tree!=NULL){
        if(data>tree->data){
            printf("路过该节点");
            tree=tree->right;
        }
        if(data<tree->data){
            printf("路过该节点");
            tree=tree->left;
        }
        if(data==tree->data){
            /**
             * 循环到此结束
             * */
            return;
        }
    }

    printf("找不到该节点");

}




