#include "SqQueue2.cpp"					//包含顺序队的类型定义和运算函数
bool deQueue1(SqQueue *&q,ElemType &e)	//从队头出队算法
{	if (q->front==q->rear)				//队空下溢出
		return false;
	q->front=(q->front+1)%MaxSize;		//修改队头指针
	e=q->data[q->front];
	return true;
}
bool enQueue1(SqQueue *&q,ElemType e)	//从队头进队算法
{  	if ((q->rear+1)%MaxSize==q->front)	//队满
		return false;
   	q->data[q->front]=e;				//e元素进队
   	q->front=(q->front-1+MaxSize)%MaxSize;//修改队头指针
   	return true;
}
bool enQueue2(SqQueue *&q,ElemType e)	//从队尾进队算法
{	if ((q->rear+1)%MaxSize==q->front)	//队满上溢出
		return false;
	q->rear=(q->rear+1)%MaxSize;		//修改队尾指针
	q->data[q->rear]=e;				//e元素进队
	return true;
}
void fun(int a[],int n)
{	int i;
	ElemType e;
	SqQueue *qu;
	InitQueue(qu);
	for (i=0;i<n;i++)
	{	if (a[i]>=90)
			printf("%d ",a[i]);
		else if (a[i]>=60)
			enQueue2(qu,a[i]);	//从队尾进队
		else
			enQueue1(qu,a[i]);	//从队头进队
	}
	while (!QueueEmpty(qu))
	{	deQueue1(qu,e);		//从队头出队
		printf("%d ",e);
	}
	printf("\n");
	DestroyQueue(qu);
}
int main()
{
	int a[]={90,30,70,80,92,56};
	int n=sizeof(a)/sizeof(a[0]);
	fun(a,n);
	return 0;
}
	
