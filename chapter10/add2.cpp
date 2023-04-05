#include "seqlist.cpp"			//顺序表基本运算算法

void BinInsertSort1(RecType R[],int n) //对R[0..n-1]按递减有序进行折半插入排序
{	int i,j,low,high,mid;
	RecType tmp;
	for (i=1;i<n;i++)
	{	if (R[i-1].key<R[i].key)
		{	tmp=R[i];					//将R[i]保存到tmp中
			low=0;high=i-1;
			while (low<=high)			//在R[low..high]中折半查找有序插入的位置
			{	mid=(low+high)/2;		//取中间位置
				if (tmp.key>R[mid].key)
					high=mid-1;		//插入点在左半区
				else
					low=mid+1;		//插入点在右半区
			}
			for (j=i-1;j>=high+1;j--)	//元素后移
				R[j+1]=R[j];
			R[high+1]=tmp;			//插入R[i]
		}
	}
}


int main()
{
	RecType R[MAXL];
	int n=10;
	int a[]={2,7,10,6,1,5,9,4,3,8};
	CreateList(R,a,n);
	printf("排序前R:"); DispList(R,n);

	BinInsertSort1(R,n);
	
	printf("排序后R:"); DispList(R,n);
	return 1;
}


