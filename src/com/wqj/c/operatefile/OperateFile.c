/**
  * Created by wqj on 2019/5/6.
 */
#include <stdio.h>

void filecopy(FILE *fp);

/**
 *
 *打开文件:FILE *fp = fopen("path","mode");
 * */
int main(int argc, char *argv[]) {
/**
 * 几个常用的
 * getc(fp): 函数
 * putc(c,fp): 函数
 * fgets(fp): 宏定义
 * fputs(c,fp): 宏定义
 * fgetc(fp): 宏定义
 * fputc(c,fp): 宏定义
 * fscanf(fp,format,...): fscanf函数只能从文本文件中按格式输入
 * fprint(fp,format,....):fprintf函数按格式将内存中的数据转换成对应的字符，并以ASCⅡ代码形式输出到文本文件中
 *
 * 对于fget和fscanf区别:
 * fscanf读到空格或者回车时会把空格或回车转化为/0（字符串结束符）,
 * 而fgets函数则把空格（回车在下文解释）作为字符接收
 *
 *1、fgets遇到“空格”就跟遇到平常的字符一样读取，遇到“回车”则结束本次读取，
 * 最后往缓冲区(char *buf[])的最后加多一个"\0"表示本次读取一行结束。一般用fgets
 *
 *2、fscanf不论遇到“空格”还是“回车”，都当作'\0'读取到缓冲区中(char  *buf[])，并结束本次读取。
 * 导致丢失空格
 *
 *
 * 同时系统提供stdin  标准输入文件
 * 同时系统提供stdout 标书输出文件
 * 同时系统提供stderr 标准错误文件
 *
 * */
    FILE *fp;
    if (argc == 1) {
        filecopy(stdin);
    } else {
        while (--argc == 1) {
            fp = fopen(*(++argv), "r+");
            if ((fp == NULL)) {
                printf("出现了问题");
                return 1;
            } else {
                filecopy(fp);
                fclose(fp);
            }
        }
    }
    return 0;

}

void filecopy(FILE *fp) {
    int c;
    while ((c = fgetc(fp) != EOF))
        fputc(c, stdout);
    fclose(fp);
}

