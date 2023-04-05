#include "sqstack.cpp"

void DispStack(SqStack *st)
{	ElemType x;
	SqStack *tmpst;			//������ʱջ
	InitStack(tmpst);			//��ʼ����ʱջ
	while (!StackEmpty(st))		//��ʱջtmpst�а���stջ�е���תԪ��
	{	Pop(st,x);
		printf("%c ",x);
		Push(tmpst,x);
	}
	printf("\n");
	while (!StackEmpty(tmpst))	//�ָ�stջ��ԭ��������
	{	Pop(tmpst,x);
		Push(st,x);
	}
	DestroyStack(tmpst);
}


int main()
{
	SqStack *st;
	InitStack(st);
	Push(st,'a');
	Push(st,'b');
	Push(st,'c');
	Push(st,'d');
	Push(st,'e');
	DispStack(st);
	DestroyStack(st);
	return 1;
}