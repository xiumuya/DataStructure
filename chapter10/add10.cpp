#include "seqlist.cpp"			//˳������������㷨

void HeapInsert(RecType R[],KeyType k,int &n)	//��k���뵽��R[1..n]��
{
	int i,j;
	n++;
	R[n].key=k;								//������ֵ��ԭ��β���ұ�����1
	i=n/2;j=n;
	while (i>0)								//����Ϊ��
	{
		if (R[i].key<R[j].key)
			swap(R[i],R[j]);				//����
		j=i;i=i/2;							//�����Ե����ϲ���
	}
}
void BuildHeap(RecType R[],KeyType A[],int m,int &n)	//������R[1..n]
{	int i;
	n=0;					//nΪ���нڵ��������ʼʱΪ0
	for (i=0;i<m;i++)		//mΪ�����Ԫ�ظ���
		HeapInsert(R,A[i],n);
}
bool IsHeap(RecType R[],int n)
{
	int i;
	if (n%2==0)		//nΪż��ʱ,���һ����֧�ڵ�(���Ϊn/2)ֻ������(���Ϊn)
	{	if (R[n/2].key<R[n].key)
			return false;
		for (i=n/2-1;i>=1;i--)	//�ж�����˫��֧�ڵ�
			if (R[i].key<R[2*i].key || R[i].key<R[2*i+1].key)
				return false;
	}
	else			//nΪ����ʱ,���з�֧�ڵ��Ϊ˫��֧�ڵ�
	{	for (i=n/2;i>=1;i--)	//�ж�����˫��֧�ڵ�
			if (R[i].key<R[2*i].key || R[i].key<R[2*i+1].key)
				return false;
	}
	return true;
}


int main()
{
	RecType R[MAXL];
	int n,m=6;
	int a[]={3,8,7,6,5,4};

	BuildHeap(R,a,m,n);
	printf("�����R:"); DispList1(R,n);
	printf("n=%d\n",n);
	printf("���:%d\n",IsHeap(R,n));

	return 1;
}

