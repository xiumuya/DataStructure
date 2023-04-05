#include <stdio.h>
#include <malloc.h>
#define MaxSize 100
typedef char ElemType;
typedef struct
{	ElemType data[MaxSize];
	int rear;						//队尾指针
	int count;					//队列中元素个数
} QuType;							//队列类型
void InitQu(QuType *&q)				//队列初始化运算
{	q=(QuType *)malloc(sizeof(QuType));
	q->rear=0;
	q->count=0;
}
bool EnQu(QuType *&q,ElemType x)		//进队运算
{	if (q->count==MaxSize)			//队满上溢出
		return false;
	else
	{	q->rear=(q->rear+1)%MaxSize;
		q->data[q->rear]=x;
		q->count++;
		return true;
	}
}
bool DeQu(QuType *&q,ElemType &x)		//出队运算
{	int front;					//局部变量
	if (q->count==0)				//队空下溢出
		return false;
	else
	{	front=(q->rear-q->count+MaxSize)%MaxSize; 
		front=(front+1)%MaxSize;	//队头位置进1
		x=q->data[front];
		q->count--;
		return true;
	}
}
bool QuEmpty(QuType *q)		//判空运算
{
	return(q->count==0);
}
int main()
{
	QuType *qu;
	InitQu(qu);
	EnQu(qu,'a');
	EnQu(qu,'b');
	EnQu(qu,'c');
	EnQu(qu,'d');
	ElemType e;
	printf("队中元素: ");
	while(!QuEmpty(qu))
	{
		DeQu(qu,e);
		printf("%c ",e);
	}
	
	return 0;
}
	
