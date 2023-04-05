#include "SqString.cpp"		//包含顺序串的定义和基本运算函数
bool Find(SqString s,char x)
{	SqString s1;
	if (s.length==0)
		return false;
	else if (s.data[0]==x)			//a1=x
		return true;
	else
	{	s1=SubStr(s,2,s.length-1);	//s1="a2…an"
		return(Find(s1,x));
	}
}


int main()
{
	SqString s;
	StrAssign(s,"aabcad");
	printf("s: "); DispStr(s);
	printf("ans=%d\n",Find(s,'a'));
	printf("ans=%d\n",Find(s,'x'));
	
	
	return 0;
}
	
