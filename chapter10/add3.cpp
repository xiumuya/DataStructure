#include "seqlist.cpp"			//顺序表基本运算算法

void OeSort(RecType R[],int n)
{	int i;
	bool sorted=false;
	while (!sorted)
	{	sorted=true;
		for (i=0;i<n-1;i+=2)		//奇数扫描
			if (R[i].key>R[i+1].key)
			{	sorted=false;
				swap(R[i],R[i+1]);
			}
		for (i=1;i<n-1;i+=2)		//偶数扫描
			if (R[i].key>R[i+1].key)
			{	sorted=false;
				swap(R[i],R[i+1]);
			}
	}
}

int main()
{
	RecType R[MAXL];
	int n=10;
	int a[]={2,7,10,6,1,5,9,4,3,8};
	CreateList(R,a,n);
	printf("排序前R:"); DispList(R,n);

	OeSort(R,n);
	
	printf("排序后R:"); DispList(R,n);
	return 1;
}


