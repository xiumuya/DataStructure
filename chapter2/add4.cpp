#include "sqlist.cpp"
void swap(ElemType &x,ElemType &y)
{
	ElemType tmp=x;
	x=y; y=tmp;
}
bool Rearrangement(SqList *&L,int k1,int k2)
{
	int i=0,j=L->length-1;
	if (k1>k2)					//参数错误返回假
		return false;
	while (i<j)					//将所有小于等于k1的元素前移
	{	while (L->data[i]<=k1) i++;
		while (L->data[j]>k1) j--;
		if (i<j)
		{	swap(L->data[i],L->data[j]);
			i++;
			j--;
		}
	}
	j=L->length-1;
	while (i<j)					//将所有大于等于k2的元素后移
	{	while (L->data[i]<k2) i++;
		while (L->data[j]>=k2) j--;
		if (i<j)
		{	swap(L->data[i],L->data[j]);
			i++;
			j--;
		}
	}	
	return true;			//操作成功返回真
}


int main()
{
	ElemType a[]={6,4,10,7,9,2,20,1,3,30};
	SqList *L;
	CreateList(L,a,10);
	printf("L:");DispList(L);
	Rearrangement(L,5,8);
	printf("L:");DispList(L);
	DestroyList(L);
	return 1;
}