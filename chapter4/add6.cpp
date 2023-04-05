#include "sqstring.cpp"

int substrcount(SqString s,SqString t)
{	int i=0,j,k,count=0;
	for (i=0;s.data[i];i++)
	{	for (j=i,k=0;j<s.length && k<t.length && 
			(s.data[j]==t.data[k]);j++,k++);
		if (k>=t.length)
			count++;
	}
	return(count);
}


int main()
{
	SqString s,t;
	StrAssign(s,"aababcabcdabcde");
	StrAssign(t,"abc");
	printf("s:");DispStr(s);
	printf("t:");DispStr(t);

	printf("½á¹û£º%d\n",substrcount(s,t));

	return 1;
}

