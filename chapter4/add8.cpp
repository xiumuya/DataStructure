#include "sqstring.cpp"
typedef struct
{	char c;				//�ַ�
	int num;			//�ַ�����
} CType;
int fun(SqString s,CType cnum[])
{
	int i,j,k=0;		//k��¼cnum�е�Ԫ�ظ���
	for (i=0;i<s.length;i++)
	{	if (k==0)		//cnum��û��Ԫ��ʱ,��s.data[i]ֱ�ӷŵ�cnum��
		{	cnum[k].c=s.data[i];
			cnum[k].num=1;
			k++;
		}
		else			//cnum�д���Ԫ��ʱ,�����Ƿ�����ͬ���ַ�
		{	for (j=0;j<k && s.data[i]!=cnum[j].c;j++);
			if (j>=k)	//s.data[i]����cnum������
			{	cnum[k].c=s.data[i];
				cnum[k].num=1;
				k++;
			}
			else cnum[j].num++;
		}
	}
	return k;
}
int main()
{
	int i,k;
	char str[MaxSize];
	SqString s;
	CType cnum[MaxSize];
	printf("���봮:"); gets(str);
	StrAssign(s,str);
	printf("ͳ�ƽ������:\n");
	k=fun(s,cnum);
	for (i=0;i<k;i++)
		printf("  %c %d\n",cnum[i].c,cnum[i].num);
	return 1;
}
