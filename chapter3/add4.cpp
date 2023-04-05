#include "SqStack.cpp"			//包含顺序栈的定义及运算函数
bool isSerial(char str[],int n)
{	int i,j;
	char A[MaxSize],e;
	SqStack *st;				//建立一个顺序栈
	InitStack(st);
	for (i=0;i<n;i++)
		A[i]='a'+i;				//将abcde放入数组A中
	i=0;j=0;
	while (i<n)
	{
		Push(st,A[i]);
		printf("  元素%c进栈\n",A[i]);
		i++;	
		while (!StackEmpty(st) && (GetTop(st,e) && e==str[j]))
		{	Pop(st,e);
			printf("  元素%c出栈\n",e);
			j++;
		}
	}
	bool flag=StackEmpty(st);
	DestroyStack(st);
	return flag;
}
void Disp(char str[],int n)			//输出str
{	int i;
	for (i=0;i<n;i++)
		printf("%c",str[i]);
}
int main()
{	int n=5;
	char str[]="acbed";
	Disp(str,n); printf("的操作序列:\n");
	if (isSerial(str,n))
	{	Disp(str,n);
		printf("是合适的出栈序列\n");
	}
	else
	{	Disp(str,n);
		printf("不是合适的出栈序列\n");
	}
	return 1;
}
