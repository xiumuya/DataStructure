#include "sqstring.cpp"

void maxsubstr(SqString s,SqString &t)
{
	int maxi=0,maxlen=0,len,i,j,k;
	i=0;
	while (i<s.length)				//���±�Ϊi���ַ���ʼ
	{
		j=i+1;
		while (j<s.length)
		{
			if (s.data[i]==s.data[j]) //��һ���Ӵ�,����ʼ�±�Ϊi,����Ϊlen
			{
				len=1;
				for(k=1;s.data[i+k]==s.data[j+k];k++)
					len++;
				if (len>maxlen)		//���ϴ󳤶��߸���maxi��maxlen
				{
					maxi=i;
					maxlen=len;
				}
				j+=len;
			}
			else j++;
		}
		i++;						//����ɨ���i�ַ�֮����ַ�
	}
	t.length=maxlen;				//����ظ��Ӵ�����t
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

