#include "SqQueue.cpp"			//����˳��ӵ����Ͷ�������㺯��
ElemType Last(SqQueue *qu)
{	ElemType x;
	int i,count=(qu->rear-qu->front+MaxSize)%MaxSize;
	for (i=1;i<=count;i++)
	{	deQueue(qu,x);		//����Ԫ��x
		enQueue(qu,x);		//��Ԫ��x����
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
	printf("��βԪ��:%c\n",Last(qu));
	DestroyQueue(qu);

	return 0;
}
	
