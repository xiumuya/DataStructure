#include "seqlist.cpp"			//顺序表基本运算算法

int partition(RecType R[],int s,int t)	//一趟划分
{	int i=s,j=t;
	RecType tmp=R[i];			//以R[i]为基准
	while (i<j)  				//从两端交替向中间扫描,直至i=j为止
	{	while (j>i && R[j].key>=tmp.key)
			j--;				//从右向左扫描,找一个小于tmp.key的R[j]
		R[i]=R[j];			//找到这样的R[j],放入R[i]处
		while (i<j && R[i].key<=tmp.key)
			i++;				//从左向右扫描,找一个大于tmp.key的R[i]
		R[j]=R[i];			//找到这样的R[i],放入R[j]处
	}
	R[i]=tmp;
	return i;
}

void QuickSort1(RecType R[],int n)		//对R[0..n-1]进行快速排序
{	int i,low,high,top=-1;
	struct 
	{	int low,high;
	} St[MAXL];
	RecType tmp;
	top++;								//进栈
	St[top].low=0; St[top].high=n-1;	
	while (top>-1)						//栈不空取出一个子序列进行划分
	{
		low=St[top].low;high=St[top].high;	//出栈
		top--;
		if (low<high)					//区间内至少存在两个元素的情况
		{
			i=partition(R,low,high);
			top++;
			St[top].low=low;St[top].high=i-1;
			top++;
			St[top].low=i+1;St[top].high=high;
		}
	}
}

int main()
{
	RecType R[MAXL];
	int n=10;
	int a[]={1,2,3,4,5,10,9,8,7,5};
	//int a[]={2,7,10,6,1,5,9,4,3,8};
	CreateList(R,a,n);
	printf("排序前R:"); DispList(R,n);

	QuickSort1(R,n);
	
	printf("排序后R:"); DispList(R,n);
	return 1;
}


