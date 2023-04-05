#include "sqstring.cpp"

int index(SqString s,SqString t)
{
	int i=0,j=0;
	while (i<s.length && j<t.length)
	{
		if (s.data[i]==t.data[j] || t.data[j]=='?')
		{
			i++;
			j++;
		}
		else
		{
			i=i-j+1;
			j=0;
		}
	}
	if (j>=t.length)
		return(i-t.length);
	else
		return(-1);
}


int main()
{
	SqString s,t;
	StrAssign(s,"there are");
	StrAssign(t,"?re");
	printf("s:");DispStr(s);
	printf("t:");DispStr(t);
	printf("½á¹û:%d\n",index(s,t));
	return 1;
}

