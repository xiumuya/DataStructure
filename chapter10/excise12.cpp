#include "seqlist.cpp"			//˳�����������㷨

void SelectSort1(RecType R[],int n,int m)
{	int i,j,k;
	for (i=0;i<m;i++)			//����i������
	{	k=i;
		for (j=i+1;j<n;j++)		//�ڵ�ǰ������R[i..n-1]��ѡkey����R[k]
			if (R[j].key>R[k].key)
				k=j;			//k����Ŀǰ�ҵ������ؼ������ڵ�λ��
		if (k!=i) 
			swap(R[i],R[k]);	//����R[i]��R[k]
	}
}

int main()
{
	RecType R[MAXL];
	int n=10,m=4;
	int a[]={2,7,10,6,1,5,9,4,3,8};
	CreateList(R,a,n);
	printf("����ǰR:"); DispList(R,n);

	SelectSort1(R,n,m);
	printf("ǰ%d��Ԫ�صݼ�����\n",m);
	
	printf("�����R:"); DispList(R,n);
	return 1;
}


