#include "sqstack.cpp"
#include "sqqueue.cpp"

bool fun(SqQueue *&qu,int i)
{
	ElemType e;
	int j=1;
	int n=(qu->rear-qu->front+MaxSize)%MaxSize;
	if (j<1 || j>n) return false;
	for (j=1;j<=n;j++)
	{
		deQueue(qu,e);
		if (j!=i)
			enQueue(qu,e);
	}
	return true;
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
	fun(qu,2);
	while (!QueueEmpty(qu))
	{
		deQueue(qu,e);
		printf("%c ",e);
	}
	printf("\n");
	return 1;
}