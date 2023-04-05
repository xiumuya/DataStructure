#include <stdio.h>
#define MAXM 10
#define MAXN 10
void disparr(int arr[][MAXN],int m,int n)
{
	int i,j;
	for (i=0;i<m;i++)
	{
		for (j=0;j<n;j++)
			printf("%4d",arr[i][j]);
		printf("\n");
	}
}

void sum(int a[][MAXN],int b[][MAXN],int m,int n)
{
	int i,j;
	b[0][0]=a[0][0];
	for (i=1;i<m;i++)		//求b的第0列
		b[i][0]=b[i-1][0]+a[i][0];
	for (j=1;j<n;j++)		//求b的第0行
		b[0][j]=b[0][j-1]+a[0][j];
	for (i=1;i<m;i++)		//求b[i][j]
		for (j=1;j<n;j++)
			b[i][j]=a[i][j]+b[i-1][j]+b[i][j-1]-b[i-1][j-1];
}
int submat(int b[][MAXN],int i,int j,int s,int t)
{
	int sum;
	if (i==0 && j==0)
		return b[s][t];
	else
		sum=b[s][t]-b[s][j-1]-b[i-1][t]+b[i-1][j-1];
	return sum;
}
int main()
{
	int m=4,n=4;
	int a[MAXM][MAXN]={
		{1,1,1,1},
		{1,1,1,1},
		{1,1,1,1},
		{1,1,1,1}};
	int b[MAXM][MAXN];
	sum(a,b,m,n);
	disparr(b,m,n);
	printf("结果:%d\n",submat(b,1,1,3,3));

	return 1;
}
	