#include "seqlist.cpp"			//顺序表基本运算算法

KeyType QuickSelect(RecType R[],int s,int t,int k)	//在R[s..t]序列中找第k小的元素
{	int i=s,j=t;
	RecType tmp;
	if (s<t) 					//区间内至少存在2个元素的情况
	{	tmp=R[s];				//用区间的第1个记录作为基准
		while (i!=j)			//从区间两端交替向中间扫描,直至i=j为止
		{	while (j>i && R[j].key>=tmp.key) 
				j--;			//从右向左扫描,找第1个关键字小于tmp的R[j]
			R[i]=R[j];			//将R[j]前移到R[i]的位置
			while (i<j && R[i].key<=tmp.key) 
				i++;			//从左向右扫描,找第1个关键字大于tmp的R[i]
			R[j]=R[i];			//将R[i]后移到R[j]的位置
		}
		R[i]=tmp;
		if (k-1==i) return R[i].key;
		else if (k-1<i) return QuickSelect(R,s,i-1,k);	//在左区间中递归查找
		else return QuickSelect(R,i+1,t,k);				//在右区间中递归查找
	}
	else if (s==t && s==k-1)	//区间内只有一个元素且为R[k-1]
		return R[k-1].key;
	else
		return -1;				//k错误返回特殊值-1
}

int main()
{
	RecType R[MAXL];
	int n=10;
	int a[]={2,7,10,6,1,5,9,4,3,8};
	CreateList(R,a,n);
	printf("排序前R:"); DispList(R,n);

	int k=20;
	printf("第%d小的元素关键字:%d\n",k,QuickSelect(R,0,n-1,k));
	return 1;
}


