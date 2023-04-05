#include "sqlist.cpp"

void swap(ElemType &x,ElemType &y)
{
	ElemType tmp=x;
	x=y; y=tmp;
}
void fun(SqList *&L)
{	int i=0,j=L->length-1;
	while (i<j)
	{	while (L->data[i]<0) i++;
		while (L->data[j]>=0) j--;
		if (i<j)	//L->data[i]与L->data[j]交换
			swap(L->data[i], L->data[j]);
	}
}



int main()
{
	ElemType a[]={1,2,-2,1,0,2,-4,2,3,-1};
	ElemType x=2;
	SqList *L;
	CreateList(L,a,10);
	printf("L:");DispList(L);
	printf("删除值为%d的元素\n",x);
	fun(L);
	printf("L:");DispList(L);
	DestroyList(L);
	return 1;
}