#include "sqstring.cpp"

#include "SqStack.cpp"	//����˳��ջ�Ķ���ͻ������㺯��
bool symm(SqString s)
{
	int i=0; char e,x;
	bool flag=true;
	SqStack *st;
	InitStack(st);
	while (i<s.length)		//��'@'֮ǰ���ַ���ջ
	{
		e=s.data[i];
		if (e!='@')
			Push(st,e);
		else
			break;
		i++;
	}
	i++;					//����@�ַ�
	while (i<s.length &&flag)
	{
		e=s.data[i];
		if (!Pop(st,x)) flag=false;
		if (e!=x) flag=false;
		i++;
	}
	if (!StackEmpty(st)) flag=false;
	DestroyStack(st);
	return flag;
}

int main()
{
	SqString s;
	StrAssign(s,"a+b@b+a");
	printf("s:");DispStr(s);
	printf("���:%d\n",symm(s));
	return 1;
}

