#include "sqstack.cpp"
#include "sqqueue.cpp"

void Reverse(SqQueue *&qu)
{
	ElemType e;
	SqStack *st;
	InitStack(st);
	while (!QueueEmpty(qu))		//�Ӳ���ʱ,���Ӳ���ջ
	{
		deQueue(qu,e);
		Push(st,e);
	}
	InitQueue(qu);				//���г�ʼ��
	while (!StackEmpty(st))		//ջ����ʱ,��ջ����Ԫ�����
	{
		Pop(st,e);
		enQueue(qu,e);
	}
	DestroyStack(st);
}

int main()
{
	ElemType e;
	SqQueue *qu;
	InitQueue(qu);
	enQueue(qu,'a');
	enQueue(qu,'b');
	enQueue(qu,'c');
	enQueue(qu,'d');
	enQueue(qu,'e');
	Reverse(qu);
	while(!QueueEmpty(qu))
	{
		deQueue(qu,e);
		printf("%c ",e);
	}
	DestroyQueue(qu);
	return 1;
}