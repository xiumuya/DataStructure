#include "sqstack.cpp"

void trans(int d,char b[])		//b用于存放d转换成的二进制数串
{	char e;
	SqStack *st;
	InitStack(st);
	int i=0;
	while (d!=0)
	{	e='0'+d%2;			//求余数并转换为字符
		Push(st,e);
		d/=2;				//继续求更高位
	}
	while (!StackEmpty(st))
	{	Pop(st,e);			//出栈元素e
		b[i]=e;				//将e存放在数组b中
		i++;
	}
	b[i]='\0';				//加入字符串结束标志
	DestroyStack(st);		//销毁栈
}

int main()
{
	int d=12;
	char b[MaxSize];
	trans(d,b);
	printf("%d=>%s\n",d,b);
	return 1;
}