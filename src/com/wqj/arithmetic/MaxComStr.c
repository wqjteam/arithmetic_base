/**
  * Created by wqj on 2019/8/22.
  * description:
 */
#include <stdio.h>
#include <string.h>

void main() {
    char *s = "asdfgh";
    char *t = "asertytyt";
    char c[20];
    int index = 0, length = 0, i = 0, j = 0, length2;
    /**
     * s为主的字符串,t为从字符串
     * i的s的位置 j为t的位置
     * */
    while (s[i] != '\0') {
        j = 0;
        while (t[j] != '\0') {
            if (s[i] == t[j]) {
                length2 = 1;
                /**
                 * 以s为基础,遇到第一个s[i]=t[j]
                 * 保证不溢出,不会出现大于下标的情况
                 * i + k < strlen(s)&& j + k < strlen(t)
                 * */
                for (int k = 0; i + k < strlen(s) && j + k < strlen(t) && s[i + k] == t[j + k]; ++k) {
                    length2++;
                }
                /**
                 * 比较两个length的长度大小
                 * */
                if (length2 > length) {
                    length = length2;
                    /**
                     * 并记录在s的起始index
                     * */
                    index = i;
                }
                /**
                 * 加上length2后,继续寻找
                 * */
                j = j + length2;
            } else {
                j++;
            }
        }
        i++;

    }
    for (int l = 0; l < length; ++l) {
        c[l] = s[index + l];
    }
    c[length] = '\0';
    i = 0;
    while (c[i] != '\0') {
        printf("%c", c[i]);
        i++;
    }

}