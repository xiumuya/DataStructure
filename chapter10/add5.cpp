#include "seqlist.cpp"			//顺序表基本运算算法
#define MaxSize 100

int partition(RecType R[],int s,int t)	//一趟划分
{	int i=s,j=t;
	RecType tmp=R[i];			//以R[i]为基准
	while (i<j)  				//从两端交替向中间扫描,直至i=j为止
	{	while (j>i && R[j].key>=tmp.key)
			j--;				//从右向左扫描,找一个小于tmp.key的R[j]
		R[i]=R[j];				//找到这样的R[j],放入R[i]处
		while (i<j && R[i].key<=tmp.key)
			i++;				//从左向右扫描,找一个大于tmp.key的R[i]
		R[j]=R[i];				//找到这样的R[i],放入R[j]处
	}
	R[i]=tmp;
	return i;
}

void QuickSort2(RecType R[],int n)	//对R[0..n-1]进行快速排序
{	int i,low,high;
	int front=-1,rear=-1;			//队首、队尾指针
	struct 
	{	int low;
		int high;
	} Qu[MaxSize];
	rear++;								//进队
	Qu[rear].low=0;Qu[rear].high=n-1;
	while (front!=rear)					//队不空取出一个子区间进行划分
	{	front=(front+1)%MaxSize;
		low=Qu[front].low;high=Qu[front].high;	//出队
		i=partition(R,low,high);
		rear=(rear+1)%MaxSize;
		Qu[rear].low=low;Qu[rear].high=i-1;//左区间进队
		rear=(rear+1)%MaxSize;
		Qu[rear].low=i+1;Qu[rear].high=high;//右区间进队
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

	QuickSort2(R,n);
	
	printf("排序后R:"); DispList(R,n);
	return 1;
}


