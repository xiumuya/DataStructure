#include "seqlist.cpp"			//˳�����������㷨

void BinInsertSort1(RecType R[],int n) //��R[0..n-1]���ݼ���������۰��������
{	int i,j,low,high,mid;
	RecType tmp;
	for (i=1;i<n;i++)
	{	if (R[i-1].key<R[i].key)
		{	tmp=R[i];					//��R[i]���浽tmp��
			low=0;high=i-1;
			while (low<=high)			//��R[low..high]���۰������������λ��
			{	mid=(low+high)/2;		//ȡ�м�λ��
				if (tmp.key>R[mid].key)
					high=mid-1;		//������������
				else
					low=mid+1;		//��������Ұ���
			}
			for (j=i-1;j>=high+1;j--)	//Ԫ�غ���
				R[j+1]=R[j];
			R[high+1]=tmp;			//����R[i]
		}
	}
}


int main()
{
	RecType R[MAXL];
	int n=10;
	int a[]={2,7,10,6,1,5,9,4,3,8};
	CreateList(R,a,n);
	printf("����ǰR:"); DispList(R,n);

	BinInsertSort1(R,n);
	
	printf("�����R:"); DispList(R,n);
	return 1;
}


