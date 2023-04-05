#include "sqstring.cpp"

SqString MaxComStr(SqString s,SqString t)
{	SqString str;			//str用于存放最长公共子串
	int maxidx=0,maxlen=0,i,j,k,len;
	i=0;					//i作为扫描s的指针
	while (i<s.length)
	{	j=0;				//j作为扫描t的指针
		while (j<t.length)
		{	if (s.data[i]==t.data[j]) 
			{	len=1;		//找一个公共子串,其在s中的位置为i,长度为len
				for (k=1;i+k<s.length && j+k<t.length 
						&& s.data[i+k]==t.data[j+k];k++)
					len++;
				if (len>maxlen)	//将较大长度者赋给idx与len
				{	maxidx=i;
					maxlen=len;
				}
				j+=len;		//继续扫描t中第j+len字符之后的字符
			}
			else j++;
		}
		i++;					//继续扫描s中第i字符之后的字符
	}
	for (i=0;i<maxlen;i++)
		str.data[i]=s.data[maxidx+i];
	str.length=maxlen;
	return(str);				//返回最长公共子串
}


int main()
{
	SqString s,t,str;
	StrAssign(s,"aababcbcdefg");
	StrAssign(t,"ababcf");
	printf("s:");DispStr(s);
	printf("t:");DispStr(t);

	str=MaxComStr(s,t);

	printf("str:");DispStr(str);
	return 1;
}

