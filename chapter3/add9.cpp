#include <stdio.h>
#include <malloc.h>
#define MaxSize 100
typedef char ElemType;
typedef struct 
{	ElemType data[MaxSize];
	int front,rear;	//队头和队尾指针
	int tag;			//为0表示队可能空,为1时表示队可能满
} QueueType;

void InitQueue1(QueueType &qu)		//初始化队列算法
{	qu.front=qu.rear=0;
	qu.tag=0;						//为0表示队空可能为空
}
bool QueueEmpty1(QueueType qu)		//判队空算法
{
	return(qu.front==qu.rear && qu.tag==0);
}
bool QueueFull1(QueueType qu)		//判队满算法
{
	return(qu.tag==1 && qu.front==qu.rear);
}
bool EnQueue1(QueueType &qu,ElemType x)//进队算法
{	if (QueueFull1(qu)==1)			//队满
		return false;
	qu.rear=(qu.rear+1)%MaxSize;
	qu.data[qu.rear]=x;
	qu.tag=1;						//至少有一个元素,可能满
	return true;
}
bool DeQueue1(QueueType &qu,ElemType &x)//出队算法
{	if (QueueEmpty1(qu)==1)			//队空
		return false;
	qu.front=(qu.front+1)%MaxSize;
	x=qu.data[qu.front];
	qu.tag=0;						//出队一个元素,可能空
	return true;
}
int main()
{
	QueueType qu;
	InitQueue1(qu);
	EnQueue1(qu,'a');
	EnQueue1(qu,'b');
	EnQueue1(qu,'c');
	EnQueue1(qu,'d');
	ElemType e;
	printf("队中元素: ");
	while(!QueueEmpty1(qu))
	{
		DeQueue1(qu,e);
		printf("%c ",e);
	}
	
	return 0;
}
	
