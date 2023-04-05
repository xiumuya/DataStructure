#include "seqlist.cpp"   //顺序表基本运算算法

int BinSearch1(RecType R[],int n,KeyType k)
{
	int low=0,high=n-1,mid;
	int cnum=1;				//成功查找需要1次比较
	while (low<=high)
	{
		mid=(low+high)/2;
		if (R[mid].key==k)
			return cnum;
		else if (k<R[mid].key)
			high=mid-1;
		else
			low=mid+1;
		cnum++;
	}
	cnum--;					//不成功查找需要减1
	return cnum;
}

int main()
{
	KeyType keys[]={12,18,24,35,47,50,62,83,90,115,134};
	KeyType k;
	int n=11;
	RecType R[MAXL];
	CreateList(R,keys,n);
	printf("R:"); DispList(R,n);
	printf("k:"); scanf("%d",&k);
	printf("比较次数:%d\n",BinSearch1(R,n,k));
	return 1;
}