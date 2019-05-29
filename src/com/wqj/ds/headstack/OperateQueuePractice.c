/**
  * Created by wqj on 2019/5/27.
  * description:
 */
#include <stdio.h>

#define  M 10
typedef struct node4 {
    char data;
    struct node4 *link;
} QLinkNode, *QLinkList;

int rightRomve(int array[], int n, int k);

int rightRomve2(int array[], int n, int k);

void conversion(int num);

void conversion2(int num);

int calcFunction(int m, int n);

int calcFunction(int m, int n);

int calcFunction2(int m, int n);

int main(int argc, char *argv[]) {
    int arr[M] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    rightRomve2(arr, M, 3);
    conversion(999999);
    conversion2(751);
    printf("�ݹ�ѭ��ֵΪ:%d\n", calcFunction(2, 1));
    printf("�ǵݹ�ѭ��ֵΪ:%d\n", calcFunction2(2, 1));
}


/**
 * ʱ�临�Ӷ�0(kn)
 * */
int rightRomve(int array[], int n, int k) {
    for (int i = 0; i < k; ++i) {
        int temp = array[n - 1];
        for (int j = n - 2; j >= 0; j--) {
            array[j + 1] = array[j];
        }
        array[0] = temp;
    }
}

/**
 * ʱ�临�Ӷ�0(n)
 * */
int rightRomve2(int array[], int n, int k) {
    int i = 0, j = 0, count = 1, temp;
    while (count < n) {
        j = (j + k) % n;
        if (i != j) {
            temp = array[j];
            array[j] = array[i];
            array[i] = temp;

        } else {
            j++;
            i++;
        }
        count++;
    }
}

void conversion(int num) {
    int STACK[100], top = -1;
    while (num != 0) {
        STACK[++top] = num % 8;
        num = num / 8;
    }
    while (top >= 0) {
        printf("%d", STACK[top--]);
    }
    printf("\n��1��\n");
}

void conversion2(int num) {
    char STACK[100];
    int top = -1, temp;
    while (num != 0) {
        switch (temp = num % 16) {
            case 10:
                STACK[++top] = 'A';
                break;
            case 11:
                STACK[++top] = 'B';
                break;
            case 12:
                STACK[++top] = 'C';
                break;
            case 13:
                STACK[++top] = 'D';
                break;
            case 14:
                STACK[++top] = 'E';
                break;
            case 15:
                STACK[++top] = 'F';
                break;
            default:
                STACK[++top] = (unsigned char) temp;
        };

        num = num / 16;
    }
    while (top >= 0) {
        printf("%c|", STACK[top--]);
    }
    printf("\n��2��\n");
}

/**
 * �ݹ��㷨
 * */
int calcFunction(int m, int n) {
    if (m * n == 0) {
        return m + n + 1;
    } else {
        return calcFunction(m - 1, calcFunction(m, n - 1));
    }
}

/**
 * �ǵݹ��㷨
 * */

/**
 * f(x)=    m+n+1
 *          f(m-1,f(m,n-1))
 *
 * f(2, 1) = f(1, f( 2, 0))
 * = f(1, 3 )
 * = f(0, f(1, 2))
 * = f(0, f(0, f(1, 1)))
 * = f(0, f(0, f(0, f(1, 0))))
 * = f(0, f(0, f(0, 2)))
 * = f(0, f(0, 3))
 * = f(0, 4)
 * = 5
 *
 *
 *
 * */
int calcFunction2(int m, int n) {
    int STACK[100], top = -1;
    do {
        /**
         * ��m��STACK������
         * */
        if (m * n != 0) {
            STACK[++top] = m - 1;
            n--;
        } else {
            n = m + n + 1;
            /**
             * Ϊ�˱���
             * ��һ�ν���
             * ʱtopΪ-1�����
             * ȡ������ֵ
             * */
            if (top >= 0) {
                m = STACK[top];
            }
            /**
             * ��top��һ
             * ��ô������-1ʱ��
             * �͵���-2��
             * */
            top--;
        }
    } while (top >= -1);
    return n;
}


/**
 * ��׺���ʽ�������Ǵ�����
 * ��õı��ʽ
 * */
/**
 * ��ѭ���²��裺
    (1) ��ʼ������ջ�������ջS1�ʹ����м�����ջS2��
    (2) ��������ɨ����׺���ʽ��
    (3) ����������ʱ������ѹ��S2��
    (4) ���������ʱ���Ƚ�����S1ջ������������ȼ���
    (4-1) ���S1Ϊ�գ���ջ�������Ϊ�����š�)������ֱ�ӽ����������ջ��
    (4-2) ���������ȼ���ջ��������Ľϸ߻���ȣ�Ҳ�������ѹ��S1��
    (4-3) ���򣬽�S1ջ���������������ѹ�뵽S2�У��ٴ�ת��(4-1)��S1���µ�ջ���������Ƚϣ�
    (5) ��������ʱ��
    (5-1) ����������š�)������ֱ��ѹ��S1��
    (5-2) ����������š�(���������ε���S1ջ�������������ѹ��S2��ֱ������������Ϊֹ����ʱ����һ�����Ŷ�����
    (6) �ظ�����(2)��(5)��ֱ�����ʽ������ߣ�
    (7) ��S1��ʣ�����������ε�����ѹ��S2��
    (8) ���ε���S2�е�Ԫ�ز�����������Ϊ��׺���ʽ��Ӧ��ǰ׺���ʽ
 *
 *
 *
 * */
