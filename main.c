#include <stdio.h>
#include "Bubble.h"
/**
 * ��ʹ��main�����Ĵ��ΰ汾��ʱ����õľ��ǣ�int main(int argc , char* argv[]��;
 * ��������argc��argv�ǳ�������ƣ���ȻҲ���Ի����������ơ�
 * ������ִ�е���ʽΪ����ִ���ļ��� ����1 ����2 �� �� ����n����ִ���ļ����ƺͲ���������֮���ʹ�ÿո����
 * */
int main(int argc, char *argv[]) {
    int i;
    printf("Total %d arguments\n",argc);

    for(i = 0; i < argc; i++)
    {
        printf("\nArgument argv[%d]  = %s \n",i, argv[i]);
    }

    printf("Hello, World!\n");
    printf("1111����\n");
    printf("���Ϊ=%d\n",add(10,3));
    return 0;
}