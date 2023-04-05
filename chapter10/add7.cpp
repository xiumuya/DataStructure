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

int main()
{
	RecType R[MAXL];
	int n=5;
	int a[]={0,8,7,6,5,4};
	CreateList1(R,a,n);
	printf("插入前R:"); DispList1(R,n);
	
	KeyType k=10;
	HeapInsert(R,k,n);
	
	printf("插入后R:"); DispList1(R,n);
	return 1;
}


