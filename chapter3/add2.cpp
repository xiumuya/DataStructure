#include "sqstack.cpp"

void DispStack(SqStack *st)
{	ElemType x;
	SqStack *tmpst;			//定义临时栈
	InitStack(tmpst);			//初始化临时栈
	while (!StackEmpty(st))		//临时栈tmpst中包含st栈中的逆转元素
	{	Pop(st,x);
		printf("%c ",x);
		Push(tmpst,x);
	}
	printf("\n");
	while (!StackEmpty(tmpst))	//恢复st栈中原来的内容
	{	Pop(tmpst,x);
		Push(st,x);
	}
	DestroyStack(tmpst);
}


int main()
{
	SqStack *st;
	InitStack(st);
	Push(st,'a');
	Push(st,'b');
	Push(st,'c');
	Push(st,'d');
	Push(st,'e');
	DispStack(st);
	DestroyStack(st);
	return 1;
}