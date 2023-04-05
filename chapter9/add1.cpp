#include "seqlist.cpp"   //顺序表基本运算算法

int SeqSearch1(RecType R[],int n,KeyType k,int i)
//初始调用时i=0
{	if (i>=n)
		return 0;
	else if (R[i].key==k)
		return i+1;
	else
		return(SeqSearch1(R,n,k,i+1));
}


int main()
{
	KeyType keys[]={1,2,3,4,5,6,7,8,9};
	int n=9,i;
	RecType R[MAXL];
	CreateList(R,keys,n);
	printf("R:"); DispList(R,n);

	KeyType k=9;
	i=SeqSearch1(R,n,k,0);
	if (i>0)
		printf("结果:R[%d]=%d\n",i,k);
	else
		printf("未找到%d\n",k);

	return 1;
}