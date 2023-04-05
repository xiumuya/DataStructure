#include "SqStack.cpp"			//����˳��ջ�Ķ��弰���㺯��
bool Findk(SqStack *st,int k,ElemType &e)
{	int i=0;
	bool flag=false;
	ElemType x;
	SqStack *tmpst;			//������ʱջ
	InitStack(tmpst);			//��ʼ����ʱջ
	while (!StackEmpty(st))		//��ʱջtmpst�а���stջ�е���תԪ��
	{	i++;
		Pop(st,x);
		if (i==k)
		{	e=x;
			flag=true;
		}
		Push(tmpst,x);
	}
	while (!StackEmpty(tmpst))	//�ָ�stջ��ԭ��������
	{	Pop(tmpst,x);
		Push(st,x);
	}
	DestroyStack(tmpst);
	return flag;
}

int main()
{
	ElemType e;
	SqStack *st;
	InitStack(st);
	Push(st,'a');
	Push(st,'b');
	Push(st,'c');
	Push(st,'d');
	Push(st,'e');
	if (Findk(st,4,e))
		printf("e:%c\n",e);
	else
		printf("No Found\n");
	DestroyStack(st);
	return 1;
}