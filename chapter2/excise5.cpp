#include "sqlist.cpp"

void Insert(SqList *&L,ElemType x)
{	int i=0,j;
	while (i<L->length && L->data[i]<x) i++;
	for (j=L->length-1;j>=i;j--)
		L->data[j+1]=L->data[j];
	L->data[i]=x;
	L->length++;
}


int main()
{
	ElemType a[]={1,2,3,6,9,20};
	ElemType x=30;
	SqList *L;
	CreateList(L,a,6);
	printf("L:");DispList(L);
	Insert(L,x);
	printf("L:");DispList(L);
	DestroyList(L);
	return 1;
}