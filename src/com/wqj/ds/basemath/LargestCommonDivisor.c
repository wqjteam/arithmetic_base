/**
  * Created by wqj on 2019/5/8.
  * descripttion:最大公约数
  *
 */
#include <stdio.h>

int main(int argc, char *argv[]) {
//    printf("请输入数据用空格分隔,最多5个\n");
//    int data[5];
//    for (int i = 0; i <5; ++i) {
//    scanf(" %d",(data+i));
//    }
//    for (int j = 0; j <5 ; ++j) {
//       printf("%d",data[j]);
//    }

    int a=100,b=60;
    while(1){
        int temp;
        if((temp=b%a)==0){
            printf("最大的公因数:%d\n",a);
            break;
        }
        b=a;
        a=temp;
    }

}