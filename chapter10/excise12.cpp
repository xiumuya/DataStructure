#include "seqlist.cpp"			//顺序表基本运算算法

void SelectSort1(RecType R[],int n,int m)
{	int i,j,k;
	for (i=0;i<m;i++)			//做第i趟排序
	{	k=i;
		for (j=i+1;j<n;j++)		//在当前无序区R[i..n-1]中选key最大的R[k]
			if (R[j].key>R[k].key)
				k=j;			//k记下目前找到的最大关键字所在的位置
		if (k!=i) 
			swap(R[i],R[k]);	//交换R[i]和R[k]
	}
}

int main()
{
	RecType R[MAXL];
	int n=10,m=4;
	int a[]={2,7,10,6,1,5,9,4,3,8};
	CreateList(R,a,n);
	printf("排序前R:"); DispList(R,n);

	SelectSort1(R,n,m);
	printf("前%d个元素递减排序\n",m);
	
	printf("排序后R:"); DispList(R,n);
	return 1;
}


