#include "sqlist.cpp"
void swap(ElemType &x,ElemType &y)
{
	ElemType tmp=x;
	x=y; y=tmp;
}
void move(SqList *&L)
{
	int i=-1,j=0,k=L->length;
	while (j<k)
	{
		if (L->data[j]==0)
		{	i++;
			swap(L->data[i],L->data[j]);
			j++;
		}
		else if (L->data[j]==2)
		{
			k--;
			swap(L->data[k],L->data[j]);
		}
		else j++;
	}
}

int main()
{
	ElemType a[]={1,2,0,2,1,1,0,1,2,0};
	SqList *L;
	CreateList(L,a,10);
	printf("L:");DispList(L);
	move(L);
	printf("L:");DispList(L);
	DestroyList(L);
	return 1;
}