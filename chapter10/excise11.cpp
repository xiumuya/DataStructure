#include "seqlist.cpp"			//顺序表基本运算算法

void DBubbleSort(RecType R[],int n)	//对R[0..n-1]按递增序进行双向冒泡排序
{	int i=0,j;
	bool exchange=true;			//exchange标识本趟是否进行了元素交换
	while (exchange) 
	{	exchange=false;
		for (j=n-i-1;j>i;j--)
			if (R[j].key<R[j-1].key)	//由后向前冒泡小元素
			{	exchange=true;
				swap(R[j],R[j-1]);		//R[j]和R[j-1]交换
			}
		for (j=i;j<n-i-1;j++)
			if (R[j].key>R[j+1].key)  	//由前向后冒泡大元素
			{	exchange=true;
				swap(R[j],R[j+1]);		//R[j]和R[j+1]交换
			}
		if (!exchange) return;
		i++;
	}
}
int main()
{
	RecType R[MAXL];
	int n=10;
	int a[]={2,7,10,6,1,5,9,4,3,8};
	CreateList(R,a,n);
	printf("排序前R:"); DispList(R,n);
	DBubbleSort(R,n);
	printf("排序后R:"); DispList(R,n);
	return 1;
}


