#include <stdio.h>
#include <malloc.h>
#define MaxSize 100
typedef char ElemType;
typedef struct 
{	ElemType data[MaxSize];
	int front,rear;	//��ͷ�Ͷ�βָ��
	int tag;			//Ϊ0��ʾ�ӿ��ܿ�,Ϊ1ʱ��ʾ�ӿ�����
} QueueType;

void InitQueue1(QueueType &qu)		//��ʼ�������㷨
{	qu.front=qu.rear=0;
	qu.tag=0;						//Ϊ0��ʾ�ӿտ���Ϊ��
}
bool QueueEmpty1(QueueType qu)		//�жӿ��㷨
{
	return(qu.front==qu.rear && qu.tag==0);
}
bool QueueFull1(QueueType qu)		//�ж����㷨
{
	return(qu.tag==1 && qu.front==qu.rear);
}
bool EnQueue1(QueueType &qu,ElemType x)//�����㷨
{	if (QueueFull1(qu)==1)			//����
		return false;
	qu.rear=(qu.rear+1)%MaxSize;
	qu.data[qu.rear]=x;
	qu.tag=1;						//������һ��Ԫ��,������
	return true;
}
bool DeQueue1(QueueType &qu,ElemType &x)//�����㷨
{	if (QueueEmpty1(qu)==1)			//�ӿ�
		return false;
	qu.front=(qu.front+1)%MaxSize;
	x=qu.data[qu.front];
	qu.tag=0;						//����һ��Ԫ��,���ܿ�
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
	printf("����Ԫ��: ");
	while(!QueueEmpty1(qu))
	{
		DeQueue1(qu,e);
		printf("%c ",e);
	}
	
	return 0;
}
	
