#include "seqlist.cpp"			//顺序表基本运算算法

void CountSort(RecType A[],RecType B[],int n)
{	int i,j,count;
	for (i=0;i<n;i++) 
	{	count=0;
		for (j=0;j<n;j++)
			if (A[j].key<A[i].key)	//统计小于A[i].key的记录个数
				count++;
		B[count]=A[i];				//A[i]应为第count大的记录
	}
}

int main()
{
	RecType A[MAXL],B[MAXL];
	int n=6;
	int a[]={3,8,7,6,5,4};

	CreateList(A,a,n);
	printf("A:"); DispList(A,n);
	
	CountSort(A,B,n);
	printf("B:"); DispList(B,n);

	return 1;
}


