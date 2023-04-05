#include "SqQueue2.cpp"					//����˳��ӵ����Ͷ�������㺯��
bool deQueue1(SqQueue *&q,ElemType &e)	//�Ӷ�ͷ�����㷨
{	if (q->front==q->rear)				//�ӿ������
		return false;
	q->front=(q->front+1)%MaxSize;		//�޸Ķ�ͷָ��
	e=q->data[q->front];
	return true;
}
bool enQueue1(SqQueue *&q,ElemType e)	//�Ӷ�ͷ�����㷨
{  	if ((q->rear+1)%MaxSize==q->front)	//����
		return false;
   	q->data[q->front]=e;				//eԪ�ؽ���
   	q->front=(q->front-1+MaxSize)%MaxSize;//�޸Ķ�ͷָ��
   	return true;
}
bool enQueue2(SqQueue *&q,ElemType e)	//�Ӷ�β�����㷨
{	if ((q->rear+1)%MaxSize==q->front)	//���������
		return false;
	q->rear=(q->rear+1)%MaxSize;		//�޸Ķ�βָ��
	q->data[q->rear]=e;				//eԪ�ؽ���
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
			enQueue2(qu,a[i]);	//�Ӷ�β����
		else
			enQueue1(qu,a[i]);	//�Ӷ�ͷ����
	}
	while (!QueueEmpty(qu))
	{	deQueue1(qu,e);		//�Ӷ�ͷ����
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
	
