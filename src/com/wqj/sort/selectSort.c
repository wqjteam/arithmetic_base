#include <stdio.h>
//选择排序
int main()
{
	int sorta[9] = { 1, 3, 4, 5, 6, 9, 4, 7, 0 };
	int sie = sizeof(sorta) / sizeof(sorta[0]);
	printf("长度\n", sie);
	for (int i = 0; i < sie; i++)
	{
		printf("%d|原来的数据%d\n", sorta[i], i);
	}

	int index;
	for (int i = 0; i < sie; i++)
	{
		printf("进入到次");
		//获取最大的数据
		int temp = sorta[i];
		for (int j = i; j < sie; j++)
		{
			printf("ѭ���ڲ�temp%d|��sorta[j]%d\n", temp, sorta[j]);
			if (sorta[j] >= temp)
			{
				temp = sorta[j];
				index = j;
			}
		}
		printf("最大的位置d%\n", index, temp);
		//记录最大的下标位置
		if (temp > sorta[i])
		{
			sorta[index] = sorta[i];
			sorta[i] = temp;
		}
	}

	for (int i = 0; i < sie; i++)
	{
		printf("%d,", sorta[i]);
	}

	return 0;
}
