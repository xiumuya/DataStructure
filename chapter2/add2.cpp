#include "sqlist.cpp"
void swap(ElemType &x,ElemType &y)
{
	ElemType tmp=x;
	x=y; y=tmp;
}
void reverse(SqList *&L,int m,int n)	//将R[m..n]逆置
{
	int i;
	for (i=0;i<(n-m+1)/2;i++)
		swap(L->data[m+i],L->data[n-i]); //将data[m+i]与data[n-i]进行交换
}

bool creverse(SqList *&L,int p)		//将L中元素循环左移p个位置
{	if (p<=0 || p>=L->length)
		return false;
	else
	{	reverse(L,0,p-1);
		reverse(L,p,L->length-1);
		reverse(L,0,L->length-1);
		return true;
	}
}

int main()
{
	ElemType a[]={1,2,3,4,5,6,7,8,9,10};
	SqList *L;
	CreateList(L,a,10);
	printf("L:");DispList(L);
	creverse(L,9);
	printf("L:");DispList(L);
	DestroyList(L);
	return 1;
}