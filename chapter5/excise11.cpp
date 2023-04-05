#include "sqstring.cpp"		//˳�򴮵Ļ��������㷨
int findpat(SqString s,SqString t)
{
	int i=0,j=0,k,start;
	while (i<s.length && j<t.length)
	{
		if (t.data[j]=='*')
		{
			j++;				//����* 
			k=findpat(SubStr(s,i+1,s.length-i),SubStr(t,j+1,t.length-j));
			if (k>-1)			//�ҵ��� 
				return start;
		}
		else if (s.data[i]==t.data[j])
		{
			i++;
			j++;
		}
		else
		{
			i=i-j+1;
			start=i;
			j=0;
		}
	}
	if (j>=t.length)
		return start;
	else
		return -1;
}		
int main()
{
	SqString s,t;
	StrAssign(s,"abcdefg");
	printf("s:"); DispStr(s);
	StrAssign(t,"b*");
	printf("t:"); DispStr(t);

	printf("���:%d\n",findpat(s,t));

	return 1;
}
	
