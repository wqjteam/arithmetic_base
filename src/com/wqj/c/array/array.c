#include<stdio.h>
int main(int argc, char const *argv[])
{
    /* code */
    int x[50];
    int a;
	scanf("%d",&a);
    x[a+1]++;
    for (int i = 0; i <10 ;) {
        printf("%d\n",i);
        ++i;
    }
    switch(1){
        /**case 1:case 2 可以重叠*/
        case 1:case 2:printf("12213");
    };/** ;可加可不加*/

    return 0;

}
