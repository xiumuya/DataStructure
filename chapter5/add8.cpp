#include <stdio.h>
#define MaxSize 10
int n,r;					//ȫ�ֱ���
void print(int a[])		//���һ�����
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
	printf("����n,r(r<=n):");
	scanf("%d%d",&n,&r);
	printf("1..%d��%d������Ͻ������:\n",n,r);
	comb(a,n,r);
	printf("\n");
	return 1;
}

