#include "sqstring.cpp"

void DelAll1(SqString &s,char c)
{	int k=0,i=0;					//k记录值等于c的字符个数
	while (i<s.length)
	{	if (s.data[i]==c)
			k++;
		else
			s.data[i-k]=s.data[i];	//当前字符前移k个位置
		i++;
	}
	s.length-= k;					//串s的长度递减
}

int main()
{
	SqString s;
	StrAssign(s,"abacd");
	printf("s:");DispStr(s);
	printf("删除所有a\n");
	DelAll1(s,'a'); 
	printf("s:");DispStr(s);

	return 1;
}

