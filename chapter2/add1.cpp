#include "sqlist.cpp"
void swap(ElemType &x,ElemType &y)
{
	ElemType tmp=x;
	x=y; y=tmp;
}
void reverse(SqList *&L)
{	int i;
	for (i=0;i<L->length/2;i++)		//交换一半的元素
		swap(L->data[i],L->data[L->length-i-1]);
}

int main()
{	ElemType a[]={1,2,3,4,5,6,7,8,9,10};
	SqList *L;
	CreateList(L,a,10);
	printf("L:");DispList(L);
	reverse(L);
	printf("L:");DispList(L);
	DestroyList(L);
	return 1;
}