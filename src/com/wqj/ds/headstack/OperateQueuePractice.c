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

void convertOperate1(char *t, int n);

void convertOperate2(char *t, int n);

int main(int argc, char *argv[]) {
    int arr[M] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    rightRomve2(arr, M, 3);
    conversion(999999);
    conversion2(751);
    printf("递归循环值为:%d\n", calcFunction(2, 1));
    printf("非递归循环值为:%d\n", calcFunction2(2, 1));

    char str[100] = "1+((2+3)*4)-5";
    convertOperate1(str, 13);
    convertOperate2(str, 13);
}


/**
 * 时间复杂度0(kn)
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
 * 时间复杂度0(n)
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
    printf("\n结1束\n");
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
    printf("\n结2束\n");
}

/**
 * 递归算法
 * */
int calcFunction(int m, int n) {
    if (m * n == 0) {
        return m + n + 1;
    } else {
        return calcFunction(m - 1, calcFunction(m, n - 1));
    }
}

/**
 * 非递归算法
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
         * 把m用STACK存起来
         * */
        if (m * n != 0) {
            STACK[++top] = m - 1;
            n--;
        } else {
            n = m + n + 1;
            /**
             * 为了避免
             * 第一次进来
             * 时top为-1的情况
             * 取到垃圾值
             * */
            if (top >= 0) {
                m = STACK[top];
            }
            /**
             * 将top减一
             * 那么当等于-1时候
             * 就等于-2了
             * */
            top--;
        }
    } while (top >= -1);
    return n;
}


/**
 * 中缀表达式就是我们大脑中
 * 最常用的表达式
 * */
/**
 * 遵循以下步骤：
    (1) 初始化两个栈：运算符栈S1和储存中间结果的栈S2；
    (2) 从右至左扫描中缀表达式；
    (3) 遇到操作数时，将其压入S2；
    (4) 遇到运算符时，比较其与S1栈顶运算符的优先级：
    (4-1) 如果S1为空，或栈顶运算符为右括号“)”，则直接将此运算符入栈；
    (4-2) 否则，若优先级比栈顶运算符的较高或相等，也将运算符压入S1；
    (4-3) 否则，将S1栈顶的运算符弹出并压入到S2中，再次转到(4-1)与S1中新的栈顶运算符相比较；
    (5) 遇到括号时：
    (5-1) 如果是右括号“)”，则直接压入S1；
    (5-2) 如果是左括号“(”，则依次弹出S1栈顶的运算符，并压入S2，直到遇到右括号为止，此时将这一对括号丢弃；
    (6) 重复步骤(2)至(5)，直到表达式的最左边；
    (7) 将S1中剩余的运算符依次弹出并压入S2；
    (8) 依次弹出S2中的元素并输出，结果即为中缀表达式对应的前缀表达式
 *
 *
 *  A*(B–C)/D+E
 *  ABC–*D/E+
 * */

/**
 *
 * 中缀转前缀
 * */
void convertOperate1(char *t, int n) {
    char STACK1[100], STACK2[100];
    int top1 = -1, top2 = -1;
    for (int i = n - 1; i >= 0; i--) {
//        switch (t[i]){
//            case '(':STACK2[++top2];break;
//            case ')':STACK2[++top2];break;
//            case '+':STACK2[++top2];break;
//            case '-':STACK2[++top2];break;
//            case '*':STACK2[++top2];break;
//            case '/':STACK2[++top2];break;
//            case '0':STACK1[++top1];break;
//            case '1':STACK1[++top1];break;
//            case '2':STACK1[++top1];break;
//            case '3':STACK1[++top1];break;
//            case '4':STACK1[++top1];break;
//            case '5':STACK1[++top1];break;
//            case '6':STACK1[++top1];break;
//            case '7':STACK1[++top1];break;
//            case '8':STACK1[++top1];break;
//            case '9':STACK1[++top1];break;
//        }

        if (t[i] == ')') {
            STACK2[++top2] = t[i];
        }
        if (t[i] == '(') {
            /**
             * 遇到 ( 就弹栈,
             * 直至遇到遇到)为止
             * */
            for (int j = top2; j > -1; j--) {
                if (STACK2[top2] != ')') {
                    STACK1[++top1] = STACK2[top2];
                } else {
                    top2--;
                    break;
                }
                top2--;
            }


        }
        if (t[i] == '+' || t[i] == '-' || t[i] == '*' || t[i] == '/') {
            STACK2[++top2] = t[i];
        }
        if (t[i] == '0' || t[i] == '1' || t[i] == '2' || t[i] == '3' ||
            t[i] == '4' || t[i] == '5' || t[i] == '6' || t[i] == '7' || t[i] == '8' || t[i] == '9') {
            STACK1[++top1] = t[i];
        }
    }

    /**
     * 循环遍历之后
     * 再清空stack2中的运算符
     * */
    while (top2 > -1) {
        STACK1[++top1] = STACK2[top2--];
    }

    printf("\n前缀运算:");
    while (top1 > -1) {
        printf("%c", STACK1[top1--]);
    }
}

/**
 *
 * 中缀转后缀
 * */
void convertOperate2(char *t, int n) {
    char STACK1[100], STACK2[100];
    int top1 = -1, top2 = -1;
    for (int i = 0; i < n; i++) {
//        switch (t[i]){
//            case '(':STACK2[++top2];break;
//            case ')':STACK2[++top2];break;
//            case '+':STACK2[++top2];break;
//            case '-':STACK2[++top2];break;
//            case '*':STACK2[++top2];break;
//            case '/':STACK2[++top2];break;
//            case '0':STACK1[++top1];break;
//            case '1':STACK1[++top1];break;
//            case '2':STACK1[++top1];break;
//            case '3':STACK1[++top1];break;
//            case '4':STACK1[++top1];break;
//            case '5':STACK1[++top1];break;
//            case '6':STACK1[++top1];break;
//            case '7':STACK1[++top1];break;
//            case '8':STACK1[++top1];break;
//            case '9':STACK1[++top1];break;
//        }

        if (t[i] == ')') {
            /**
              * 遇到 )就弹栈,
              * 直至遇到遇到(为止
              * */
            for (int j = top2; j > -1; j--) {
                if (STACK2[top2] != '(') {
                    STACK1[++top1] = STACK2[top2];
                } else {
                    top2--;
                    break;
                }
                top2--;
            }

        }
        if (t[i] == '(') {
            STACK2[++top2] = t[i];

        }
        if (t[i] == '+' || t[i] == '-' || t[i] == '*' || t[i] == '/') {
            STACK2[++top2] = t[i];
        }
        if (t[i] == '0' || t[i] == '1' || t[i] == '2' || t[i] == '3' ||
            t[i] == '4' || t[i] == '5' || t[i] == '6' || t[i] == '7' || t[i] == '8' || t[i] == '9') {
            STACK1[++top1] = t[i];
        }
    }

    /**
     * 循环遍历之后
     * 再清空stack2中的运算符
     * */
    while (top2 > -1) {
        STACK1[++top1] = STACK2[top2--];
    }

    printf("\n后缀运算:");
    while (top1 > -1) {
        printf("%c", STACK1[top1--]);
    }
}




