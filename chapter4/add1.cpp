#include "sqstring.cpp"

void swap(char &x,char &y)
{
	char tmp=x;
	x=y; y=tmp;
}
void reverse(SqString &s)
{
	for (int i=0;i<s.length/2;i++)
		swap(s.data[i],s.data[s.length-i-1]);
				//data[i]Óëdata[L.length-i-1]½»»»
}

int main()
{
	SqString s;
	StrAssign(s,"abcdefgh");
	printf("s:");DispStr(s);

	reverse(s);

	printf("s:");DispStr(s);
	return 1;
}

