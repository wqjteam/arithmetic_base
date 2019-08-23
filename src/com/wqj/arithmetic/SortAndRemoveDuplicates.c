/**
  * Created by wqj on 2019/8/22.
  * description: 排序并去重
 */
#include <stdio.h>
#include <string.h>

void main() {

    char str[100] = "aaabbccddeeffgggghhhhiiij", temp;
    char str3[][10] = {"aaa", "bbcc", "ffgggg"};
    char str4[] = "asd";
    int b1 = sizeof(str4);
    int a = sizeof(str3);
    int a2 = sizeof(str3[0]);
    int a3 = sizeof(str3[1]);
    int a4 = strlen(str3[0]);

    /**
     * 证明用*str生成就是final的变量
     * */
    char str2[] = "asertytyt111";
//   strcpy(str3,str);
//    strcmp(str3,"asertytyt");
//    *str2 = 'z';
//    str2[0] = 'z';
    int index;
    /**
     * 排序
     * */
    for (int i = 0; i < strlen(str); ++i) {
        index = i;
        for (int j = i + 1; j < strlen(str); j++) {
            if (str[index] > str[j]) {
                index = j;
            }
        }
        if (index != i) {
            temp = str[i];
            str[i] = str[index];
            str[index] = temp;
        }
    }
    /**
     * 去重,count就是不同元素的个数
     * 从0开始,所以会有count+1个元素
     * 那么他的最后一个元素下标就是count
     * 可以吧'\0'放置在count+1
     * */
    int count = 0;
    for (int k = 1; k < strlen(str); ++k) {
        if (str[count] != str[k]) {
            count++;
            str[count] = str[k];
        }
    }
    str[count + 1] = '\0';
    puts(str);

}