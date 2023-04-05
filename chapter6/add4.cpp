#include <stdio.h>
int maxSubSum(int a[],int n)
{	int i,j,k;
	int maxSum=a[0],thisSum; 
	for (i=0;i<n;i++)				//两重循环穷举所有的连续子序列
	{	for (j=i;j<n;j++)
		{	thisSum=0;
			for (k=i;k<=j;k++)
				thisSum+=a[k];
			if (thisSum>maxSum)	//通过比较求最大连续子序列之和
				maxSum=thisSum;
		}
	}
	return maxSum;
}

int main()
{
	int a[]={-6,2,4,-7,5,3,2,-1,6,-9,10,-2};
	int n=sizeof(a)/sizeof(a[0]);
	printf("结果=%d\n",maxSubSum(a,n));

	return 1;
}
	
