#include "sqstring.cpp"
typedef struct
{	char c;				//字符
	int num;			//字符计数
} CType;
int fun(SqString s,CType cnum[])
{
	int i,j,k=0;		//k记录cnum中的元素个数
	for (i=0;i<s.length;i++)
	{	if (k==0)		//cnum中没有元素时,将s.data[i]直接放到cnum中
		{	cnum[k].c=s.data[i];
			cnum[k].num=1;
			k++;
		}
		else			//cnum中存在元素时,查找是否有相同的字符
		{	for (j=0;j<k && s.data[i]!=cnum[j].c;j++);
			if (j>=k)	//s.data[i]不在cnum数组中
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
	printf("输入串:"); gets(str);
	StrAssign(s,str);
	printf("统计结果如下:\n");
	k=fun(s,cnum);
	for (i=0;i<k;i++)
		printf("  %c %d\n",cnum[i].c,cnum[i].num);
	return 1;
}
