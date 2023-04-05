#include <stdio.h>
#define MaxSize 10
int n,r;					//全局变量
void print(int a[])		//输出一个组合
{	int j;
	for (j=r-1;j>=0;j--)
		printf("%d ",a[j]);
	printf("\n");
}
void comb(int a[],int m,int k)
{	int i;
	for (i=m;i>=k;i--)
	{	a[k-1]=i;
		if (k>1)
			comb(a,i-1,k-1);
		else
			print(a);
	}
}
int main()
{	int a[MaxSize];
	printf("输入n,r(r<=n):");
	scanf("%d%d",&n,&r);
	printf("1..%d中%d个的组合结果如下:\n",n,r);
	comb(a,n,r);
	printf("\n");
	return 1;
}

