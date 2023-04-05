#include <stdio.h>
#include <malloc.h>
#define MaxSize 100
typedef char ElemType;
typedef struct
{	ElemType data[MaxSize];
	int rear;						//��βָ��
	int count;					//������Ԫ�ظ���
} QuType;							//��������
void InitQu(QuType *&q)				//���г�ʼ������
{	q=(QuType *)malloc(sizeof(QuType));
	q->rear=0;
	q->count=0;
}
bool EnQu(QuType *&q,ElemType x)		//��������
{	if (q->count==MaxSize)			//���������
		return false;
	else
	{	q->rear=(q->rear+1)%MaxSize;
		q->data[q->rear]=x;
		q->count++;
		return true;
	}
}
bool DeQu(QuType *&q,ElemType &x)		//��������
{	int front;					//�ֲ�����
	if (q->count==0)				//�ӿ������
		return false;
	else
	{	front=(q->rear-q->count+MaxSize)%MaxSize; 
		front=(front+1)%MaxSize;	//��ͷλ�ý�1
		x=q->data[front];
		q->count--;
		return true;
	}
}
bool QuEmpty(QuType *q)		//�п�����
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
	printf("����Ԫ��: ");
	while(!QuEmpty(qu))
	{
		DeQu(qu,e);
		printf("%c ",e);
	}
	
	return 0;
}
	
