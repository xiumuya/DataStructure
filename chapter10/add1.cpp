#include "seqlist.cpp"			//顺序表基本运算算法

typedef struct
{	KeyType key;	//关键字
	int no;			//序号
} IndexType;		//索引类型

void CreateIndex(RecType R[],IndexType idx[],int n) //建立R的索引idx
{
	IndexType tmp;
	int i,j;
	for (i=0;i<n;i++)			//建立idx
	{
		idx[i].key=R[i].key;
		idx[i].no=i;
	}
	for (i=1;i<n;i++)			//对idx按key排序
	{	if (idx[i].key<idx[i-1].key) 
		{	tmp=idx[i];
			j=i-1; 
			do
			{	idx[j+1]=idx[j]; 
				j--;
			}  while  (j>=0 && idx[j].key>tmp.key);
			idx[j+1]=tmp;
		} 
	}
}


int main()
{
	RecType R[MAXL];
	IndexType idx[MAXL];
	int n=10;
	int a[]={2,7,10,6,1,5,9,4,3,8};
	CreateList(R,a,n);
	printf("数据:\n");
	printf("位  置:");
	for (int i=0;i<n;i++)
		printf("%3d",i);
	printf("\n");
	printf("关键字:");
	for (i=0;i<n;i++)
		printf("%3d",R[i].key);
	printf("\n");
	CreateIndex(R,idx,n);
	printf("索引:\n");
	printf("关键字:");
	for (i=0;i<n;i++)
		printf("%3d",idx[i].key);
	printf("\n");
	printf("位  置:");
	for (i=0;i<n;i++)
		printf("%3d",idx[i].no);
	printf("\n");

	return 1;
}


