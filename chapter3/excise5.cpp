#include "sqstack.cpp"

void fun(SqStack *&st,ElemType x)
{
	SqStack *s; 
	ElemType d;
	InitStack(s);
	while(!StackEmpty(st))
	{	Pop(st,d);
		if(d!=x) Push(s,d);
	}
	while (!StackEmpty(s))
	{	Pop(s,d);
		Push(st,d);
	}
	DestroyStack(s);
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
	fun(st,'c');
	while (!StackEmpty(st))
	{
		Pop(st,e);
		printf("%c ",e);
	}
	printf("\n");
	return 1;
}