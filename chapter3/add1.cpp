#include "sqstack.cpp"

void trans(int d,char b[])		//b���ڴ��dת���ɵĶ���������
{	char e;
	SqStack *st;
	InitStack(st);
	int i=0;
	while (d!=0)
	{	e='0'+d%2;			//��������ת��Ϊ�ַ�
		Push(st,e);
		d/=2;				//���������λ
	}
	while (!StackEmpty(st))
	{	Pop(st,e);			//��ջԪ��e
		b[i]=e;				//��e���������b��
		i++;
	}
	b[i]='\0';				//�����ַ���������־
	DestroyStack(st);		//����ջ
}

int main()
{
	int d=12;
	char b[MaxSize];
	trans(d,b);
	printf("%d=>%s\n",d,b);
	return 1;
}