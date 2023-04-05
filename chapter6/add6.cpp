#include <stdio.h>
#define MAXN 10


int findk(int i,int j)		//由i、j求压缩存储中的k下标
{	if (i>=j)
		return (i*(i+1)/2+j);
	else
		return (j*(j+1)/2+i);
}
void Mult(int a[],int b[],int c[MAXN][MAXN],int n)
{	int i,j,k,k1,k2;
	int s;
	for (i=0;i<n;i++)
		for (j=0;j<n;j++)
		{	s=0;
			for (k=0;k<n;k++)
			{	k1=findk(i,k);
				k2=findk(k,j);
				s+=a[k1]*b[k2];
			}
			c[i][j]=s;
		}
}

void compression(int A[][MAXN],int n,int B[])		//对称矩阵A压缩存储到B中
{	int i,j,k=0;
	for(i=0;i<n;i++)
		for(j=0;j<=i;j++)
			B[k++]=A[i][j];
}

void Mult1(int A[][MAXN],int B[][MAXN],int C[][MAXN],int n)	//验证
{
	int i,j,k,s;
	for(int i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			s=0;
			for(k=0;k<n;k++)
				s+=A[i][k]*B[k][j];
		}
}
	 
int main()
{
	int n=4;
	int A[MAXN][MAXN]={
		{1,1,1,1},
		{1,1,1,1},
		{1,1,1,1},
		{1,1,1,1}};
	int B[MAXN][MAXN]={
		{1,1,1,1},
		{1,1,1,1},
		{1,1,1,1},
		{1,1,1,1}};
	int a[MAXN*(MAXN+1)/2],b[MAXN*(MAXN+1)/2];
	compression(A,n,a);
	compression(B,n,b);
	int C[MAXN][MAXN];
	Mult(a,b,C,n);
	printf("C的结果:\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			printf("%3d",C[i][j]);
		printf("\n");
	}
	
	Mult1(A,B,C,n);
	printf("C的验证结果:\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			printf("%3d",C[i][j]);
		printf("\n");
	}

	return 1;
}
	
