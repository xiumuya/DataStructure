#include "sqstring.cpp"

void DelAll1(SqString &s,char c)
{	int k=0,i=0;					//k��¼ֵ����c���ַ�����
	while (i<s.length)
	{	if (s.data[i]==c)
			k++;
		else
			s.data[i-k]=s.data[i];	//��ǰ�ַ�ǰ��k��λ��
		i++;
	}
	s.length-= k;					//��s�ĳ��ȵݼ�
}

int main()
{
	SqString s;
	StrAssign(s,"abacd");
	printf("s:");DispStr(s);
	printf("ɾ������a\n");
	DelAll1(s,'a'); 
	printf("s:");DispStr(s);

	return 1;
}

