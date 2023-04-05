#include "sqstring.cpp"		//顺序串的基本运算算法
SqString invert(SqString s)
{	SqString s1,s2;
	if (StrLength(s)>0)
	{	s1=invert(SubStr(s,2,StrLength(s)-1));
		s2=Concat(s1,SubStr(s,1,1));
	}
	else
		StrCopy(s2,s);
	return s2;
}

int main()
{
	SqString s,t;
	StrAssign(s,"abcdefg");
	printf("s:"); DispStr(s);
	t=invert(s);
	printf("t:"); DispStr(t);
	return 1;
}
	