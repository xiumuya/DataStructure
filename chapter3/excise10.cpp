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
								//遇到'('、'['或'{',则将其进栈
			Push(ls,exp[i]);
		if (exp[i]==')')		//遇到')',若栈顶是'(',则继续处理,否则以不配对返回
		{
			if (GetTop(ls,e))
			{
				if (e=='(') Pop(ls,e);
				else flag=false;
			}
			else flag=false;
		}
		if (exp[i]==']')		//遇到']',若栈顶是'[',则继续处理,否则以不配对返回
		{
			if (GetTop(ls,e))
			{
				if (e=='[') Pop(ls,e);
				else flag=false;
			}
			else flag=false;
		}
		if (exp[i]=='}')		//遇到'}',若栈顶是'{',则继续处理,否则以不配对返回
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
	if (!StackEmpty(ls)) flag=false;		//若栈不空,则不配对
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