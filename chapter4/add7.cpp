#include "sqstring.cpp"

SqString MaxComStr(SqString s,SqString t)
{	SqString str;			//str���ڴ��������Ӵ�
	int maxidx=0,maxlen=0,i,j,k,len;
	i=0;					//i��Ϊɨ��s��ָ��
	while (i<s.length)
	{	j=0;				//j��Ϊɨ��t��ָ��
		while (j<t.length)
		{	if (s.data[i]==t.data[j]) 
			{	len=1;		//��һ�������Ӵ�,����s�е�λ��Ϊi,����Ϊlen
				for (k=1;i+k<s.length && j+k<t.length 
						&& s.data[i+k]==t.data[j+k];k++)
					len++;
				if (len>maxlen)	//���ϴ󳤶��߸���idx��len
				{	maxidx=i;
					maxlen=len;
				}
				j+=len;		//����ɨ��t�е�j+len�ַ�֮����ַ�
			}
			else j++;
		}
		i++;					//����ɨ��s�е�i�ַ�֮����ַ�
	}
	for (i=0;i<maxlen;i++)
		str.data[i]=s.data[maxidx+i];
	str.length=maxlen;
	return(str);				//����������Ӵ�
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

