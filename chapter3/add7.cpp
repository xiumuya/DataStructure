#include "SqQueue.cpp"			//包含顺序队的类型定义和运算函数
bool Delk(SqQueue *&qu,int k)
{	ElemType e;
	int i,count=(qu->rear-qu->front+MaxSize)%MaxSize;
	if (k<=0 || k>count)
		return false;
	for (i=1;i<=count;i++)
	{	deQueue(qu,e);		//出队元素e
		if (i!=k)				//第k个元素只出不进
			enQueue(qu,e);	//其他元素出队后又进队
	}
	return true;
}
int main()
{
	SqQueue *qu;
	InitQueue(qu);
	enQueue(qu,'a');
	enQueue(qu,'b');
	enQueue(qu,'c');
	enQueue(qu,'d');
	ElemType e;
	int k=3; 
	Delk(qu,k);
	printf("出队第%d个元素\n",k); 
	printf("队中元素: ");
	while(!QueueEmpty(qu))
	{
		deQueue(qu,e);
		printf("%c ",e);
	}
	
	DestroyQueue(qu);
	
	return 0;
}
	
