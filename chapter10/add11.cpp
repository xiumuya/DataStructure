#include "seqlist.cpp"			//˳�����������㷨

void CountSort(RecType A[],RecType B[],int n)
{	int i,j,count;
	for (i=0;i<n;i++) 
	{	count=0;
		for (j=0;j<n;j++)
			if (A[j].key<A[i].key)	//ͳ��С��A[i].key�ļ�¼����
				count++;
		B[count]=A[i];				//A[i]ӦΪ��count��ļ�¼
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


