/**
  * Created by wqj on 2019/5/9.
  * description:
 */

#include<stdio.h>

void findItem(char (*Collect)[10], char *item, int rows);

void insertItem(char *Collect, int *len, char item, int location);

void deleteItem(char *Collect, int *len, int location);

void testPara(char *Collect,char Collect2[]);

int main(int argc, char *argv[]) {

    char Collect[][10] = {"zs", "lisi", "ww", "zls", "zl"};

    char item[10] = {"zl"};
    findItem(Collect, item, sizeof(Collect) / sizeof(*Collect));

    char Collect2[10] = {"qweerrt"};
    int len = 7;
    insertItem(Collect2, &len, 'z', 3);
    printf("长度%d\n", len);
    printf("1liner:%s\n", Collect2);

    deleteItem(Collect2, &len, 3);
    printf("2liner:%s\n", Collect2);

     char testCollect[5]={"12345"};
    testPara(testCollect,testCollect);
    printf("3liner:%s\n", testCollect);
}


/**
  * 时间复杂度 O(n2)
  * */
void findItem(char (*Collect)[10], char *item, int rows) {

    for (int i = 0; i < rows; ++i) {

        for (int j = 0; j < sizeof(Collect[i]) / sizeof(char); ++j) {
            if (item[j] != Collect[i][j]) {
                break;
            } else {
                if (j == sizeof(Collect[i]) / sizeof(char) - 1) {
                    printf("有相同的元素%s,位置%d\n", *(Collect + i), i + 1);
                    return;
                }
            }

        }
    }
    printf("无相同的元素\n");
}

void insertItem(char *Collect, int *len, char item, int location) {

    if (*len == 10 || location < 1 || location + 1 > 10) {
        printf("异常");
        return;
    } else {
        /**
         * 不考虑 间隔情况
         * */
//        if(location>len){
//
//        }
        for (int i = *len - 1; i >= location - 1; --i) {
            Collect[i + 1] = Collect[i];
        }
        Collect[location - 1] = item;
        (*len)++;
        printf("数据插入结束\n");
    }
}


void deleteItem(char *Collect, int *len, int location) {
    if (location > *len || location < 1) {
        printf("输入参数异常\n");
        return;
    }
    for (int i = location; i < *len; ++i) {
        Collect[i - 1] = Collect[i];
    }
    (*len)--;
}

void testPara(char *Collect,char Collect2[]){
    Collect[0]='q';
    Collect2[1]='w';
}