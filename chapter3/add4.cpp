#include "SqStack.cpp"			//����˳��ջ�Ķ��弰���㺯��
bool isSerial(char str[],int n)
{	int i,j;
	char A[MaxSize],e;
	SqStack *st;				//����һ��˳��ջ
	InitStack(st);
	for (i=0;i<n;i++)
		A[i]='a'+i;				//��abcde��������A��
	i=0;j=0;
	while (i<n)
	{
		Push(st,A[i]);
		printf("  Ԫ��%c��ջ\n",A[i]);
		i++;	
		while (!StackEmpty(st) && (GetTop(st,e) && e==str[j]))
		{	Pop(st,e);
			printf("  Ԫ��%c��ջ\n",e);
			j++;
		}
	}
	bool flag=StackEmpty(st);
	DestroyStack(st);
	return flag;
}
void Disp(char str[],int n)			//���str
{	int i;
	for (i=0;i<n;i++)
		printf("%c",str[i]);
}
int main()
{	int n=5;
	char str[]="acbed";
	Disp(str,n); printf("�Ĳ�������:\n");
	if (isSerial(str,n))
	{	Disp(str,n);
		printf("�Ǻ��ʵĳ�ջ����\n");
	}
	else
	{	Disp(str,n);
		printf("���Ǻ��ʵĳ�ջ����\n");
	}
	return 1;
}
