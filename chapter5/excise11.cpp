#include "sqstring.cpp"		//顺序串的基本运算算法
int findpat(SqString s,SqString t)
{
	int i=0,j=0,k,start;
	while (i<s.length && j<t.length)
	{
		if (t.data[j]=='*')
		{
			j++;				//跳过* 
			k=findpat(SubStr(s,i+1,s.length-i),SubStr(t,j+1,t.length-j));
			if (k>-1)			//找到了 
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

	printf("结果:%d\n",findpat(s,t));

	return 1;
}
	
