#include "sqstring.cpp"

bool Equal(SqString s,SqString t)
{	int i=0;
	bool flag=true;
	if (s.length!=t.length)
		return false;
	else
	{	while (i<s.length && flag)
		{	if (s.data[i]!=t.data[i])
				flag=false;
			i++;
		}
		return flag;
	}
}


int main()
{
	SqString s,t;
	StrAssign(s,"abcd");
	StrAssign(t,"accd");
	printf("s:");DispStr(s);
	printf("t:");DispStr(t);

	printf("%d\n",Equal(s,t));

	return 1;
}

