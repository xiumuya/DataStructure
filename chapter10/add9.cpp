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

void sift(RecType R[],int low,int high)
{	int i=low,j=2*i;						//R[j]是R[i]的左孩子
	RecType tmp=R[i];
	while (j<=high)
	{	if (j<high && R[j].key<R[j+1].key) 	//若右孩子较大,把j指向右孩子
			j++;
		if (tmp.key<R[j].key) 				//若根节点小于最大孩子的关键字
		{	R[i]=R[j];					//将R[j]调整到双亲节点位置上
			i=j;							//修改i和j值,以便继续向下筛选
			j=2*i;
		}
		else break;					//若根节点大于等于最大孩子关键字,筛选结束
	}
	R[i]=tmp;								//被筛选节点放入最终位置上
}

void HeapDelete(RecType R[],int &n)	//将R[1]从R[1..n]的堆中删除
{
	swap(R[1],R[n]);
	n--;
	sift(R,1,n);		//调用《教程》的筛选算法
}

int main()
{
	RecType R[MAXL];
	int n,m=6;
	int a[]={3,8,7,6,5,4};

	BuildHeap(R,a,m,n);
	printf("输出堆R:"); DispList1(R,n);
	HeapDelete(R,n);
	printf("删除一次\n");
	
	printf("输出堆R:"); DispList1(R,n);

	return 1;
}


