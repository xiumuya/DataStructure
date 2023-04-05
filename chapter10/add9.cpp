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
void BuildHeap(RecType R[],KeyType A[],int m,int &n)	//������R[1..n]
{	int i;
	n=0;					//nΪ���нڵ��������ʼʱΪ0
	for (i=0;i<m;i++)		//mΪ�����Ԫ�ظ���
		HeapInsert(R,A[i],n);
}

void sift(RecType R[],int low,int high)
{	int i=low,j=2*i;						//R[j]��R[i]������
	RecType tmp=R[i];
	while (j<=high)
	{	if (j<high && R[j].key<R[j+1].key) 	//���Һ��ӽϴ�,��jָ���Һ���
			j++;
		if (tmp.key<R[j].key) 				//�����ڵ�С������ӵĹؼ���
		{	R[i]=R[j];					//��R[j]������˫�׽ڵ�λ����
			i=j;							//�޸�i��jֵ,�Ա��������ɸѡ
			j=2*i;
		}
		else break;					//�����ڵ���ڵ�������ӹؼ���,ɸѡ����
	}
	R[i]=tmp;								//��ɸѡ�ڵ��������λ����
}

void HeapDelete(RecType R[],int &n)	//��R[1]��R[1..n]�Ķ���ɾ��
{
	swap(R[1],R[n]);
	n--;
	sift(R,1,n);		//���á��̡̳���ɸѡ�㷨
}

int main()
{
	RecType R[MAXL];
	int n,m=6;
	int a[]={3,8,7,6,5,4};

	BuildHeap(R,a,m,n);
	printf("�����R:"); DispList1(R,n);
	HeapDelete(R,n);
	printf("ɾ��һ��\n");
	
	printf("�����R:"); DispList1(R,n);

	return 1;
}


