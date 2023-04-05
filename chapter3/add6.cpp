#include "SqQueue.cpp"			//包含顺序队的类型定义和运算函数
ElemType Last(SqQueue *qu)
{	ElemType x;
	int i,count=(qu->rear-qu->front+MaxSize)%MaxSize;
	for (i=1;i<=count;i++)
	{	deQueue(qu,x);		//出队元素x
		enQueue(qu,x);		//将元素x进队
	}
	return x;
}
int main()
{
	SqQueue *qu;
	InitQueue(qu);
	enQueue(qu,'a');
	enQueue(qu,'b');
	enQueue(qu,'c');
	enQueue(qu,'d');
	printf("队尾元素:%c\n",Last(qu));
	DestroyQueue(qu);

	return 0;
}
	
