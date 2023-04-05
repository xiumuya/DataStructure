#include "seqlist.cpp"			//顺序表基本运算算法

void HeapInsert(RecType R[],KeyType k,int &n)	//将k插入到堆R[1..n]中
{
	int i,j;
	n++;
	R[n].key=k;								//增加新值到原表尾部且表长加1
	i=n/2;j=n;
	while (i>0)								//调整为堆
	{
		if (R[i].key<R[j].key)
			swap(R[i],R[j]);				//交换
		j=i;i=i/2;							//继续自底向上查找
	}
}
void BuildHeap(RecType R[],KeyType A[],int m,int &n)	//建立堆R[1..n]
{	int i;
	n=0;					//n为堆中节点个数，初始时为0
	for (i=0;i<m;i++)		//m为插入的元素个数
		HeapInsert(R,A[i],n);
}

int main()
{
	RecType R[MAXL];
	int n,m=6;
	int a[]={3,8,7,6,5,4};

	BuildHeap(R,a,m,n);
	
	printf("输出堆R:"); DispList1(R,n);

	return 1;
}


