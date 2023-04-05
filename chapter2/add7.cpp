#include "sqlist.cpp"
void swap(ElemType &x,ElemType &y)
{
	ElemType tmp=x;
	x=y; y=tmp;
}

void Union(SqList *A,SqList *B,SqList *&C)
{
	int i=0,j=0,k=0;			//k记录C中的元素个数
	C=(SqList *)malloc(sizeof(SqList));
	while (i<A->length && j<B->length)
	{	if (A->data[i]<B->data[j])
		{	C->data[k]=A->data[i];
			i++; k++;
		}
		else if (A->data[i]>B->data[j])
		{	C->data[k]=B->data[j];
			j++; k++;
		}
		else					//公共元素只复制一次
		{	C->data[k]=A->data[i];
			i++; j++; k++;
		}
	}
	while (i<A->length)			//若A未遍历完，将余下的所有元素复制到C中
	{	C->data[k]=A->data[i];
		i++; k++;
	}
	while (j<B->length)			//若B未遍历完，将余下的所有元素复制到C中
	{	C->data[k]=B->data[j];
		j++; k++;
	}
	C->length=k;				//修改顺序表的长度
}


int main()
{
	ElemType a[]={1,2,3,4};
	ElemType b[]={2,4,8,9,10};
	SqList *L1,*L2,*L3;
	CreateList(L1,a,4);
	printf("L1:");DispList(L1);

	CreateList(L2,b,5);
	printf("L2:");DispList(L2);

	Union(L1,L2,L3);
	printf("L3:");DispList(L3);

	DestroyList(L1);
	DestroyList(L2);
	DestroyList(L3);
	return 1;
}