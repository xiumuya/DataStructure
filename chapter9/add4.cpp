#include "seqlist.cpp"   //顺序表基本运算算法

void Binsert(RecType R[],int &n,RecType x)
{	int low=0,high=n-1,mid,pos,i;
	bool find=false;
	while (low<=high && !find)	//二分查找
	{	mid=(low+high)/2;
		if (x.key<R[mid].key)
			high=mid-1;
		else if (x.key>R[mid].key)
			low=mid+1;
		else 
		{	i=mid;
			find=true;
		}
	}
	if (find)				//若找相同值的元素,则在该mid处插入元素
		pos=mid;
	else 					//若未找相同值的元素,则在该high+1处插入元素
		pos=high+1;
	for (i=n-1;i>=pos;i--)	//R[pos..n-1]均后移一位
		R[i+1]=R[i];
	R[pos]=x;				//插入元素x
	n++;					//元素个数增加1
}


int main()
{
	KeyType keys[]={1,3,5,7,9,11,13,15,17};
	int n=9;
	RecType R[MAXL];
	CreateList(R,keys,n);
	printf("R:"); DispList(R,n);
	KeyType k;
	RecType x;
	while (true)
	{
		printf("k(输入-1结束):"); scanf("%d",&k);
		if (k==-1) break;
		x.key=k;
		Binsert(R,n,x);
		printf("R:"); DispList(R,n);
	}

	return 1;
}