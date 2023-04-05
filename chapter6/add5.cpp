#include <stdio.h>
#define MAXN 10
void func(int A[MAXN*MAXN],int B[MAXN][MAXN],int n)
{	int i,j,k,m,g,gs;
	m=0;
	for (k=1;k<=2*n-1;k++)		//对于每条对角线循环一次
	{	if (k<n)
			gs=k;			//gs为第k条斜线上的元素个数
		else
			gs=2*n-k;
		for (g=1;g<=gs;g++)
		{	if (k%2==1)		//k为奇数的情况,从下向上方递增
			{	i=gs-g;
				j=g-1;
			}
			else				//k为偶数的情况,从上向下方递增
			{	i=g-1;
				j=gs-g;
			}
			if (k>n)			//考虑第n+1到2n-1的斜线
			{	i=i+n-gs;
				j=j+n-gs;
			}
			B[i][j]=A[m];m++;
		}
	}
}

int main()
{
	//int a[MAXN*MAXN]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	int a[MAXN*MAXN]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24};
	int b[MAXN][MAXN];
	int n=5;
	func(a,b,n);
	printf("B:\n");
	for (int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			printf("%3d",b[i][j]);
		printf("\n");
	}

	return 1;
}
	
