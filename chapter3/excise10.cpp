#include "listack.cpp"

bool Match(char exp[],int n)
{
	LinkStNode *ls;
	InitStack(ls);
	int i=0;
	ElemType e;
	bool flag=true;
	while (i<n && flag)
	{	if (exp[i]=='(' || exp[i]=='[' || exp[i]=='{')
								//����'('��'['��'{',�����ջ
			Push(ls,exp[i]);
		if (exp[i]==')')		//����')',��ջ����'(',���������,�����Բ���Է���
		{
			if (GetTop(ls,e))
			{
				if (e=='(') Pop(ls,e);
				else flag=false;
			}
			else flag=false;
		}
		if (exp[i]==']')		//����']',��ջ����'[',���������,�����Բ���Է���
		{
			if (GetTop(ls,e))
			{
				if (e=='[') Pop(ls,e);
				else flag=false;
			}
			else flag=false;
		}
		if (exp[i]=='}')		//����'}',��ջ����'{',���������,�����Բ���Է���
		{
			if (GetTop(ls,e))
			{
				if (e=='{') Pop(ls,e);
				else flag=false;
			}
			else flag=false;
		}
		i++;
	}
	if (!StackEmpty(ls)) flag=false;		//��ջ����,�����
	DestroyStack(ls);
	return flag;
}


int main()
{
	char exp1[]="([])";
	printf("%s:%d\n",exp1,Match(exp1,4));
	char exp2[]="([)]";
	printf("%s:%d\n",exp2,Match(exp2,4));
	char exp3[]="({})]";
	printf("%s:%d\n",exp3,Match(exp3,5));
	return 1;
}