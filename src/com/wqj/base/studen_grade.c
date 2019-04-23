#include <stdio.h>
void e(int argc, char const *argv[])
{
    /* code */
    int grade;
    printf("请输出成绩:\n");
	scanf_s("%d", &grade);
    // if(grade>60){
    //     printf("Pass%d\n",grade);
    // }else{
    //     printf("Fail%d\n",grade);
    // }

    switch (grade)
    {
    case 60:
        printf("及格");
        break;
    default:
        printf("不及格");
    }
}
