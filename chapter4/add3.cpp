#include "sqstring.cpp"
void Trans(SqString &s,char c1,char c2)
{	int i;
	for (i=0;i<s.length;i++)
		if (s.data[i]==c1)
			s.data[i]=c2;
}

int main()
{
	SqString s;
	StrAssign(s,"abacd");
	printf("s:");DispStr(s);
	printf("a->x\n");
	Trans(s,'a','x');
	printf("s:");DispStr(s);

	return 1;
}

