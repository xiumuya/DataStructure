#include <stdio.h>
#define MAXN 10
void func(int A[MAXN*MAXN],int B[MAXN][MAXN],int n)
{	int i,j,k,m,g,gs;
	m=0;
	for (k=1;k<=2*n-1;k++)		//����ÿ���Խ���ѭ��һ��
	{	if (k<n)
			gs=k;			//gsΪ��k��б���ϵ�Ԫ�ظ���
		else
			gs=2*n-k;
		for (g=1;g<=gs;g++)
		{	if (k%2==1)		//kΪ���������,�������Ϸ�����
			{	i=gs-g;
				j=g-1;
			}
			else				//kΪż�������,�������·�����
			{	i=g-1;
				j=gs-g;
			}
			if (k>n)			//���ǵ�n+1��2n-1��б��
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
	
