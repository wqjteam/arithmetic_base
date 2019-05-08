#include <stdio.h>
#include <mem.h>

/**
  * Created by wqj on 2019/5/7.
 */
int main(int argc, char *argv[]) {

    /**
     *����fgetc��fputcʹ��
     *
     * */
    FILE *fp;
    FILE *wp = fopen("output.txt", "w");
    if ((fp = fopen("input.txt", "r")) != NULL) {
        /**/
        int temp;
        /**
         * Ѱ���ļ���ָ���λ��
         * SEEK_SET�� �ļ���ͷ
         * SEEK_CUR�� ��ǰλ��
         * SEEK_END�� �ļ���β
         * rewind���� ���� (void)fseek(fp, 0L, SEEK_SET)
         *
         * */
        fseek(fp, 0, SEEK_SET);
        /**
         * fget(fp)��ȡ�ļ���,���Զ�ƫ��һλ
         * */
        while ((temp = fgetc(fp)) != EOF) {
            fputc(temp, wp);
        }
        fclose(fp);
        fclose(wp);
    }


    /**
     *
     * ����fgets��fputsʹ��
     * */
    FILE *fp2;
    FILE *wp2 = fopen("output2.txt", "w");
    if ((fp2 = fopen("input.txt", "r")) != NULL) {
        /**/
        char StrTemp[300];
        fseek(fp2, 0, SEEK_SET);
        /**
         * fget(fp)��ȡ�ļ���,���Զ�ƫ��һλ
         * */

        while (fgets(StrTemp, sizeof(StrTemp) / sizeof(char), fp2) != NULL) {
            /**
            * �����̨��ӡ����
            * */
            puts(StrTemp);
            /**
            * ������д���ļ�
            * */
            fputs(StrTemp, wp2);
        };


        fclose(fp2);
        fclose(wp2);
    }


    /**
     *
     * ����feof��ferrorʹ��
     *
     * **/
    FILE *wp3 = fopen("output3.txt", "w");
    fseek(fp, 0, SEEK_SET);

    if ((fp = fopen("input.txt", "r")) != NULL) {
        char StrTemp[300];
        while (!feof(fp)) {
            if (ferror(fp)) {
                perror("ϵͳ����");
                return 1;
            }
            fgets(StrTemp, sizeof(StrTemp) / sizeof(char), fp);
            fputs(StrTemp, wp3);
        }
    }
    fclose(wp3);


    /**
     * ����fread��fwriteʹ��
     *
     * */
    FILE *wp4 = fopen("output4.txt", "w");
    fseek(fp, 0, SEEK_SET);
    if (fp != NULL) {
        char StrTemp[200];
        /**
         * ����1��ʾ��ȡ��size�ֽڣ�����0��ʾ��ȡ��������size�ֽ�
         * */
        while (fread(StrTemp, sizeof(char), 200, fp) != 0) {
            fwrite(StrTemp, sizeof(char), strlen(StrTemp), wp4);
        }

    }
    fclose(fp);
    fclose(wp4);

    /**
     * ���fseek��ftell��rewind����������ʹ��
     * */
    FILE *fseekt = fopen("FseekTest.txt", "r");

    /**
     * ��ָ��ָ���ļ�ĩβ
     * */
    fseek(fseekt, 0, SEEK_END);
    /**
     * ��ȡָ����ְ������ļ�ͷ���ĳ���,
     * �����ڼ���ƫ����
     * */
    long offset = ftell(fseekt);
    printf("����|ƫ����:%ld\n", offset);
    /**
    * ��ָ��ָ���ļ�ͷ��
    * */
    rewind(fseekt);
    /**
     * ƫ��һλ
     * */
    fseek(fseekt, 1, SEEK_SET);
    printf("���:%c\n", fgetc(fseekt));

    fclose(fseekt);
    return 0;
}