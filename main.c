#include <stdio.h>
#include "Bubble.h"
/**
 * 在使用main函数的带参版本的时，最常用的就是：int main(int argc , char* argv[]）;
 * 变量名称argc和argv是常规的名称，当然也可以换成其他名称。
 * 命令行执行的形式为：可执行文件名 参数1 参数2 … … 参数n。可执行文件名称和参数、参数之间均使用空格隔开
 * */
int main(int argc, char *argv[]) {
    int i;
    printf("Total %d arguments\n",argc);

    for(i = 0; i < argc; i++)
    {
        printf("\nArgument argv[%d]  = %s \n",i, argv[i]);
    }

    printf("Hello, World!\n");
    printf("1111哈哈\n");
    printf("结果为=%d\n",add(10,3));
    return 0;
}