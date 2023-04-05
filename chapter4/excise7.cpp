#include "sqstring.cpp"

SqString CommChar(SqString s1,SqString s2)
{
	SqString s3;
	int i,j,k=0;
	for (i=0;i<s1.length;i++)
	{	for (j=0;j<s2.length;j++)
			if (s2.data[j]==s1.data[i])
				break;
		if (j<s2.length)	//s1.data[i]ÊÇ¹«¹²×Ö·û
		{	s3.data[k]=s1.data[i];
			k++;
		}
	}
	s3.length=k;
	return s3;
}


int main()
{
	SqString s1,s2,s3;
	StrAssign(s1,"abcdefg");
	StrAssign(s2,"ad123");
	printf("s1:");DispStr(s1);
	printf("s2:");DispStr(s2);
	s3=CommChar(s1,s2);
	printf("s3:");DispStr(s3);
	return 1;
}

