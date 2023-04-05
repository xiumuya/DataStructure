#include "sqstring.cpp"

#include "SqStack.cpp"	//包括顺序栈的定义和基本运算函数
bool symm(SqString s)
{
	int i=0; char e,x;
	bool flag=true;
	SqStack *st;
	InitStack(st);
	while (i<s.length)		//将'@'之前的字符进栈
	{
		e=s.data[i];
		if (e!='@')
			Push(st,e);
		else
			break;
		i++;
	}
	i++;					//跳过@字符
	while (i<s.length &&flag)
	{
		e=s.data[i];
		if (!Pop(st,x)) flag=false;
		if (e!=x) flag=false;
		i++;
	}
	if (!StackEmpty(st)) flag=false;
	DestroyStack(st);
	return flag;
}

int main()
{
	SqString s;
	StrAssign(s,"a+b@b+a");
	printf("s:");DispStr(s);
	printf("结果:%d\n",symm(s));
	return 1;
}

