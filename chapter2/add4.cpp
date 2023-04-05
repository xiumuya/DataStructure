#include "sqlist.cpp"
void swap(ElemType &x,ElemType &y)
{
	ElemType tmp=x;
	x=y; y=tmp;
}
bool Rearrangement(SqList *&L,int k1,int k2)
{
	int i=0,j=L->length-1;
	if (k1>k2)					//�������󷵻ؼ�
		return false;
	while (i<j)					//������С�ڵ���k1��Ԫ��ǰ��
	{	while (L->data[i]<=k1) i++;
		while (L->data[j]>k1) j--;
		if (i<j)
		{	swap(L->data[i],L->data[j]);
			i++;
			j--;
		}
	}
	j=L->length-1;
	while (i<j)					//�����д��ڵ���k2��Ԫ�غ���
	{	while (L->data[i]<k2) i++;
		while (L->data[j]>=k2) j--;
		if (i<j)
		{	swap(L->data[i],L->data[j]);
			i++;
			j--;
		}
	}	
	return true;			//�����ɹ�������
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