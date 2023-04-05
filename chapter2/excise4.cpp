#include "sqlist.cpp"

void fun(SqList *&L,ElemType x,ElemType y)
{	int i,k=0;
	for (i=0;i<L->length;i++)
		if (!(L->data[i]>=x && L->data[i]<=y))
		{	L->data[k]=L->data[i];
			k++;
		}
	L->length=k;
}


int main()
{
	ElemType a[]={1,2,2,1,0,2,4,2,3,1};
	ElemType x=2;
	SqList *L;
	CreateList(L,a,10);
	printf("L:");DispList(L);
	printf("删除值为%d的元素\n",x);
	fun(L,2,3);
	printf("L:");DispList(L);
	DestroyList(L);
	return 1;
}