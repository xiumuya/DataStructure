#include <stdio.h>
int maxSubSum(int a[],int n)
{	int i,j,k;
	int maxSum=a[0],thisSum; 
	for (i=0;i<n;i++)				//����ѭ��������е�����������
	{	for (j=i;j<n;j++)
		{	thisSum=0;
			for (k=i;k<=j;k++)
				thisSum+=a[k];
			if (thisSum>maxSum)	//ͨ���Ƚ����������������֮��
				maxSum=thisSum;
		}
	}
	return maxSum;
}

int main()
{
	int a[]={-6,2,4,-7,5,3,2,-1,6,-9,10,-2};
	int n=sizeof(a)/sizeof(a[0]);
	printf("���=%d\n",maxSubSum(a,n));

	return 1;
}
	
