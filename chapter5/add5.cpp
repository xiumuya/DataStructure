#include <stdio.h>
#define M 10
#define N 10
int fun(int n,int m)
{	if (n>=0 && m==0 || n>=0 && m==n)
		return 1;
	else
	{	if (n>m && n>=0 && m>=0)
			return(fun(n-1,m)+fun(n-1,m-1));
		else
		{	printf("n,m值不正确\n");
			return(-1);
		}
	}
}
int fun1(int n,int m)
{	int a[M][N]={0},i,j;
	for (i=0;i<=n;i++)
	{	a[i][0]=1;
		a[i][i]=1;
	}
	for (j=1;j<=m;j++)
		for (i=j+1;i<=n;i++)
			a[i][j]=a[i-1][j]+a[i-1][j-1];
	return a[n][m];
}
int main()
{
	int n=5,m=3; 
	printf("递归算法结果:  %d\n",fun(n,m));
	printf("非递归算法结果:%d\n",fun1(n,m));
	return 1;
}
	
