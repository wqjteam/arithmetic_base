//
// Created by lenovo on 2019/4/23.
//
#include <stdio.h>

#define  NUM 10

int main() {

    FILE *in, *out;

    in = fopen("input.txt", "r");
    out = fopen("output.txt", "w");
    /**
     *
     * ����Ϊ
     * ���
     * ����
     * ��
     * �ļ���
     *
     * */
    for (int j = 0; j < 10; ++j) {
        fprintf(out,"%d",j);
    }
    fclose(out);

    int scorelist[NUM], i;
    for (int i = 0; i < NUM; ++i) {
            fscanf(in,"%d",&scorelist[i]);
            printf("%d ",scorelist[i]);
    }

    printf("\n");
    /**
     *
     * ��ϰ
     * ָ��
     *
     *
     * */
    int x = 100;
    int *px;
    px = &x;

    printf("int�Ľ��Ϊ%d",*px);

}
