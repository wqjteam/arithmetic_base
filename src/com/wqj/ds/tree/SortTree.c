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

