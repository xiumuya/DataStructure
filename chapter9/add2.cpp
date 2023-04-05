#include "seqlist.cpp"   //顺序表基本运算算法

void swap(RecType &x,RecType &y)
{
	RecType tmp=x;
	x=y; y=tmp;
}

int SeqSearch2(RecType R[],int n,KeyType k)
{	int i=0;
	while (i<n && R[i].key!=k)
		i++;
	if (i<n)				//找到了关键字为k的元素R[i]
	{
		if (i>0)			//i>0时R[i]前移一位
		{
			swap(R[i], R[i-1]);
			return i;		//返回R[i]新位置的逻辑序号
		}
		else return i+1;	//i=0时不能移动R[i]，返回1
	}
	return 0;
}

int main()
{
	KeyType keys[]={1,2,3,4,5,6,7,8,9};
	int n=9,i;
	RecType R[MAXL];
	CreateList(R,keys,n);
	printf("R:"); DispList(R,n);

	KeyType k;
	while (true)
	{
		printf("k(输入-1结束):"); scanf("%d",&k);
		if (k==-1) break;
		i=SeqSearch2(R,n,k);
		if (i>0)
			printf("结果:R[%d]=%d\n",i,k);
		else
			printf("未找到%d\n",k);
		printf("R:"); DispList(R,n);
	}

	return 1;
}