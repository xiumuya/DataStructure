#include "sqstring.cpp"
int PartPos(SqString s,SqString t,int index)	//S为主串,t为子串
{	int i,j,k;
	int n=s.length;
	int m=t.length;
	for (i=index;i<=n-m;i++)
	{	for (j=0,k=i;j<m && t.data[j]==s.data[k];k++,j++);
		if (j==m)
			return(i);
	}
	return(-1);
}


int main()
{
	SqString s,t;
	StrAssign(s,"abcabcdabcd");
	StrAssign(t,"abc");
	printf("s:");DispStr(s);
	printf("t:");DispStr(t);

	printf("%d\n",PartPos(s,t,4));

	return 1;
}

