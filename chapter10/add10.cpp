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
bool IsHeap(RecType R[],int n)
{
	int i;
	if (n%2==0)		//n为偶数时,最后一个分支节点(编号为n/2)只有左孩子(编号为n)
	{	if (R[n/2].key<R[n].key)
			return false;
		for (i=n/2-1;i>=1;i--)	//判断所有双分支节点
			if (R[i].key<R[2*i].key || R[i].key<R[2*i+1].key)
				return false;
	}
	else			//n为奇数时,所有分支节点均为双分支节点
	{	for (i=n/2;i>=1;i--)	//判断所有双分支节点
			if (R[i].key<R[2*i].key || R[i].key<R[2*i+1].key)
				return false;
	}
	return true;
}


int main()
{
	RecType R[MAXL];
	int n,m=6;
	int a[]={3,8,7,6,5,4};

	BuildHeap(R,a,m,n);
	printf("输出堆R:"); DispList1(R,n);
	printf("n=%d\n",n);
	printf("结果:%d\n",IsHeap(R,n));

	return 1;
}


