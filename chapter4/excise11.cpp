#include "sqstring.cpp"

void maxsubstr(SqString s,SqString &t)
{
	int maxi=0,maxlen=0,len,i,j,k;
	i=0;
	while (i<s.length)				//从下标为i的字符开始
	{
		j=i+1;
		while (j<s.length)
		{
			if (s.data[i]==s.data[j]) //找一个子串,其起始下标为i,长度为len
			{
				len=1;
				for(k=1;s.data[i+k]==s.data[j+k];k++)
					len++;
				if (len>maxlen)		//将较大长度者赋给maxi与maxlen
				{
					maxi=i;
					maxlen=len;
				}
				j+=len;
			}
			else j++;
		}
		i++;						//继续扫描第i字符之后的字符
	}
	t.length=maxlen;				//将最长重复子串赋给t
	for (i=0;i<maxlen;i++)
		t.data[i]=s.data[maxi+i];
}


int main()
{
	SqString s,t;
	//StrAssign(s,"aababcabcdabcde");
	StrAssign(s,"aababcabcd");
	printf("s:"); DispStr(s);
	maxsubstr(s,t);
	printf("t:");DispStr(t);
	return 1;
}

