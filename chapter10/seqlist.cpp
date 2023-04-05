//顺序表基本运算算法
#include "seqlist.h"
void CreateList(RecType R[],KeyType keys[],int n)	//创建顺序表
{
	for (int i=0;i<n;i++)
		R[i].key=keys[i];
}
void DispList(RecType R[],int n)	//输出顺序表
{
	for (int i=0;i<n;i++)
		printf("%d ",R[i].key);
	printf("\n");
}
void swap(RecType &x,RecType &y)
{
	RecType tmp;
	tmp=x;
	x=y; y=tmp;
}
//----------------------------------------------------------
//----以下运算针对堆排序的程序
void CreateList1(RecType R[],KeyType keys[],int n)	//创建顺序表
{
	for (int i=0;i<=n;i++)
		R[i].key=keys[i];
}
void DispList1(RecType R[],int n)	//输出顺序表
{
	for (int i=1;i<=n;i++)
		printf("%d ",R[i].key);
	printf("\n");
}