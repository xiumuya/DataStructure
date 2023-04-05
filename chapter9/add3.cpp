#include "seqlist.cpp"   //顺序表基本运算算法

int BinSearch1(RecType R[],int low,int high,KeyType k)
{	//初始调用时:low=0,high=n-1
	int mid;
	if (low<=high) 
	{	mid=(low+high)/2;
		if (R[mid].key<k)
			return BinSearch1(R,mid+1,high,k);
		else if (R[mid].key>k)
			return BinSearch1(R,low,mid-1,k);
		else				//R[mid].key=k
			return mid+1;
	}
	else return 0;
}

int main()
{
	KeyType keys[]={1,2,3,4,5,6,7,8,9};
	int n=9,i;
	RecType R[MAXL];
	CreateList(R,keys,n);
	printf("R:"); DispList(R,n);

	KeyType k;
	while (true)
	{
		printf("k(输入-1结束):"); scanf("%d",&k);
		if (k==-1) break;
		i=BinSearch1(R,0,n-1,k);
		if (i>0)
			printf("结果:R[%d]=%d\n",i,k);
		else
			printf("未找到%d\n",k);
		printf("R:"); DispList(R,n);
	}

	return 1;
}