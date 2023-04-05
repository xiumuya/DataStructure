#include "SqQueue.cpp"			//����˳��ӵ����Ͷ�������㺯��
bool Delk(SqQueue *&qu,int k)
{	ElemType e;
	int i,count=(qu->rear-qu->front+MaxSize)%MaxSize;
	if (k<=0 || k>count)
		return false;
	for (i=1;i<=count;i++)
	{	deQueue(qu,e);		//����Ԫ��e
		if (i!=k)				//��k��Ԫ��ֻ������
			enQueue(qu,e);	//����Ԫ�س��Ӻ��ֽ���
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
	printf("���ӵ�%d��Ԫ��\n",k); 
	printf("����Ԫ��: ");
	while(!QueueEmpty(qu))
	{
		deQueue(qu,e);
		printf("%c ",e);
	}
	
	DestroyQueue(qu);
	
	return 0;
}
	
