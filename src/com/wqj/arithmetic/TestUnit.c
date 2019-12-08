/**
  * Created by wqj on 2019/8/23.
  * description:
 */
#include <stdio.h>
#include <string.h>


void fun(int *s) {
    static int j = 0;
    do
        s[j] += s[j + 1];
    while (++j < 2);
}


void main() {
    char *b[3] = {"z 123 qwe qwe sdf qwe", "qwe  123 qwe qwe ", "zqwe  123 qwe qwe  ff"};
    char *s1 = b[0], *s2 = b[1], *s3 = b[2], common[200], *index;
    int len = 0, k, k2, flag;
    char *temp3, *temp2;
    while (*s1 != '\0') {
        temp2 = s2;
        while (*temp2 != '\0') {
            if (*temp2 == *s1) {
                for (k = 0; *(s1 + k) == *(temp2 + k) && *(s1 + k) != '\0' && *(temp2 + k) != '\0'; k++);
                /**加宁外一个判断*/
                temp3 = s3;
                flag = 0;
                while (*temp3 != '\0' && flag == 0) {
                    for (k2 = 0; *(s1 + k2) == *(temp3 + k2) && k2 < k; k2++);
                    if (k2 == k) {
                        flag = 1;
                    }
                    temp3++;
                }
                if (k > len && flag == 1) {
                    index = s1;
                    len = k;
                }
                temp2 = temp2 + k;
            } else temp2++;
        }
        s1++;

    }

    for (
            int j = 0;
            j < len;
            ++j) {
        printf("%c", *(index + j));
    }
    printf("::::");
}
