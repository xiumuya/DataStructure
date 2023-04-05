#include "sqstack.cpp"
#include "sqqueue.cpp"

void Reverse(SqQueue *&qu)
{
	ElemType e;
	SqStack *st;
	InitStack(st);
	while (!QueueEmpty(qu))		//队不空时,出队并进栈
	{
		deQueue(qu,e);
		Push(st,e);
	}
	InitQueue(qu);				//队列初始化
	while (!StackEmpty(st))		//栈不空时,出栈并将元素入队
	{
		Pop(st,e);
		enQueue(qu,e);
	}
	DestroyStack(st);
}

int main()
{
	ElemType e;
	SqQueue *qu;
	InitQueue(qu);
	enQueue(qu,'a');
	enQueue(qu,'b');
	enQueue(qu,'c');
	enQueue(qu,'d');
	enQueue(qu,'e');
	Reverse(qu);
	while(!QueueEmpty(qu))
	{
		deQueue(qu,e);
		printf("%c ",e);
	}
	DestroyQueue(qu);
	return 1;
}