#include <stdio.h>
#define MAXN 100
int Add(int A[],int B[],int C[])
{	int i=0,j=0,k=0,sum;
	while (A[i]!=-1 && B[j]!=-1)
	{	if (A[i]==B[j])				//按列优先比较
		{	if (A[i+1]==B[j+1])		//比较列号
			{	sum=A[i+2]+B[j+2];
				if (sum!=0)			//和不为零时
				{	C[k]=A[i];C[k+1]=A[i+1];C[k+2]=sum;
					k=k+3;
				}
				i=i+3;
				j=j+3;	
			}
			else if (A[i+1]<B[j+1]) 
			{	C[k]=A[i];C[k+1]=A[i+1];C[k+2]=A[i+2];
				k=k+3;i=i+3;
			}
			else						//A[i+1]>B[j+1]
			{	C[k]=B[j];C[k+1]=B[j+1];C[k+2]=B[j+2];
				k=k+3;j=j+3;
			}
		}
		else if (A[i]<B[j])
		{	C[k]=A[i];C[k+1]=A[i+1];C[k+2]=A[i+2];
			k=k+3;i=i+3;
		}
		else							//A[i]>B[j]
		{	C[k]=B[j];C[k+1]=B[j+1];C[k+2]=B[j+2];
			k=k+3;j=j+3;
		}
	}
	if (A[i]==-1 && B[j]!=-1)
	{	C[k]=B[j];C[k+1]=B[j+1];C[k+2]=B[j+2];
		k=k+3;j=j+3;
	}
	if (A[i]!=-1 && B[j]==-1)
	{	C[k]=A[i];C[k+1]=A[i+1];C[k+2]=A[i+2];
		k=k+3;i=i+3;
	}
	C[k]=-1;
	return k+1;
}


int main()
{
	int A[]={0,0,1,0,3,2,1,2,3,2,1,4,2,3,5,-1};
	int B[]={0,0,1,0,3,2,1,2,3,2,1,4,2,3,5,-1};
	int C[MAXN];
	int k=Add(A,B,C);
	printf("C的结果");
	for(int i=0;i<k;i++)
	{
		if(i%3==0) printf("\n");
		printf("%3d",C[i]);
	}
	return 1;
}
	
