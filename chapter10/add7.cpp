#include "seqlist.cpp"			//˳�����������㷨

void HeapInsert(RecType R[],KeyType k,int &n)	//��k���뵽��R[1..n]��
{
	int i,j;
	n++;
	R[n].key=k;								//������ֵ��ԭ��β���ұ���1
	i=n/2;j=n;
	while (i>0)								//����Ϊ��
	{
		if (R[i].key<R[j].key)
			swap(R[i],R[j]);				//����
		j=i;i=i/2;							//�����Ե����ϲ���
	}
}

int main()
{
	RecType R[MAXL];
	int n=5;
	int a[]={0,8,7,6,5,4};
	CreateList1(R,a,n);
	printf("����ǰR:"); DispList1(R,n);
	
	KeyType k=10;
	HeapInsert(R,k,n);
	
	printf("�����R:"); DispList1(R,n);
	return 1;
}


