#include "sqlist.cpp"
void swap(ElemType &x,ElemType &y)
{
	ElemType tmp=x;
	x=y; y=tmp;
}

void Diffence(SqList *A,SqList *B,SqList *&C)
{
	int i=0,j=0,k=0;				//k��¼C�е�Ԫ�ظ���
	C=(SqList *)malloc(sizeof(SqList));
	while (i<A->length && j<B->length)
	{	if (A->data[i]<B->data[j])	//ֻ��A��С��Ԫ�ط���C��
		{	C->data[k]=A->data[i];
			i++; k++;
		}
		else if (A->data[i]>B->data[j])
			j++;
		else						//����Ԫ�ز��ܷ���C��
		{	i++;
			j++;
		}
	}
	while (i<A->length)				//��Aδ�����꣬�����µ�����Ԫ�ط���C��
	{	C->data[k]=A->data[i];
		i++; k++;
	}
	C->length=k;					//�޸ļ��ϳ���
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

	Diffence(L1,L2,L3);
	printf("L3:");DispList(L3);

	DestroyList(L1);
	DestroyList(L2);
	DestroyList(L3);
	return 1;
}