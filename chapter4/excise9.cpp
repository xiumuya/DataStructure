#include "sqstring.cpp"

int lastposition(SqString s,SqString t)
{
	int i,j,k;
	if (s.length-t.length<0)
		return -1;
	for (i=s.length-t.length;i>=0;i--)
	{
		for (j=i,k=0;j<s.length && k<t.length && s.data[j]==t.data[k];j++,k++);
		if (k==t.length)
			return i;
	}
	return -1;
}



int main()
{
	SqString s,t;
	StrAssign(s,"aababcabcdabcde");
	StrAssign(t,"abc");
	printf("s:");DispStr(s);
	printf("t:");DispStr(t);
	printf("½á¹û:%d\n",lastposition(s,t));
	return 1;
}

