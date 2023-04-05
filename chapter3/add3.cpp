#include "SqStack.cpp"			//包含顺序栈的定义及运算函数
bool Findk(SqStack *st,int k,ElemType &e)
{	int i=0;
	bool flag=false;
	ElemType x;
	SqStack *tmpst;			//定义临时栈
	InitStack(tmpst);			//初始化临时栈
	while (!StackEmpty(st))		//临时栈tmpst中包含st栈中的逆转元素
	{	i++;
		Pop(st,x);
		if (i==k)
		{	e=x;
			flag=true;
		}
		Push(tmpst,x);
	}
	while (!StackEmpty(tmpst))	//恢复st栈中原来的内容
	{	Pop(tmpst,x);
		Push(st,x);
	}
	DestroyStack(tmpst);
	return flag;
}

int main()
{
	ElemType e;
	SqStack *st;
	InitStack(st);
	Push(st,'a');
	Push(st,'b');
	Push(st,'c');
	Push(st,'d');
	Push(st,'e');
	if (Findk(st,4,e))
		printf("e:%c\n",e);
	else
		printf("No Found\n");
	DestroyStack(st);
	return 1;
}