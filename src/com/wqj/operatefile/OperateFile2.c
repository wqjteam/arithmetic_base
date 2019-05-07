#include <stdio.h>
#include <mem.h>

/**
  * Created by wqj on 2019/5/7.
 */
int main(int argc, char *argv[]) {

    /**
     *关于fgetc和fputc使用
     *
     * */
    FILE *fp;
    FILE *wp = fopen("output.txt", "w");
    if ((fp = fopen("input.txt", "r")) != NULL) {
        /**/
        int temp;
        /**
         * 寻找文件的指针的位置
         * SEEK_SET： 文件开头
         * SEEK_CUR： 当前位置
         * SEEK_END： 文件结尾
         * rewind函数 等于 (void)fseek(fp, 0L, SEEK_SET)
         *
         * */
        fseek(fp, 0, SEEK_SET);
        /**
         * fget(fp)读取文件后,会自动偏移一位
         * */
        while ((temp = fgetc(fp)) != EOF) {
            fputc(temp, wp);
        }
        fclose(fp);
        fclose(wp);
    }


    /**
     *
     * 关于fgets和fputs使用
     * */
    FILE *fp2;
    FILE *wp2 = fopen("output2.txt", "w");
    if ((fp2 = fopen("input.txt", "r")) != NULL) {
        /**/
        char StrTemp[300];
        fseek(fp2, 0, SEEK_SET);
        /**
         * fget(fp)读取文件后,会自动偏移一位
         * */

        while (fgets(StrTemp, sizeof(StrTemp) / sizeof(char), fp2) != NULL) {
            /**
            * 向控制台打印数据
            * */
            puts(StrTemp);
            /**
            * 将数据写入文件
            * */
            fputs(StrTemp, wp2);
        };


        fclose(fp2);
        fclose(wp2);
    }


    /**
     *
     * 关于feof和ferror使用
     *
     * **/
    FILE *wp3 = fopen("output3.txt", "w");
    fseek(fp, 0, SEEK_SET);

    if ((fp = fopen("input.txt", "r")) != NULL) {
        char StrTemp[300];
        while (!feof(fp)) {
            if (ferror(fp)) {
                perror("系统出错");
                return 1;
            }
            fgets(StrTemp, sizeof(StrTemp) / sizeof(char), fp);
            fputs(StrTemp, wp3);
        }
    }
    fclose(wp3);


    /**
     * 关于fread和fwrite使用
     *
     * */
    FILE *wp4 = fopen("output4.txt", "w");
    fseek(fp, 0, SEEK_SET);
    if (fp != NULL) {
        char StrTemp[200];
        /**
         * 返回1表示读取了size字节，返回0表示读取数量不够size字节
         * */
        while (fread(StrTemp, sizeof(char), 200, fp) != 0) {
            fwrite(StrTemp, sizeof(char), strlen(StrTemp), wp4);
        }

    }
    fclose(fp);
    fclose(wp4);

    /**
     * 针对fseek和ftell和rewind三个方法的使用
     * */
    FILE *fseekt = fopen("FseekTest.txt", "r");

    /**
     * 将指正指向文件末尾
     * */
    fseek(fseekt, 0, SEEK_END);
    /**
     * 获取指正文职最后离文件头部的长度,
     * 常用于计算偏移量
     * */
    long offset = ftell(fseekt);
    printf("长度|偏移量:%ld\n", offset);
    /**
    * 将指针指向文件头部
    * */
    rewind(fseekt);
    /**
     * 偏移一位
     * */
    fseek(fseekt, 1, SEEK_SET);
    printf("结果:%c\n", fgetc(fseekt));

    fclose(fseekt);
    return 0;
}