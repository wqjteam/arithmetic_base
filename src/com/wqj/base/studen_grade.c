#include <stdio.h>

void e(int argc, char const *argv[]) {
    /* code */
    int grade;
    printf("������ɼ�:\n");
    scanf("%d", &grade);
    // if(grade>60){
    //     printf("Pass%d\n",grade);
    // }else{
    //     printf("Fail%d\n",grade);
    // }

    switch (grade) {
        case 60:
            printf("����");
            break;
        default:
            printf("������");
    }
}
