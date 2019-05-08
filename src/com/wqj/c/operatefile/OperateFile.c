/**
  * Created by wqj on 2019/5/6.
 */
#include <stdio.h>

void filecopy(FILE *fp);

/**
 *
 *���ļ�:FILE *fp = fopen("path","mode");
 * */
int main(int argc, char *argv[]) {
/**
 * �������õ�
 * getc(fp): ����
 * putc(c,fp): ����
 * fgets(fp): �궨��
 * fputs(c,fp): �궨��
 * fgetc(fp): �궨��
 * fputc(c,fp): �궨��
 * fscanf(fp,format,...): fscanf����ֻ�ܴ��ı��ļ��а���ʽ����
 * fprint(fp,format,....):fprintf��������ʽ���ڴ��е�����ת���ɶ�Ӧ���ַ�������ASC�������ʽ������ı��ļ���
 *
 * ����fget��fscanf����:
 * fscanf�����ո���߻س�ʱ��ѿո��س�ת��Ϊ/0���ַ�����������,
 * ��fgets������ѿո񣨻س������Ľ��ͣ���Ϊ�ַ�����
 *
 *1��fgets�������ո񡱾͸�����ƽ�����ַ�һ����ȡ���������س�����������ζ�ȡ��
 * �����������(char *buf[])�����Ӷ�һ��"\0"��ʾ���ζ�ȡһ�н�����һ����fgets
 *
 *2��fscanf�����������ո񡱻��ǡ��س�����������'\0'��ȡ����������(char  *buf[])�����������ζ�ȡ��
 * ���¶�ʧ�ո�
 *
 *
 * ͬʱϵͳ�ṩstdin  ��׼�����ļ�
 * ͬʱϵͳ�ṩstdout ��������ļ�
 * ͬʱϵͳ�ṩstderr ��׼�����ļ�
 *
 * */
    FILE *fp;
    if (argc == 1) {
        filecopy(stdin);
    } else {
        while (--argc == 1) {
            fp = fopen(*(++argv), "r+");
            if ((fp == NULL)) {
                printf("����������");
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

